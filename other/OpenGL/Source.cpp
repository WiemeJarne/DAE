#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

void InitAndConfigGLFW();
void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);
unsigned int CreateVertexShader();
unsigned int CreateFragmentShader();
void CheckIfShaderCompiled(GLuint shader, std::string shaderType);
void CheckIfShaderProgramLinked(GLuint program);

//settings
const unsigned int windowWidth{ 800 };
const unsigned int windowHeight{ 600 };

//vertex shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
" gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";

//fragment shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
"}\0";

int main()
{
	//glfw: initialize and configure
	InitAndConfigGLFW();

	//glfw window creation
	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "LearnOpenGL", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	//glad: load all OpenGL function pointers
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	//build and compile the shader program

	//vertex shader
	unsigned int vertexShader{ CreateVertexShader() }; //creating vertex shader
	CheckIfShaderCompiled(vertexShader, "VERTEX"); //checking if vertex shader compilation was succesfull

	//fragment shader
	unsigned int fragmentShader{ CreateFragmentShader() }; //creating fragment shader
	CheckIfShaderCompiled(fragmentShader, "FRAGMENT"); //checking if fragment shader compilation was succesfull

	//attach and link shaders to the shader program
	unsigned int shaderProgram{ glCreateProgram() };
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	CheckIfShaderProgramLinked(shaderProgram); //check for linking errors

	//delete shader objects
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	//set up vertex date and buffer(s) and configure vertex attrubutes
	
	//array(s) with points to draw
	float vertices1[] = {
		-1.f, -1.f, 0.f,
		-0.875f, -0.75f, 0.f,
		-0.75f, -1.f, 0.f,
		-0.75f, -1.f, 0.f,
		-0.612f, -0.75f, 0.f,
		-0.5f, -1.f, 0.f
	};

	//OpenGL uses indices to decide what vertices to draw
	unsigned int indices[] = { 
	0, 1, 3, // first triangle
	1, 2, 3 // second triangle
	};

	unsigned int VAO{}, VBO{}, EBO{}; //VAO = vertex array object, VBO = vertex buffer objects, EBO = element buffer object
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	//bind the vertex array first
	glBindVertexArray(VAO);

	//then bind and set vertex buffer(s)
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//tell OpenGL how it should interpret the vertex date
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	//enable the vertex attribute
	glEnableVertexAttribArray(0);

	//render loop
	while (!glfwWindowShouldClose(window))
	{
		//input
		processInput(window);

		//rendering commands here
		glClearColor(0.2f, 0.3f, 0.3f, 1.f);
		glClear(GL_COLOR_BUFFER_BIT);

		//draw a triangle
		glUseProgram(shaderProgram); //activating shader program
		glBindVertexArray(VAO); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
		glDrawArrays(GL_TRIANGLES, 0, 6); //draws the triangle
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0); //draw using indices provided in the element buffer

		//swap buffers 
		glfwSwapBuffers(window);
		//check and call events
		glfwPollEvents();
	}

	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteProgram(shaderProgram);

	glfwTerminate();
	return 0;
}

void InitAndConfigGLFW()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
}

//glfw: whenever the window size changes(by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height) 
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

unsigned int CreateVertexShader()
{
	//creating vertex shader
	unsigned int vertexShader{ glCreateShader(GL_VERTEX_SHADER) };
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	return vertexShader;
}

unsigned int CreateFragmentShader()
{
	//creating fragment shader
	unsigned int fragmentShader{ glCreateShader(GL_FRAGMENT_SHADER) };
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	return fragmentShader;
}

void CheckIfShaderCompiled(GLuint shader, std::string shaderType)
{
	int success{};
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);

	if (!success)
	{
		char infoLog[512]{}; //storage container for error messages if there are any
		glGetShaderInfoLog(shader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << shaderType << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

void CheckIfShaderProgramLinked(GLuint program)
{
	int success{};
	glGetProgramiv(program, GL_LINK_STATUS, &success);

	if (!success)
	{
		char infoLog[512]{}; //storage container for error messages if there are any
		glGetProgramInfoLog(program, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
}