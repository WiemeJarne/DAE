#pragma once

class PostFilmGrain : public PostProcessingMaterial
{
public:
	PostFilmGrain();
	~PostFilmGrain() override = default;
	PostFilmGrain(const PostFilmGrain& other) = delete;
	PostFilmGrain(PostFilmGrain&& other) noexcept = delete;
	PostFilmGrain& operator=(const PostFilmGrain& other) = delete;
	PostFilmGrain& operator=(PostFilmGrain&& other) noexcept = delete;

protected:
	void Initialize(const GameContext& /*gameContext*/) override {}
};