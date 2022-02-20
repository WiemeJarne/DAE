//Maya ASCII 2022 scene
//Name: 1DAE2_RickAstley_Assignment1.000.ma
//Last modified: Fri, Feb 18, 2022 11:20:56 AM
//Codeset: 1252
requires maya "2022";
requires "stereoCamera" "10.0";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" -nodeType "aiSkyDomeLight"
		 -nodeType "aiStandardSurface" "mtoa" "4.2.1";
requires "stereoCamera" "10.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202102181415-29bfc1879c";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19042)";
fileInfo "UUID" "75D94FAB-4E76-F9AA-A139-92A7CAF010AA";
fileInfo "license" "education";
createNode transform -s -n "persp";
	rename -uid "CBB20537-40F8-A23F-4B21-26837A14FFF1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 28.185242391457656 170.64651067714283 -218.59341221513938 ;
	setAttr ".r" -type "double3" -36.338352729500549 534.99999999990825 0 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "6CB0EF23-4C47-136F-7BC7-2C89212700F0";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 211.346077626029;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".dgm" no;
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "45E02EF2-4F56-EF12-FDF5-2895A3A150BC";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 1000.1 0 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "30CC5B27-4562-DCB1-B432-9BB785A531E9";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "E954741A-49E3-D1E2-3A3A-34907A2CA684";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "1F5AE986-4B50-6B46-DB4F-279C57D4A5C7";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "83D0C7A7-414C-8094-4EDC-AA901C3893A1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 0 0 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "8F23D138-46DB-4DF0-85BB-A98A807A7331";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "Template";
	rename -uid "1BAE495E-4F3D-2238-9EA6-AAA3D2659F3F";
createNode transform -n "LIGHTS_Grp" -p "Template";
	rename -uid "2B0E0A47-4D01-81E4-401C-E8B09B3A3BC1";
createNode transform -n "Skydome_l" -p "LIGHTS_Grp";
	rename -uid "08A4BEBE-4B26-DA65-7E6A-299CFBE98066";
createNode aiSkyDomeLight -n "Skydome_lShape" -p "Skydome_l";
	rename -uid "649B4E4B-45D4-93CD-C362-65B07757CB3E";
	addAttr -ci true -h true -sn "aal" -ln "attributeAliasList" -dt "attributeAlias";
	setAttr -k off ".v";
	setAttr ".csh" no;
	setAttr ".rcsh" no;
	setAttr ".aal" -type "attributeAlias" {"exposure","aiExposure"} ;
createNode transform -n "groundplane_Geo" -p "Template";
	rename -uid "93A00281-460D-5DA0-1B1B-7B9C26CAACBF";
	setAttr ".s" -type "double3" 1 -0.32127547571129456 1 ;
createNode mesh -n "groundplane_GeoShape" -p "groundplane_Geo";
	rename -uid "628DBC8C-47D7-A44B-8145-C79ADF405DE8";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 12 ".uvst[0].uvsp[0:11]" -type "float2" 0 0 1 0 0 1 1 1 0
		 0 1 0 1 1 0 1 0 0 1 0 1 1 0 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".vt[0:7]"  -100 0 100 100 0 100 -100 0 -100 100 0 -100
		 -100 0 100 100 0 100 100 0 -100 -100 0 -100;
	setAttr -s 12 ".ed[0:11]"  0 1 0 0 2 0 1 3 0 2 3 0 0 4 0 1 5 0 4 5 0
		 3 6 0 5 6 0 2 7 0 7 6 0 4 7 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 6 8 -11 -12
		mu 0 4 8 9 10 11
		f 4 1 3 -3 -1
		mu 0 4 4 7 6 5
		f 4 0 5 -7 -5
		mu 0 4 0 1 9 8
		f 4 2 7 -9 -6
		mu 0 4 1 3 10 9
		f 4 -4 9 10 -8
		mu 0 4 3 2 11 10
		f 4 -2 4 11 -10
		mu 0 4 2 0 8 11;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube1";
	rename -uid "3531803C-46E4-7A61-900D-4A815C8187C3";
	setAttr ".t" -type "double3" -36.894325714333952 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 37.608044329193724 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" 37.608044329193724 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape1" -p "pCube1";
	rename -uid "46EFBE4E-4931-330B-472F-84B0A5B0979E";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 6 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "back";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[2]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottom";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "f[3]";
	setAttr ".gtag[2].gtagnm" -type "string" "front";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 1 "f[0]";
	setAttr ".gtag[3].gtagnm" -type "string" "left";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "f[5]";
	setAttr ".gtag[4].gtagnm" -type "string" "right";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "f[4]";
	setAttr ".gtag[5].gtagnm" -type "string" "top";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 1 "f[1]";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube2";
	rename -uid "CB37BD9E-405F-AAB0-1DF6-E58101146C0B";
	setAttr ".t" -type "double3" -21.894325714333952 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 22.608044329193724 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" 22.608044329193724 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape2" -p "pCube2";
	rename -uid "30D91678-44F5-9DFD-569D-0D8B8D3BD30F";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube3";
	rename -uid "203B7275-481C-92AB-0EE1-37B02564BCC0";
	setAttr ".t" -type "double3" -6.8943257143339522 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 7.6080443291937243 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" 7.6080443291937243 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape3" -p "pCube3";
	rename -uid "A0CC086E-4879-F508-68C7-BDA1778B03CC";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube4";
	rename -uid "D12C7CDC-4253-5910-C365-A5BE539AC7BA";
	setAttr ".t" -type "double3" 8.1056742856660478 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -7.3919556708062757 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" -7.3919556708062757 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape4" -p "pCube4";
	rename -uid "09D4D6E1-4CB5-FA0A-D02C-C7AF2E0336F2";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -1.2523316e-13 0 -0.37396088 
		-1.2523316e-13 0 -0.37396088 -1.2523316e-13 0 -0.37396088 -1.2523316e-13 0 -0.37396088 
		1.1723955e-13 0 19.485472 1.1723955e-13 0 19.485472 1.1723955e-13 0 19.485472 1.1723955e-13 
		0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube5";
	rename -uid "129C15EA-4809-15ED-8FD5-C78AAB30D269";
	setAttr ".t" -type "double3" 23.105674285666048 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -22.391955670806276 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" -22.391955670806276 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape5" -p "pCube5";
	rename -uid "C45857E2-4A5A-60FC-3CC4-A0A6D7B15ABA";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube6";
	rename -uid "4775C573-4D2C-AED3-08AA-799354792033";
	setAttr ".t" -type "double3" 38.105674285666048 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -37.391955670806276 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" -37.391955670806276 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape6" -p "pCube6";
	rename -uid "F46B55AE-4D8B-F4BA-E820-F99995E70C41";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -1.8651747e-13 0 -0.37396088 
		-2.1138646e-13 0 -0.37396088 -1.8651747e-13 0 -0.37396088 -2.1138646e-13 0 -0.37396088 
		-1.8651747e-13 0 19.485472 -2.1138646e-13 0 19.485472 -1.8651747e-13 0 19.485472 
		-2.1138646e-13 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube7";
	rename -uid "657E8A21-4682-9849-4C10-3398CD2A2386";
	setAttr ".t" -type "double3" -16.498036060935796 3.1381306088255889 44.749905666553346 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".r" -type "double3" 0 90 0 ;
	setAttr -av ".ry";
	setAttr ".rp" -type "double3" -5.0000000000000142 0 17.221029281616183 ;
	setAttr ".rpt" -type "double3" 22.211754675795582 0 -11.166104317383386 ;
	setAttr ".sp" -type "double3" -5.0000000000000142 0 17.221029281616183 ;
createNode mesh -n "pCubeShape7" -p "pCube7";
	rename -uid "2288E6A6-444B-AAA3-6A80-49B7D1AFF8E7";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -9.7699626e-15 6.2172489e-15 
		4.2632564e-14 -1.6549526 6.2172489e-15 4.2632564e-14 -9.7699626e-15 1.8873791e-15 
		4.2632564e-14 -1.6549526 1.8873791e-15 4.2632564e-14 -9.7699626e-15 6.2172489e-15 
		34.442062 -1.6549526 6.2172489e-15 34.442062 -9.7699626e-15 8.2156504e-15 34.442062 
		-1.6549526 8.2156504e-15 34.442062;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube8";
	rename -uid "22EACDFF-49DA-8D67-AC7B-35B37D5B4729";
	setAttr ".t" -type "double3" -16.498036060935796 3.1265503613649268 -8.250094333446647 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -58.000000000000036 0.011580247460662108 17.221029281616183 ;
	setAttr ".rpt" -type "double3" 75.211754675795589 0 41.833895682616621 ;
	setAttr ".sp" -type "double3" -58.000000000000036 0.011580247460662108 17.221029281616183 ;
createNode mesh -n "pCubeShape8" -p "pCube8";
	rename -uid "B4630CD7-417A-E5B0-A390-A1A357E9E334";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -8.7712498 -1.3322676e-15 
		4.2632564e-14 -10.426202 7.7715612e-16 4.2632564e-14 -8.7712498 -5.5511151e-15 4.2632564e-14 
		-10.426202 -4.4408921e-15 4.2632564e-14 -8.7712498 -1.2212453e-15 34.442062 -10.426202 
		-1.110223e-16 34.442062 -8.7712498 6.6613381e-16 34.442062 -10.426202 2.7755576e-15 
		34.442062;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube9";
	rename -uid "659C0C98-4AF5-D479-2513-7A9CF78B4192";
	setAttr ".t" -type "double3" -16.50731066675641 3.1265503613649273 -60.195169369213843 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -111 0.011580247460661219 17.221029281616183 ;
	setAttr ".rpt" -type "double3" 128.22102928161618 0 93.778970718383817 ;
	setAttr ".sp" -type "double3" -111 0.011580247460661219 17.221029281616207 ;
	setAttr ".spt" -type "double3" 0 0 -2.48689957516035e-14 ;
createNode mesh -n "pCubeShape9" -p "pCube9";
	rename -uid "E2FB9301-4CAD-A8B3-D63A-F9899384015A";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -17.5425 6.2172489e-15 4.2632564e-14 
		-19.197453 6.2172489e-15 4.2632564e-14 -17.5425 1.8873791e-15 4.2632564e-14 -19.197453 
		1.8873791e-15 4.2632564e-14 -17.5425 6.2172489e-15 34.442062 -19.197453 6.2172489e-15 
		34.442062 -17.5425 8.2156504e-15 34.442062 -19.197453 8.2156504e-15 34.442062;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube10";
	rename -uid "D25BAD2A-41C2-C184-BBD1-C19B89296F95";
	setAttr ".t" -type "double3" 38.014798668270934 6.1868701816246494 45.730914183769457 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -37.301080053411162 -3.0487395727990605 5.0739164470166997 ;
	setAttr ".sp" -type "double3" -37.301080053411162 -3.0487395727990605 5.0739164470166997 ;
createNode mesh -n "pCubeShape10" -p "pCube10";
	rename -uid "B80325F3-42F1-5A79-EDCC-26A0AAA89FCD";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 6 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "back";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[2]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottom";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "f[3]";
	setAttr ".gtag[2].gtagnm" -type "string" "front";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 1 "f[0]";
	setAttr ".gtag[3].gtagnm" -type "string" "left";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "f[5]";
	setAttr ".gtag[4].gtagnm" -type "string" "right";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "f[4]";
	setAttr ".gtag[5].gtagnm" -type "string" "top";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 1 "f[1]";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 1.584438 0 -1.2434498e-14 1.584438 0 -1.2434498e-14 1.584438 0 -1.2434498e-14 
		1.584438;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube11";
	rename -uid "91A943F8-48C2-AD80-BEA0-CDAFA5E525AE";
	setAttr ".t" -type "double3" 38.014798668270934 6.2383952411995223 -7.2690858162305432 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -37.301080053411162 -3.1002646323739333 58.0739164470167 ;
	setAttr ".sp" -type "double3" -37.301080053411162 -3.1002646323739333 58.0739164470167 ;
createNode mesh -n "pCubeShape11" -p "pCube11";
	rename -uid "03AB21D4-44D1-A4E4-C57D-E88FDB14BDCF";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 8.8662291 0 0 8.8662291 
		0 0 8.8662291 0 0 8.8662291 0 0 10.355687 0 0 10.355687 0 0 10.355687 0 0 10.355687;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube12";
	rename -uid "4E3F5D1C-4C4D-3AFB-E36A-BF84231E27AA";
	setAttr ".t" -type "double3" 38.014798668270934 6.2383952411995223 -60.269085816230543 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -37.301080053411162 -3.1002646323739333 111.0739164470167 ;
	setAttr ".sp" -type "double3" -37.301080053411162 -3.1002646323739333 111.0739164470167 ;
createNode mesh -n "pCubeShape12" -p "pCube12";
	rename -uid "14677DC6-496A-ACB9-AFEC-EDA05B6038E0";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  1.1990409e-13 2.6645353e-15 
		17.637478 1.1990409e-13 2.6645353e-15 17.637478 1.1990409e-13 3.5527137e-15 17.637478 
		1.1990409e-13 3.5527137e-15 17.637478 -2.220446e-15 -1.3322676e-15 19.126936 -3.1086245e-15 
		-1.3322676e-15 19.126936 -2.220446e-15 1.3322676e-15 19.126936 -3.1086245e-15 1.3322676e-15 
		19.126936;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube13";
	rename -uid "F9F03031-45F6-4AE2-98C1-62BC567E7C95";
	setAttr ".t" -type "double3" 23.014798668270934 6.1868701816246494 45.730914183769457 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -22.301080053411162 -3.0487395727990605 5.0739164470166997 ;
	setAttr ".sp" -type "double3" -22.301080053411162 -3.0487395727990605 5.0739164470166997 ;
createNode mesh -n "pCubeShape13" -p "pCube13";
	rename -uid "0DEC1191-40EF-5A43-1B6D-9E861F5E24D0";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 1.584438 0 -1.2434498e-14 1.584438 0 -1.2434498e-14 1.584438 0 -1.2434498e-14 
		1.584438;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube14";
	rename -uid "A7CCEC76-407C-7EED-A2EB-DF9EF47816E1";
	setAttr ".t" -type "double3" 23.014798668270934 6.2383952411995223 -7.2690858162305432 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -22.301080053411162 -3.1002646323739333 58.0739164470167 ;
	setAttr ".sp" -type "double3" -22.301080053411162 -3.1002646323739333 58.0739164470167 ;
createNode mesh -n "pCubeShape14" -p "pCube14";
	rename -uid "32943105-4234-A053-4ECD-B6804C44A966";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -9.9475983e-14 0 8.8662291 
		-9.9475983e-14 0 8.8662291 -9.9475983e-14 0 8.8662291 -9.9475983e-14 0 8.8662291 
		-9.9475983e-14 0 10.355687 -9.9475983e-14 0 10.355687 -9.9475983e-14 0 10.355687 
		-9.9475983e-14 0 10.355687;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube15";
	rename -uid "A7169C7E-419B-9FC2-26B5-D39E84BCD27B";
	setAttr ".t" -type "double3" 23.014798668270934 6.2383952411995223 -60.269085816230543 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -22.301080053411162 -3.1002646323739333 111.0739164470167 ;
	setAttr ".sp" -type "double3" -22.301080053411162 -3.1002646323739333 111.0739164470167 ;
createNode mesh -n "pCubeShape15" -p "pCube15";
	rename -uid "DE995AB3-47A2-4DD5-FD43-0C9ACD14FCB1";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -9.9475983e-14 -4.4408921e-15 
		17.637478 -9.9475983e-14 -4.4408921e-15 17.637478 -9.9475983e-14 -6.2172489e-15 17.637478 
		-9.9475983e-14 -6.2172489e-15 17.637478 -9.9475983e-14 -1.1990409e-14 19.126936 -9.9475983e-14 
		-1.1990409e-14 19.126936 -9.9475983e-14 -9.7699626e-15 19.126936 -9.9475983e-14 -9.7699626e-15 
		19.126936;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube16";
	rename -uid "85973F9C-4D32-2F13-66AB-009B2ADA6941";
	setAttr ".t" -type "double3" 8.0147986682709345 6.1868701816246494 45.730914183769457 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -7.3010800534111624 -3.0487395727990605 5.0739164470166997 ;
	setAttr ".sp" -type "double3" -7.3010800534111624 -3.0487395727990605 5.0739164470166997 ;
createNode mesh -n "pCubeShape16" -p "pCube16";
	rename -uid "A85B30D0-4F9C-A70A-C97F-26A5284F5533";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  6.2172489e-15 -1.2434498e-14 
		0.094980463 0 -1.2434498e-14 0.094980463 6.2172489e-15 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 1.584438 -3.5527137e-15 -1.2434498e-14 
		1.584438 0 -1.2434498e-14 1.584438 -3.5527137e-15 -1.2434498e-14 1.584438;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube17";
	rename -uid "208D3D2D-4790-C6EE-F3A8-368B0E4056D6";
	setAttr ".t" -type "double3" 8.0147986682709345 6.2383952411995223 -7.2690858162305432 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -7.3010800534111624 -3.1002646323739333 58.0739164470167 ;
	setAttr ".sp" -type "double3" -7.3010800534111624 -3.1002646323739333 58.0739164470167 ;
createNode mesh -n "pCubeShape17" -p "pCube17";
	rename -uid "99C05B7D-4886-3E58-56F4-98BC226E358E";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 8.8662291 0 0 8.8662291 
		0 0 8.8662291 0 0 8.8662291 0 0 10.355687 0 0 10.355687 0 0 10.355687 0 0 10.355687;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube18";
	rename -uid "F3B4DD35-4301-B0CE-4DD2-C3AEED8D7AD0";
	setAttr ".t" -type "double3" 8.0147986682709345 6.2383952411995223 -60.269085816230543 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -7.3010800534111624 -3.1002646323739333 111.0739164470167 ;
	setAttr ".sp" -type "double3" -7.3010800534111624 -3.1002646323739333 111.0739164470167 ;
createNode mesh -n "pCubeShape18" -p "pCube18";
	rename -uid "A76AE08D-40D0-2280-EA4D-2E937BD77A28";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -2.9753977e-14 2.6645353e-15 
		17.637478 -2.7533531e-14 2.6645353e-15 17.637478 -2.9753977e-14 3.5527137e-15 17.637478 
		-2.7533531e-14 3.5527137e-15 17.637478 -1.0214052e-13 -1.3322676e-15 19.126936 -1.0258461e-13 
		-1.3322676e-15 19.126936 -1.0214052e-13 1.3322676e-15 19.126936 -1.0258461e-13 1.3322676e-15 
		19.126936;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube19";
	rename -uid "04C273AF-44D1-7DB1-BC7B-AD967B53B6D2";
	setAttr ".t" -type "double3" -6.9852013317290655 6.1868701816246494 45.730914183769457 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 7.6989199465888376 -3.0487395727990605 5.0739164470166997 ;
	setAttr ".sp" -type "double3" 7.6989199465888376 -3.0487395727990605 5.0739164470166997 ;
createNode mesh -n "pCubeShape19" -p "pCube19";
	rename -uid "7C664693-4357-51E5-C707-E481DD2888C9";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 0.094980463 0 -1.2434498e-14 0.094980463 
		0 -1.2434498e-14 1.584438 0 -1.2434498e-14 1.584438 0 -1.2434498e-14 1.584438 0 -1.2434498e-14 
		1.584438;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube20";
	rename -uid "490C5DC4-4CDA-0A11-EBAD-4783C3969B46";
	setAttr ".t" -type "double3" -6.9852013317290655 6.2383952411995223 -7.2690858162305432 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 7.6989199465888376 -3.1002646323739333 58.0739164470167 ;
	setAttr ".sp" -type "double3" 7.6989199465888376 -3.1002646323739333 58.0739164470167 ;
createNode mesh -n "pCubeShape20" -p "pCube20";
	rename -uid "DB321F85-43C3-A81A-32C4-8BA03EFAF26C";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 8.8662291 0 0 8.8662291 
		0 0 8.8662291 0 0 8.8662291 0 0 10.355687 0 0 10.355687 0 0 10.355687 0 0 10.355687;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube21";
	rename -uid "55D27BF5-4863-55BF-66CC-92A669783BBE";
	setAttr ".t" -type "double3" -6.9852013317290655 6.2383952411995223 -60.269085816230543 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 7.6989199465888376 -3.1002646323739333 111.0739164470167 ;
	setAttr ".sp" -type "double3" 7.6989199465888376 -3.1002646323739333 111.0739164470167 ;
createNode mesh -n "pCubeShape21" -p "pCube21";
	rename -uid "8C163E08-4C12-F489-0505-F4B1B17220FE";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  3.2862602e-14 9.7699626e-15 
		17.637478 3.1974423e-14 9.7699626e-15 17.637478 3.2862602e-14 8.8817842e-15 17.637478 
		3.1974423e-14 8.8817842e-15 17.637478 -1.5987212e-14 -8.8817842e-16 19.126936 -1.5987212e-14 
		-8.8817842e-16 19.126936 -1.5987212e-14 -8.8817842e-16 19.126936 -1.5987212e-14 -8.8817842e-16 
		19.126936;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube22";
	rename -uid "488E29BC-4162-1E37-C604-798BC35F0D5A";
	setAttr ".t" -type "double3" -21.985201331729066 6.1868701816246494 45.730914183769485 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 22.698919946588838 -3.0487395727990605 5.0739164470166713 ;
	setAttr ".sp" -type "double3" 22.698919946588838 -3.0487395727990605 5.0739164470166713 ;
createNode mesh -n "pCubeShape22" -p "pCube22";
	rename -uid "B7D24CB5-407F-127F-1F12-2886BCEAF22C";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -2.4868996e-14 0 0.094980463 
		-2.4868996e-14 0 0.094980463 -2.4868996e-14 0 0.094980463 -2.4868996e-14 0 0.094980463 
		-2.4868996e-14 0 1.584438 -2.4868996e-14 0 1.584438 -2.4868996e-14 0 1.584438 -2.4868996e-14 
		0 1.584438;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube23";
	rename -uid "E18171C1-4845-C606-2865-3784C8126E5D";
	setAttr ".t" -type "double3" -21.985201331729066 6.2383952411995223 -7.2690858162305432 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 22.698919946588838 -3.1002646323739333 58.0739164470167 ;
	setAttr ".sp" -type "double3" 22.698919946588838 -3.1002646323739333 58.0739164470167 ;
createNode mesh -n "pCubeShape23" -p "pCube23";
	rename -uid "A1ABCDB7-4381-2CAB-A66E-EFB2596C1BC0";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 8.8662291 0 0 8.8662291 
		0 0 8.8662291 0 0 8.8662291 0 0 10.355687 0 0 10.355687 0 0 10.355687 0 0 10.355687;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube24";
	rename -uid "22A12C3F-44B5-483F-D7C2-F2B127DFD233";
	setAttr ".t" -type "double3" -21.985201331729066 6.2383952411995223 -60.269085816230543 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 22.698919946588838 -3.1002646323739333 111.0739164470167 ;
	setAttr ".sp" -type "double3" 22.698919946588838 -3.1002646323739333 111.0739164470167 ;
createNode mesh -n "pCubeShape24" -p "pCube24";
	rename -uid "0C167C71-4579-F380-A484-009A91DAEEFB";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  2.4868996e-14 1.2434498e-14 
		17.637478 2.4868996e-14 1.2434498e-14 17.637478 2.4868996e-14 1.2434498e-14 17.637478 
		2.4868996e-14 1.2434498e-14 17.637478 2.4868996e-14 1.2434498e-14 19.126936 2.4868996e-14 
		1.2434498e-14 19.126936 2.4868996e-14 1.2434498e-14 19.126936 2.4868996e-14 1.2434498e-14 
		19.126936;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube25";
	rename -uid "28F0C74D-436C-2767-4262-E0A682D9BC28";
	setAttr ".t" -type "double3" -36.985201331729066 6.1868701816246494 45.730914183769485 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 37.698919946588838 -3.0487395727990605 5.0739164470166713 ;
	setAttr ".sp" -type "double3" 37.698919946588838 -3.0487395727990605 5.0739164470166713 ;
createNode mesh -n "pCubeShape25" -p "pCube25";
	rename -uid "0242198A-445A-E071-CA4A-CBA96BAC10C8";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 0.094980463 0 0 0.094980463 
		0 0 0.094980463 0 0 0.094980463 0 0 1.584438 0 0 1.584438 0 0 1.584438 0 0 1.584438;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube26";
	rename -uid "1A224048-4A90-EE40-9A6C-B5B53F18877E";
	setAttr ".t" -type "double3" -36.985201331729066 6.2383952411995223 -7.2690858162305432 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 37.698919946588838 -3.1002646323739333 58.0739164470167 ;
	setAttr ".sp" -type "double3" 37.698919946588838 -3.1002646323739333 58.0739164470167 ;
createNode mesh -n "pCubeShape26" -p "pCube26";
	rename -uid "371D472E-4DEF-85CE-08ED-378CF4186249";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 8.8662291 0 0 8.8662291 
		0 0 8.8662291 0 0 8.8662291 0 0 10.355687 0 0 10.355687 0 0 10.355687 0 0 10.355687;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube27";
	rename -uid "D088A50A-4941-A76D-D5F2-FC8889C259F2";
	setAttr ".t" -type "double3" -36.985201331729066 6.2383952411995223 -60.269085816230543 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 37.698919946588838 -3.1002646323739333 111.0739164470167 ;
	setAttr ".sp" -type "double3" 37.698919946588838 -3.1002646323739333 111.0739164470167 ;
createNode mesh -n "pCubeShape27" -p "pCube27";
	rename -uid "9019A910-4FE1-F4BA-362D-1ABDB64CDD49";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 17.637478 0 0 17.637478 
		0 0 17.637478 0 0 17.637478 0 0 19.126936 0 0 19.126936 0 0 19.126936 0 0 19.126936;
	setAttr -s 8 ".vt[0:7]"  -4 -4 4.5 4 -4 4.5 -4 4 4.5 4 4 4.5 -4 4 -4.5
		 4 4 -4.5 -4 -4 -4.5 4 -4 -4.5;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube28";
	rename -uid "615B32E9-4C98-9888-A103-0FAF0454AA1D";
	setAttr ".t" -type "double3" -16.50731066675641 11.126550361364924 -60.195169369213843 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -111 -7.9884197525393343 17.221029281616183 ;
	setAttr ".rpt" -type "double3" 128.22102928161618 0 93.778970718383817 ;
	setAttr ".sp" -type "double3" -111 -7.9884197525393343 17.221029281616207 ;
	setAttr ".spt" -type "double3" 0 0 -2.48689957516035e-14 ;
createNode mesh -n "pCubeShape28" -p "pCube28";
	rename -uid "B7A34A88-4B77-37D1-0622-BD89BCAD4738";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -17.5425 -1.2478907e-13 4.2632564e-14 
		-19.197453 -1.0924595e-13 4.2632564e-14 -17.5425 -1.2922996e-13 4.2632564e-14 -19.197453 
		-1.1435297e-13 4.2632564e-14 -17.5425 7.9936058e-15 34.442062 -19.197453 2.3314684e-14 
		34.442062 -17.5425 1.0880186e-14 34.442062 -19.197453 2.6090241e-14 34.442062;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube29";
	rename -uid "3C2664C4-4B99-402B-5E0E-EF8C000ECCFD";
	setAttr ".t" -type "double3" -16.498036060935796 11.126550361364924 -8.250094333446647 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -58.000000000000036 -7.9884197525393343 17.221029281616183 ;
	setAttr ".rpt" -type "double3" 75.211754675795589 0 41.833895682616621 ;
	setAttr ".sp" -type "double3" -58.000000000000036 -7.9884197525393343 17.221029281616183 ;
createNode mesh -n "pCubeShape29" -p "pCube29";
	rename -uid "5C553E4D-4688-6019-1692-87AD0A876E6F";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -8.7712498 0 4.2632564e-14 
		-10.426202 0 4.2632564e-14 -8.7712498 -4.3298698e-15 4.2632564e-14 -10.426202 -4.3298698e-15 
		4.2632564e-14 -8.7712498 0 34.442062 -10.426202 0 34.442062 -8.7712498 1.9984014e-15 
		34.442062 -10.426202 1.9984014e-15 34.442062;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube30";
	rename -uid "8BFEA16B-410B-9274-BDD5-78AA3BAAFBAA";
	setAttr ".t" -type "double3" -16.498036060935796 11.138130608825589 44.749905666553346 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -5.0000000000000142 -8 17.221029281616183 ;
	setAttr ".rpt" -type "double3" 22.211754675795582 0 -11.166104317383386 ;
	setAttr ".sp" -type "double3" -5.0000000000000142 -8 17.221029281616183 ;
createNode mesh -n "pCubeShape30" -p "pCube30";
	rename -uid "BB802873-41E3-1FEA-4D32-24A6E5EA46C0";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -9.7699626e-15 0 4.2632564e-14 
		-1.6549526 1.110223e-15 4.2632564e-14 -9.7699626e-15 -5.884182e-15 4.2632564e-14 
		-1.6549526 -4.3298698e-15 4.2632564e-14 -9.7699626e-15 -1.5543122e-15 34.442062 -1.6549526 
		0 34.442062 -9.7699626e-15 1.9984014e-15 34.442062 -1.6549526 3.1086245e-15 34.442062;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube31";
	rename -uid "D0BCBD3D-4B7C-2DE0-8422-E983D1A5E38D";
	setAttr ".t" -type "double3" 38.105674285666048 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -37.391955670806276 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" -37.391955670806276 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape31" -p "pCube31";
	rename -uid "F9754F48-4A5A-5713-8A40-8E8951EE40D5";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -1.8651747e-13 0 -0.37396088 
		-2.1138646e-13 0 -0.37396088 -1.8651747e-13 0 -0.37396088 -2.1138646e-13 0 -0.37396088 
		-1.8651747e-13 0 19.485472 -2.1138646e-13 0 19.485472 -1.8651747e-13 0 19.485472 
		-2.1138646e-13 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube32";
	rename -uid "7A8DA9B0-43B6-DB21-5DC3-B5A7FFD5D2E3";
	setAttr ".t" -type "double3" 23.105674285666048 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -22.391955670806276 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" -22.391955670806276 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape32" -p "pCube32";
	rename -uid "65189C03-45A7-B8FB-E3B8-C28532176DA6";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube33";
	rename -uid "F42C3BEE-46D8-5B11-2C95-C5AC91898AF3";
	setAttr ".t" -type "double3" 8.1056742856660478 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -7.3919556708062757 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" -7.3919556708062757 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape33" -p "pCube33";
	rename -uid "AFDCB7CC-47E9-9D68-5F27-D693D450F604";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -1.2523316e-13 0 -0.37396088 
		-1.2523316e-13 0 -0.37396088 -1.2523316e-13 0 -0.37396088 -1.2523316e-13 0 -0.37396088 
		1.1723955e-13 0 19.485472 1.1723955e-13 0 19.485472 1.1723955e-13 0 19.485472 1.1723955e-13 
		0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube34";
	rename -uid "F7CD66F7-4845-1A14-CE89-FE9B72B40425";
	setAttr ".t" -type "double3" -6.8943257143339522 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 7.6080443291937243 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" 7.6080443291937243 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape34" -p "pCube34";
	rename -uid "DC55B265-4805-9ACE-23AF-62AA7305C696";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube35";
	rename -uid "875A0DF1-44E2-3810-92D2-FEA3C148404A";
	setAttr ".t" -type "double3" -21.894325714333952 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 22.608044329193724 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" 22.608044329193724 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape35" -p "pCube35";
	rename -uid "7532D352-41AC-742B-ACF9-00869F1FB1B2";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube36";
	rename -uid "EE808E0B-4E51-F6A2-E9AE-AD833E3F5FEE";
	setAttr ".t" -type "double3" -36.894325714333952 1.1175814503280683 -6.9355211702555124 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 37.608044329193724 2.0205491584975208 57.740351801041669 ;
	setAttr ".sp" -type "double3" 37.608044329193724 2.0205491584975208 57.740351801041669 ;
createNode mesh -n "pCubeShape36" -p "pCube36";
	rename -uid "C1792845-413C-E7B5-971C-2DB7D068B0F6";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 0 -0.37396088 0 0 -0.37396088 
		0 0 -0.37396088 0 0 -0.37396088 0 0 19.485472 0 0 19.485472 0 0 19.485472 0 0 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube37";
	rename -uid "E33698E8-49DE-D1BD-C7A2-46A7CF01AB9B";
	setAttr ".t" -type "double3" -36.894325714333952 13.076476146139978 -6.9355211702555195 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 37.608044329193724 -9.9383455373143885 57.740351801041676 ;
	setAttr ".sp" -type "double3" 37.608044329193724 -9.9383455373143885 57.740351801041676 ;
createNode mesh -n "pCubeShape37" -p "pCube37";
	rename -uid "43776556-4C69-C272-78FA-979C8230610C";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  1.2434498e-14 3.1086245e-15 
		-0.37396088 -1.2434498e-14 3.1086245e-15 -0.37396088 1.2434498e-14 -3.1086245e-15 
		-0.37396088 -1.2434498e-14 -3.1086245e-15 -0.37396088 -1.2434498e-14 3.1086245e-15 
		19.485472 1.2434498e-14 3.1086245e-15 19.485472 -1.2434498e-14 -3.1086245e-15 19.485472 
		1.2434498e-14 -3.1086245e-15 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube38";
	rename -uid "9B6D6036-41FD-98E7-4D82-83A8760A9884";
	setAttr ".t" -type "double3" -21.894325714333952 13.076476146139978 -6.9355211702555195 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 22.608044329193724 -9.9383455373143885 57.740351801041676 ;
	setAttr ".sp" -type "double3" 22.608044329193724 -9.9383455373143885 57.740351801041676 ;
createNode mesh -n "pCubeShape38" -p "pCube38";
	rename -uid "24153F74-4744-6F4E-7308-6DAEFCF7751E";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  1.2434498e-14 3.1086245e-15 
		-0.37396088 -1.2434498e-14 3.1086245e-15 -0.37396088 1.2434498e-14 -3.1086245e-15 
		-0.37396088 -1.2434498e-14 -3.1086245e-15 -0.37396088 -1.2434498e-14 3.1086245e-15 
		19.485472 1.2434498e-14 3.1086245e-15 19.485472 -1.2434498e-14 -3.1086245e-15 19.485472 
		1.2434498e-14 -3.1086245e-15 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube39";
	rename -uid "BE754D1F-4EF5-1CD8-F2A4-F681D6D77826";
	setAttr ".t" -type "double3" -6.8943257143339522 13.076476146139978 -6.9355211702555195 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" 7.6080443291937243 -9.9383455373143885 57.740351801041676 ;
	setAttr ".sp" -type "double3" 7.6080443291937243 -9.9383455373143885 57.740351801041676 ;
createNode mesh -n "pCubeShape39" -p "pCube39";
	rename -uid "758C4169-4366-BE30-CA9E-1A8811AC0FED";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  1.2434498e-14 3.1086245e-15 
		-0.37396088 -1.2434498e-14 3.1086245e-15 -0.37396088 1.2434498e-14 -3.1086245e-15 
		-0.37396088 -1.2434498e-14 -3.1086245e-15 -0.37396088 -1.2434498e-14 3.1086245e-15 
		19.485472 1.2434498e-14 3.1086245e-15 19.485472 -1.2434498e-14 -3.1086245e-15 19.485472 
		1.2434498e-14 -3.1086245e-15 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube40";
	rename -uid "738C1AD2-439F-A421-2F03-6480D8244108";
	setAttr ".t" -type "double3" 8.1056742856660478 13.076476146139978 -6.9355211702555195 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -7.3919556708062757 -9.9383455373143885 57.740351801041676 ;
	setAttr ".sp" -type "double3" -7.3919556708062757 -9.9383455373143885 57.740351801041676 ;
createNode mesh -n "pCubeShape40" -p "pCube40";
	rename -uid "26BF937F-4502-BD44-0F44-DFB0F5F214C0";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 4.5741189e-14 -0.37396088 
		0 4.5741189e-14 -0.37396088 0 4.6407322e-14 -0.37396088 0 4.6407322e-14 -0.37396088 
		0 -4.2854609e-14 19.485472 0 -4.2854609e-14 19.485472 0 -4.2632564e-14 19.485472 
		0 -4.2632564e-14 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube41";
	rename -uid "2017D014-4981-C90D-A28B-D0A1E62A9FBA";
	setAttr ".t" -type "double3" 23.105674285666048 13.076476146139978 -6.9355211702555195 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -22.391955670806276 -9.9383455373143885 57.740351801041676 ;
	setAttr ".sp" -type "double3" -22.391955670806276 -9.9383455373143885 57.740351801041676 ;
createNode mesh -n "pCubeShape41" -p "pCube41";
	rename -uid "96098E71-493E-2002-60F8-0C93A084835E";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  0 -2.4868996e-14 -0.37396088 
		0 -2.4868996e-14 -0.37396088 0 -2.4868996e-14 -0.37396088 0 -2.4868996e-14 -0.37396088 
		0 -2.4868996e-14 19.485472 0 -2.4868996e-14 19.485472 0 -2.4868996e-14 19.485472 
		0 -2.4868996e-14 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube42";
	rename -uid "E29DB6F3-4894-A13B-6A0A-1EA1AD69E35F";
	setAttr ".t" -type "double3" 38.105674285666048 13.076476146139978 -6.9355211702555195 ;
	setAttr -av ".tx";
	setAttr -av ".ty";
	setAttr -av ".tz";
	setAttr ".rp" -type "double3" -37.391955670806276 -9.9383455373143885 57.740351801041676 ;
	setAttr ".sp" -type "double3" -37.391955670806276 -9.9383455373143885 57.740351801041676 ;
createNode mesh -n "pCubeShape42" -p "pCube42";
	rename -uid "384F57CE-4807-7B99-EADC-B9B84684B850";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".pt[0:7]" -type "float3"  -4.1389114e-13 -1.7763568e-14 
		-0.37396088 -4.1389114e-13 -1.7763568e-14 -0.37396088 -4.1389114e-13 -1.5543122e-14 
		-0.37396088 -4.1389114e-13 -1.5543122e-14 -0.37396088 0 -3.2862602e-14 19.485472 
		0 -3.2862602e-14 19.485472 0 -3.2862602e-14 19.485472 0 -3.2862602e-14 19.485472;
	setAttr -s 8 ".vt[0:7]"  -5 -1 60 5 -1 60 -5 1 60 5 1 60 -5 1 -60
		 5 1 -60 -5 -1 -60 5 -1 -60;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 6 -ch 24 ".fc[0:5]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 3 2
		f 4 1 7 -3 -7
		mu 0 4 2 3 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 -1 -11
		mu 0 4 6 7 9 8
		f 4 -12 -10 -8 -6
		mu 0 4 1 10 11 3
		f 4 10 4 6 8
		mu 0 4 12 0 2 13;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "94ADC097-47AC-9EA6-F50D-B281867E33FF";
	setAttr -s 3 ".lnk";
	setAttr -s 3 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "879292AE-49C1-48FF-142F-638C87FEAA3E";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "20EF13AF-4952-3264-8E31-9DADE30558E6";
createNode displayLayerManager -n "layerManager";
	rename -uid "F2C1EC97-40AF-9B08-5387-9BA85FCF5FF9";
createNode displayLayer -n "defaultLayer";
	rename -uid "45D86949-4101-3F2D-C3A0-C8B00BB0C9F2";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "42B3912A-4111-CCA9-36B0-D68BE488CC81";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "2BAB7981-4BD2-8476-69FE-50B8CB25C14A";
	setAttr ".g" yes;
createNode file -n "groundplane";
	rename -uid "E827D49E-4B61-5242-F115-5087B7D2A5A2";
	setAttr ".ftn" -type "string" "C:/Users/Jarne/Downloads/3D1_Template/sourceimages/tex_template.jpg";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture1";
	rename -uid "BFC1C0F0-434E-E4CB-E469-768E4055FC74";
createNode aiOptions -s -n "defaultArnoldRenderOptions";
	rename -uid "E136054B-4DBB-0FA7-6DC0-D4979A9EB378";
	setAttr ".AA_samples" 1;
	setAttr ".GI_specular_samples" 0;
	setAttr ".GI_transmission_samples" 0;
	setAttr ".GI_sss_samples" 0;
	setAttr ".GI_volume_samples" 0;
	setAttr ".version" -type "string" "4.0.0";
createNode aiAOVFilter -s -n "defaultArnoldFilter";
	rename -uid "0262258D-4773-B67A-7D9F-7FB8CB7A5C70";
	setAttr ".ai_translator" -type "string" "gaussian";
createNode aiAOVDriver -s -n "defaultArnoldDriver";
	rename -uid "4532E5BF-4A3F-7D92-2BBA-94BE24C03C04";
	setAttr ".ai_translator" -type "string" "exr";
createNode aiAOVDriver -s -n "defaultArnoldDisplayDriver";
	rename -uid "5422F237-4B26-B17E-8427-4D8AE2C6A708";
	setAttr ".output_mode" 0;
	setAttr ".ai_translator" -type "string" "maya";
createNode aiStandardSurface -n "groundplane_shader";
	rename -uid "CE3CDA3E-4835-C5CF-8075-43B0F4D01388";
	setAttr ".specular" 0.24475523829460144;
	setAttr ".specular_roughness" 1;
createNode shadingEngine -n "aiStandardSurface1SG";
	rename -uid "7C96987F-40DA-3130-61A6-968CC09447C3";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo2";
	rename -uid "64784839-49D1-F206-2E37-B28FC8B6B110";
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "D5B47428-432E-8712-39CF-9193F3585C26";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -301.31388888461095 343.18630246380752 ;
	setAttr ".tgi[0].vh" -type "double2" 1084.6154022410221 1488.4719224615171 ;
	setAttr -s 4 ".tgi[0].ni";
	setAttr ".tgi[0].ni[0].x" -15.714285850524902;
	setAttr ".tgi[0].ni[0].y" 1235.7142333984375;
	setAttr ".tgi[0].ni[0].nvs" 1923;
	setAttr ".tgi[0].ni[1].x" 640;
	setAttr ".tgi[0].ni[1].y" 1234.2857666015625;
	setAttr ".tgi[0].ni[1].nvs" 1923;
	setAttr ".tgi[0].ni[2].x" 291.42855834960938;
	setAttr ".tgi[0].ni[2].y" 1257.142822265625;
	setAttr ".tgi[0].ni[2].nvs" 2387;
	setAttr ".tgi[0].ni[3].x" -322.85714721679688;
	setAttr ".tgi[0].ni[3].y" 1212.857177734375;
	setAttr ".tgi[0].ni[3].nvs" 1923;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "52EA78D6-4078-5B7F-C2A9-19B5A2DD8754";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n"
		+ "            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n"
		+ "            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n"
		+ "            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1319\n            -height 696\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n"
		+ "            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n"
		+ "            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n"
		+ "            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n"
		+ "            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n"
		+ "                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n"
		+ "                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showPlayRangeShades \"on\" \n                -lockPlayRangeShades \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n"
		+ "                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -keyMinScale 1\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -valueLinesToggle 1\n                -highlightAffectedCurves 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n"
		+ "                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n"
		+ "                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n"
		+ "                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n"
		+ "                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n"
		+ "                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n"
		+ "\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n"
		+ "                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n"
		+ "                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\n{ string $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n"
		+ "                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 32768\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n"
		+ "                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -controllers 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n"
		+ "                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 0\n                -height 0\n                -sceneRenderFilter 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName;\n            stereoCameraView -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName; };\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n"
		+ "\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1319\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1319\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "B974DBF3-4293-F109-E37E-96A1B02E6C8A";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode animCurveTL -n "pCube7_translateX";
	rename -uid "B539D968-418D-0205-A968-28932EBE85CD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 19.678359506297625;
createNode animCurveTL -n "pCube7_translateY";
	rename -uid "48503EFF-4100-1893-FEE4-A3B4E2B7285A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 3.1381306088255907;
createNode animCurveTL -n "pCube7_translateZ";
	rename -uid "D731E9AF-405E-9418-469D-1EB9941E4B42";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 92.512169749499151;
createNode animCurveTU -n "pCube7_visibility";
	rename -uid "A01DAA3A-4EC3-B520-7C94-A29DC18F7883";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube7_rotateX";
	rename -uid "49F15B1E-427C-ADAB-1468-94969B50958D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube7_rotateY";
	rename -uid "3545E32C-4749-DF6A-7921-0C9C6C023CF5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 90;
createNode animCurveTA -n "pCube7_rotateZ";
	rename -uid "25F98AEE-48FA-FBD4-4B65-AC82CDDB5F74";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube7_scaleX";
	rename -uid "556498BB-4AA2-9859-1AD5-D9B0ABDBF283";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube7_scaleY";
	rename -uid "6D5494CD-497D-588E-A0F2-30840B9CD04B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube7_scaleZ";
	rename -uid "2629A205-4C1E-2C5A-C273-14A3492F082D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTL -n "pCube1_translateX";
	rename -uid "7BCA5295-46FD-93F1-B5C5-0B8236D4087D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -0.71793014710053171;
createNode animCurveTL -n "pCube1_translateY";
	rename -uid "4B1EE099-41F8-BBE6-5227-6B949A582977";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube1_translateZ";
	rename -uid "75704600-4A03-7814-91EA-A6BF95A596E1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube10_translateX";
	rename -uid "E5252284-46C9-B6FF-DF8F-05823AD1E145";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 74.191194235504355;
createNode animCurveTL -n "pCube10_translateY";
	rename -uid "5D823FD3-41BA-E7E1-7321-A49B04935CCD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.1868701816246512;
createNode animCurveTL -n "pCube10_translateZ";
	rename -uid "4B122521-41CC-DD2D-6062-5CBFDF362A4A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 93.493178266715262;
createNode animCurveTL -n "pCube11_translateX";
	rename -uid "31A1BA41-4636-6C4A-E220-B7952D5FB98C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 74.191194235504355;
createNode animCurveTL -n "pCube11_translateY";
	rename -uid "EF6E59C6-4666-AE68-F33F-7CB2B94C159E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube11_translateZ";
	rename -uid "DDD58E97-4715-12F0-FC3D-8B89FDB80D97";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.493178266715262;
createNode animCurveTL -n "pCube12_translateX";
	rename -uid "820BF35E-4854-7358-7E74-39924C1F11D4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 74.191194235504355;
createNode animCurveTL -n "pCube12_translateY";
	rename -uid "D609D845-45D7-8DB2-30AD-B6A7D1E23E4E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube12_translateZ";
	rename -uid "07C2AE16-4014-40D1-DAC0-9D8533B80A60";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.506821733284735;
createNode animCurveTL -n "pCube13_translateX";
	rename -uid "FD651827-4DFB-194E-95A7-2381247DF737";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 59.191194235504355;
createNode animCurveTL -n "pCube13_translateY";
	rename -uid "10FD330A-496D-0B3D-2DBB-EB89A948BD1D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.1868701816246512;
createNode animCurveTL -n "pCube13_translateZ";
	rename -uid "C1DF555E-4822-2B33-5313-308418A20F9E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 93.493178266715262;
createNode animCurveTL -n "pCube14_translateX";
	rename -uid "FE4EF634-46F6-0CD4-92E7-D79035B84868";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 59.191194235504355;
createNode animCurveTL -n "pCube14_translateY";
	rename -uid "821F8AE4-472F-EB29-C04E-44A1B461A418";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube14_translateZ";
	rename -uid "E060ADB8-4F02-7C1A-69BA-5D87661FE23E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.493178266715262;
createNode animCurveTL -n "pCube15_translateX";
	rename -uid "4BBB3747-49D6-D1A3-43FC-6BB14C059F15";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 59.191194235504355;
createNode animCurveTL -n "pCube15_translateY";
	rename -uid "2E3C039C-44D0-CA52-968D-D3B7D06D3808";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube15_translateZ";
	rename -uid "C2F51CEB-4B12-B1BA-B5A0-E391586EA6D0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.506821733284735;
createNode animCurveTL -n "pCube16_translateX";
	rename -uid "C418DDAA-4202-45AA-6CEC-E39A47BA36F7";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 44.191194235504355;
createNode animCurveTL -n "pCube16_translateY";
	rename -uid "A69CFD66-4EA1-7EE1-B1FA-C6BA8D76CF47";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.1868701816246512;
createNode animCurveTL -n "pCube16_translateZ";
	rename -uid "06138F1D-4EC3-FB42-EEA5-6F90626A1206";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 93.493178266715262;
createNode animCurveTL -n "pCube17_translateX";
	rename -uid "BCCCB146-42C0-F805-9308-24B7987A7F2A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 44.191194235504355;
createNode animCurveTL -n "pCube17_translateY";
	rename -uid "E192E9D6-45E8-02B5-DC6C-B5B1E82C19BD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube17_translateZ";
	rename -uid "B3EC4C84-4E3E-8F51-5212-58B4FA0FF875";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.493178266715262;
createNode animCurveTL -n "pCube18_translateX";
	rename -uid "1F810C32-4DD5-B238-994E-809C4B901CA4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 44.191194235504355;
createNode animCurveTL -n "pCube18_translateY";
	rename -uid "1FAA020F-44CF-D3E4-267B-83BEBCBCEA93";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube18_translateZ";
	rename -uid "59F74A81-4E78-2CCB-F92C-1589B6A06836";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.506821733284735;
createNode animCurveTL -n "pCube19_translateX";
	rename -uid "9D24CF16-4681-6F45-19BB-E295989CC108";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 29.191194235504355;
createNode animCurveTL -n "pCube19_translateY";
	rename -uid "276AE5D0-4766-DD84-5089-ED9520C26E22";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.1868701816246512;
createNode animCurveTL -n "pCube19_translateZ";
	rename -uid "98485471-4493-43DE-EB18-1DA1BF47BBC6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 93.493178266715262;
createNode animCurveTL -n "pCube2_translateX";
	rename -uid "FCCF6DF2-4E2A-D6C7-5A0F-42808F289E97";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 14.282069852899468;
createNode animCurveTL -n "pCube2_translateY";
	rename -uid "60E5D7EA-4E42-1B07-F11F-4C97D7A6F0F5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube2_translateZ";
	rename -uid "8D90BC02-448A-7898-7B9E-4884CB3C6961";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube20_translateX";
	rename -uid "D1DF1F8F-4099-DF3A-645C-E1AE39B7D356";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 29.191194235504355;
createNode animCurveTL -n "pCube20_translateY";
	rename -uid "AFDEA82E-4328-CADD-442D-1C968158E1F2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube20_translateZ";
	rename -uid "054B693B-4C24-DFBA-8FF7-5E9EFFCB082A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.493178266715262;
createNode animCurveTL -n "pCube21_translateX";
	rename -uid "385FDEA2-4E2F-E0BB-DBFF-609062B5ED09";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 29.191194235504355;
createNode animCurveTL -n "pCube21_translateY";
	rename -uid "C75A3E65-4AD9-DBA2-711A-A082285B56E4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube21_translateZ";
	rename -uid "8A0267F8-4A21-38A3-72A4-8C9CBCF42CBC";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.506821733284735;
createNode animCurveTL -n "pCube22_translateX";
	rename -uid "628D0C9E-4C46-8D7A-72BF-F9A3D34C4EEC";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 14.191194235504355;
createNode animCurveTL -n "pCube22_translateY";
	rename -uid "3894EE49-44D8-7F20-2505-79828B48B220";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.1868701816246512;
createNode animCurveTL -n "pCube22_translateZ";
	rename -uid "C0F9E356-439C-1AE0-C28F-4680BDCEBDEE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 93.49317826671529;
createNode animCurveTL -n "pCube23_translateX";
	rename -uid "5CC3BCAE-47E9-7763-4649-17B05D710687";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 14.191194235504355;
createNode animCurveTL -n "pCube23_translateY";
	rename -uid "D2D1D6AA-4BC0-8FCC-BA61-AE9AE407D0AE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube23_translateZ";
	rename -uid "11729CB1-4936-BD5F-D59E-C0A730790257";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.493178266715262;
createNode animCurveTL -n "pCube24_translateX";
	rename -uid "A84F8B41-4699-1B18-A5D5-4AAAEA6BFAD6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 14.191194235504355;
createNode animCurveTL -n "pCube24_translateY";
	rename -uid "263CBC8F-4A66-7340-7922-2196A000D7E2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube24_translateZ";
	rename -uid "325F668B-40BA-4F07-9C91-ABACE776543F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.506821733284735;
createNode animCurveTL -n "pCube25_translateX";
	rename -uid "CF271456-4E88-D4C6-C49F-0C9DDA184974";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -0.80880576449564501;
createNode animCurveTL -n "pCube25_translateY";
	rename -uid "9AB7428F-443D-71B6-1905-AC9D2F2D6F9A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.1868701816246512;
createNode animCurveTL -n "pCube25_translateZ";
	rename -uid "FFF2C70B-4257-B9A5-F250-D9AE20170DE6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 93.49317826671529;
createNode animCurveTL -n "pCube26_translateX";
	rename -uid "D2F2DC9C-4551-5751-AB90-42A6A80B3A92";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -0.80880576449564501;
createNode animCurveTL -n "pCube26_translateY";
	rename -uid "DE8AFA7E-4F4E-3260-DAAA-2E8C7FB9EF36";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube26_translateZ";
	rename -uid "8679F42B-4192-6688-951D-7BB33A6C5424";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.493178266715262;
createNode animCurveTL -n "pCube27_translateX";
	rename -uid "0487218A-4C7D-5B6E-F4F4-5784DC4FF540";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -0.80880576449564501;
createNode animCurveTL -n "pCube27_translateY";
	rename -uid "F8B3D44F-44BB-4276-587F-93B491219B02";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 6.238395241199524;
createNode animCurveTL -n "pCube27_translateZ";
	rename -uid "B61719B8-430A-C634-3F0B-198B5A1144D8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.506821733284735;
createNode animCurveTL -n "pCube28_translateX";
	rename -uid "DD705F66-4655-4106-C8C5-C58C7097BE88";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 19.66908490047701;
createNode animCurveTL -n "pCube28_translateY";
	rename -uid "21CCF836-4EC1-2E09-8622-0B9BD0266290";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 11.126550361364925;
createNode animCurveTL -n "pCube28_translateZ";
	rename -uid "467B92E7-4B45-257B-005C-24A119B6300F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.432905286268035;
createNode animCurveTL -n "pCube29_translateX";
	rename -uid "A34210DD-4A19-BB12-4BC8-B898B8A82760";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 19.678359506297625;
createNode animCurveTL -n "pCube29_translateY";
	rename -uid "D3431F04-4E6C-4C9C-BC25-6DB81CF62940";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 11.126550361364925;
createNode animCurveTL -n "pCube29_translateZ";
	rename -uid "E1A93199-4C31-E28B-E6A2-BA9544BB9B82";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 39.512169749499158;
createNode animCurveTL -n "pCube3_translateX";
	rename -uid "5936DF67-4E12-9369-26E2-E1873CFD33CF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 29.282069852899468;
createNode animCurveTL -n "pCube3_translateY";
	rename -uid "F652242B-403E-5C64-75EC-6EBE7ADFF792";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube3_translateZ";
	rename -uid "4220C8CF-4A38-C0AB-1EDA-6FB2275E51D3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube30_translateX";
	rename -uid "D88EFA8F-43FA-9EE7-94D8-558F58F04DF8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 19.678359506297625;
createNode animCurveTL -n "pCube30_translateY";
	rename -uid "0B010836-4374-4AFF-0907-B998220BF10B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 11.138130608825591;
createNode animCurveTL -n "pCube30_translateZ";
	rename -uid "22B744B7-48DF-358C-3262-029CC73F401A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 92.512169749499151;
createNode animCurveTL -n "pCube31_translateX";
	rename -uid "8665F52C-4A96-C413-96E0-B58560000A21";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 74.282069852899468;
createNode animCurveTL -n "pCube31_translateY";
	rename -uid "E004AEAA-46EF-3767-04CC-05B79C4AA6E8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube31_translateZ";
	rename -uid "2D94A73A-429D-EE40-26C3-9B9D550E023B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube32_translateX";
	rename -uid "72EEF39D-459A-A763-79A2-A2859444BAE3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 59.282069852899468;
createNode animCurveTL -n "pCube32_translateY";
	rename -uid "63529DE2-402E-5D6C-3D35-8AB0034B3E32";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube32_translateZ";
	rename -uid "F1AB7951-43DF-56EF-8241-019241CB6CC8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube33_translateX";
	rename -uid "BF080FAF-4F89-A598-0B6B-EA85B5E4E0AF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 44.282069852899468;
createNode animCurveTL -n "pCube33_translateY";
	rename -uid "C590622B-4087-E219-A6A7-32B734A78693";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube33_translateZ";
	rename -uid "D325830B-4E72-92BE-E039-4C9F927AB472";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube34_translateX";
	rename -uid "2719C3AD-477D-C1AC-C7A5-4A889C35DAC0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 29.282069852899468;
createNode animCurveTL -n "pCube34_translateY";
	rename -uid "34B26948-4375-820A-0C27-B5B383CE50C1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube34_translateZ";
	rename -uid "47418E90-4855-E0EC-2F2D-FF9998102F0D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube35_translateX";
	rename -uid "704BC1AB-4CAA-2DA0-FA60-99A35AF404AA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 14.282069852899468;
createNode animCurveTL -n "pCube35_translateY";
	rename -uid "88D5E7AA-4619-E82F-3CB7-79B6A4DD5B4A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube35_translateZ";
	rename -uid "4FA3086D-489C-03D5-1FA1-7CAE5FFAC080";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube36_translateX";
	rename -uid "DEA0FB0C-4CA3-1A27-F1A0-4888E623917E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -0.71793014710053171;
createNode animCurveTL -n "pCube36_translateY";
	rename -uid "9EBBE32E-4A3A-0EBD-AAF5-D2AD18B8C54C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube36_translateZ";
	rename -uid "21AF7CD7-40CC-7AE2-EB54-F8868CA2F33E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube37_translateX";
	rename -uid "4F6855BE-4EBE-5C8A-46DE-F6B28BF3E4D6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -0.71793014710053171;
createNode animCurveTL -n "pCube37_translateY";
	rename -uid "ECFE57E6-40D9-476C-9B98-228FF33A83AD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 13.07647614613998;
createNode animCurveTL -n "pCube37_translateZ";
	rename -uid "1BEFDBCD-4D9F-2B06-C108-7F94B82B2327";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690285;
createNode animCurveTL -n "pCube38_translateX";
	rename -uid "9FD4E692-4509-6BD1-FAAB-289C904FF931";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 14.282069852899468;
createNode animCurveTL -n "pCube38_translateY";
	rename -uid "BDC35EF7-4270-E241-36B6-6F8DF34AB13E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 13.07647614613998;
createNode animCurveTL -n "pCube38_translateZ";
	rename -uid "6A6B77B7-435E-A2EE-F4BA-31837858B0FD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690285;
createNode animCurveTL -n "pCube39_translateX";
	rename -uid "1D04938C-4A4E-EDD1-14E8-2094AA4E3304";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 29.282069852899468;
createNode animCurveTL -n "pCube39_translateY";
	rename -uid "E11D52FB-461E-9CD3-42DF-F19E0502C574";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 13.07647614613998;
createNode animCurveTL -n "pCube39_translateZ";
	rename -uid "5C3D34B8-4841-5B19-5169-639F241EB158";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690285;
createNode animCurveTL -n "pCube4_translateX";
	rename -uid "7A34D624-4934-8C30-290B-A6A5A724D4B2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 44.282069852899468;
createNode animCurveTL -n "pCube4_translateY";
	rename -uid "8B6CF57F-4C06-1AD9-7DD6-88A59BE8CB74";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube4_translateZ";
	rename -uid "2C7DFD15-430F-1F4D-2590-A597C5103215";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube40_translateX";
	rename -uid "AA7A5350-455C-EF7D-A154-1B9577E8C98A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 44.282069852899468;
createNode animCurveTL -n "pCube40_translateY";
	rename -uid "9137B746-4575-07C6-5405-BC828D0E0742";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 13.07647614613998;
createNode animCurveTL -n "pCube40_translateZ";
	rename -uid "FCBFD7C1-486B-AFEC-B78F-C7AB6B658386";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690285;
createNode animCurveTL -n "pCube41_translateX";
	rename -uid "D5D16BB8-4921-9792-BC5F-69BCF7C0ACEF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 59.282069852899468;
createNode animCurveTL -n "pCube41_translateY";
	rename -uid "0E486584-4ED9-0670-25EF-D0A9D992DD4C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 13.07647614613998;
createNode animCurveTL -n "pCube41_translateZ";
	rename -uid "A59BEE3E-4DF3-F5DA-551E-D89283826FFB";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690285;
createNode animCurveTL -n "pCube42_translateX";
	rename -uid "37EBD95D-4735-5C96-46B1-1F9D94E9D18F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 74.282069852899468;
createNode animCurveTL -n "pCube42_translateY";
	rename -uid "6A61D62A-43CA-59D5-FD94-67922A2A91D1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 13.07647614613998;
createNode animCurveTL -n "pCube42_translateZ";
	rename -uid "156F7C1E-4C0E-1901-F7BD-B89E832FB7D2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690285;
createNode animCurveTL -n "pCube5_translateX";
	rename -uid "42438C44-4C6F-8528-96A6-D8B1DB761753";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 59.282069852899468;
createNode animCurveTL -n "pCube5_translateY";
	rename -uid "DA3EECA6-4823-BB07-65A6-968AA0848B1D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube5_translateZ";
	rename -uid "56363D1F-48CD-4293-D377-ED857E05EFBD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube6_translateX";
	rename -uid "5699EF05-4D9A-950F-960B-E59681C2E1E4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 74.282069852899468;
createNode animCurveTL -n "pCube6_translateY";
	rename -uid "3F932882-4962-AF62-2ADF-4F99649D8F70";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1.1175814503280701;
createNode animCurveTL -n "pCube6_translateZ";
	rename -uid "D275E1B0-422C-10A6-A9CC-6EB62ADDD5F5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 40.826742912690293;
createNode animCurveTL -n "pCube8_translateX";
	rename -uid "8F80E1C9-499E-91CE-628F-80BA17D89950";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 19.678359506297625;
createNode animCurveTL -n "pCube8_translateY";
	rename -uid "A96527C2-4DD7-8BD6-D5E7-A3ACC38FCB59";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 3.1265503613649286;
createNode animCurveTL -n "pCube8_translateZ";
	rename -uid "D72E13D7-498F-D947-6B63-9A9FAD0937C9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 39.512169749499158;
createNode animCurveTL -n "pCube9_translateX";
	rename -uid "EEE6343F-4C3B-3FAE-782D-449681817037";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 19.66908490047701;
createNode animCurveTL -n "pCube9_translateY";
	rename -uid "018D6B37-4146-0382-3D69-8A8BFD6E58A9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 3.126550361364929;
createNode animCurveTL -n "pCube9_translateZ";
	rename -uid "520713E3-4826-79F4-7B5A-77B3941C3505";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -12.432905286268035;
createNode animCurveTU -n "pCube1_visibility";
	rename -uid "DC13A7B5-42F2-340D-3717-85A9B12E2374";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube1_rotateX";
	rename -uid "433143C2-48AA-EECC-3623-1CB5827651EE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube1_rotateY";
	rename -uid "31C4F1AD-4AB5-9123-7184-0FA708F90163";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube1_rotateZ";
	rename -uid "4A883379-4D11-8E2C-1A7D-0687F0932334";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube1_scaleX";
	rename -uid "0464E407-4627-A9E5-A125-888FA4618174";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube1_scaleY";
	rename -uid "556F74F5-4651-82F0-A9C8-5DB87C76591A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube1_scaleZ";
	rename -uid "3CF5080F-4131-4125-7132-02BD1B16A51B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube2_visibility";
	rename -uid "1E1BD050-4327-7291-212D-B09F1A0C3BFA";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube2_rotateX";
	rename -uid "7A78A332-4F9E-B6F0-CCCC-EEA7C10023B4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube2_rotateY";
	rename -uid "BF30352B-415A-5B3D-B28B-E283C757EDA0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube2_rotateZ";
	rename -uid "AA37850A-4CCB-B4AD-5FC5-DEAB4CABE49B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube2_scaleX";
	rename -uid "044BB657-4B8D-897C-FB7F-47B76DC1C5FA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube2_scaleY";
	rename -uid "748651FC-41AC-59F6-36AB-2C9FC9FB034F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube2_scaleZ";
	rename -uid "1CC34327-420E-2577-5AEC-3295D288AD7D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube3_visibility";
	rename -uid "CF1258E9-4AE1-8A1D-C348-04B5EC091CBF";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube3_rotateX";
	rename -uid "787117B6-4428-9AB6-21CA-CC84E7B8142B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube3_rotateY";
	rename -uid "E1681757-45DF-1463-D521-51BA1963AE6F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube3_rotateZ";
	rename -uid "A32688CD-41B4-1AEF-2D28-A08004F2D16A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube3_scaleX";
	rename -uid "39EECC9B-4073-1424-CBBF-CAB1147583C8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube3_scaleY";
	rename -uid "0385389A-4E95-AB8C-77AB-C9A5D1F8FACD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube3_scaleZ";
	rename -uid "6D6FECD0-47A1-1C60-0FD3-6AAEC1912B81";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube4_visibility";
	rename -uid "A3018382-4A73-097C-4763-9684B8D80DB8";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube4_rotateX";
	rename -uid "B5E1DBC9-4576-42C9-0C95-FEB7B232F4FE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube4_rotateY";
	rename -uid "23B271BE-413B-2705-07BC-E4BF5CC39B77";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube4_rotateZ";
	rename -uid "80A90679-4C31-1C0E-1CA3-1981511E2AE0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube4_scaleX";
	rename -uid "69E8A374-4A26-91A2-D566-A2B4A78D5C22";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube4_scaleY";
	rename -uid "A17FA62D-4FA2-7349-FDC5-85A7948AE397";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube4_scaleZ";
	rename -uid "CAD8031A-425C-FD02-2670-B3B9367452EF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube5_visibility";
	rename -uid "90AF1322-4F9E-D60D-5BB0-85BA037C675F";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube5_rotateX";
	rename -uid "F3AD1566-414D-B139-34C6-57A95D2A835F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube5_rotateY";
	rename -uid "58CF251A-4FE4-2FC1-8564-49A48A450C18";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube5_rotateZ";
	rename -uid "D92BDB8B-417B-78DA-D2BE-26BB07D53AD5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube5_scaleX";
	rename -uid "41285CBD-476E-587C-A22F-7A992F6C33F3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube5_scaleY";
	rename -uid "E756D441-4902-33A1-B987-42987F834AA1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube5_scaleZ";
	rename -uid "65F662EE-4475-2F55-C17A-2494D2263D4A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube6_visibility";
	rename -uid "8D78B528-447A-2628-1BCD-E6BC873045DC";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube6_rotateX";
	rename -uid "E142558B-401E-9D4C-77D2-739798B8F256";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube6_rotateY";
	rename -uid "93EB75A8-4D85-3BA7-9B94-AD8B974E1542";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube6_rotateZ";
	rename -uid "994CBFDF-4355-5155-D858-6B80D7A754D9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube6_scaleX";
	rename -uid "DCDF8753-4F56-7CCB-B1FF-4E877BC54BE3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube6_scaleY";
	rename -uid "D4627550-4D34-CAA7-A5B1-92B96B27C88E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube6_scaleZ";
	rename -uid "16A8F302-4330-DA4E-9B21-4684E34989FA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube8_visibility";
	rename -uid "DAEE13CB-4096-7D9F-2232-63AD8F85D233";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube8_rotateX";
	rename -uid "7A5062D3-4BDA-0FDB-343F-43876FA602EF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube8_rotateY";
	rename -uid "0D8AD3BF-414C-CC07-B691-09BE34887323";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 90;
createNode animCurveTA -n "pCube8_rotateZ";
	rename -uid "B90D357A-46FB-9236-F4AA-0390086967FF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube8_scaleX";
	rename -uid "46E73478-448D-94A0-31C0-D681E0467AA6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube8_scaleY";
	rename -uid "398416FC-4865-7669-62B9-52B60CBD18EA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube8_scaleZ";
	rename -uid "CE8CC608-4F4F-8788-9252-27A4EF74EB78";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube9_visibility";
	rename -uid "293952A0-453C-8117-A811-47B767BFCF1E";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube9_rotateX";
	rename -uid "0BA26507-41B0-3E81-1083-B0B34D0890F1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube9_rotateY";
	rename -uid "CB88E673-4D68-DA04-E5F6-86B60AF0BFC3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 90;
createNode animCurveTA -n "pCube9_rotateZ";
	rename -uid "F1D268C0-4D12-25EF-2791-62BFBF84B98C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube9_scaleX";
	rename -uid "DBBFC24E-4A02-9BA5-2C41-6FBBF520A71D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube9_scaleY";
	rename -uid "A266BE4D-4228-CFDA-D67B-6882AF8D62CE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube9_scaleZ";
	rename -uid "AF620299-44B0-A6D7-E04F-15BF72FD1B5A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0.99999999999999989;
createNode animCurveTU -n "pCube10_visibility";
	rename -uid "72E2EE3D-4094-1338-6BF0-3981E04CC1F8";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube10_rotateX";
	rename -uid "D1C225E7-46CE-A7B0-680B-C9A4F8298696";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube10_rotateY";
	rename -uid "436174C2-43F2-7D92-27B2-C5B5637FD373";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube10_rotateZ";
	rename -uid "00FD5106-4167-A32F-7E00-43A78264B881";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube10_scaleX";
	rename -uid "9A5D8F39-4BBF-5265-A547-58BC4AE53E12";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube10_scaleY";
	rename -uid "173A9454-4749-7F12-D5DA-7780E749046F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube10_scaleZ";
	rename -uid "86CCB34D-4702-59D3-BD2E-8D85CAEA6A18";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube11_visibility";
	rename -uid "31D98057-4D5B-62F4-3397-25AE6DBABE99";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube11_rotateX";
	rename -uid "29A21CA9-4939-E98D-F64C-C284BA34207A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube11_rotateY";
	rename -uid "9123FE9D-4293-2AFF-2BF4-D091A37657CD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube11_rotateZ";
	rename -uid "6801D374-453D-126B-E2BE-ECA71D010064";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube11_scaleX";
	rename -uid "C0E9A197-4093-0114-92F0-A4B325AD34F5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube11_scaleY";
	rename -uid "0E31DACB-47A4-6209-CE41-3E971AF9EE75";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube11_scaleZ";
	rename -uid "60E227DB-4ED4-5C09-50AA-2BA9264C6AAD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube12_visibility";
	rename -uid "2514EEA5-49C1-06ED-BA9D-6A812A4566A3";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube12_rotateX";
	rename -uid "0893277E-4A1E-38FE-76BD-07A51F2058C2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube12_rotateY";
	rename -uid "20472B28-4B4A-B580-DD1B-B089F3F8FA99";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube12_rotateZ";
	rename -uid "81A11293-453D-4136-BB72-41BBAFEB6F40";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube12_scaleX";
	rename -uid "37D15F7E-400B-80D7-3FC6-A18F78D94B4D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube12_scaleY";
	rename -uid "BC5BBBCA-435B-8F2B-82D3-91AC1B4D619D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube12_scaleZ";
	rename -uid "C248E4DB-44A3-83B1-19D8-2995DE54608A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube13_visibility";
	rename -uid "4BD2FE22-424F-EA9F-0924-DFB4EEE59AC7";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube13_rotateX";
	rename -uid "0711CEA0-44C2-616D-A148-AE8ED532DE6A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube13_rotateY";
	rename -uid "549A4D78-4ED1-1990-884D-078850A1479E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube13_rotateZ";
	rename -uid "1546E01B-4ECE-A739-7D32-BDA4BA34F255";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube13_scaleX";
	rename -uid "3AF96B52-4FB8-31C3-F577-EE9517388559";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube13_scaleY";
	rename -uid "AC88F416-4D9C-2763-0591-5FB133F42671";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube13_scaleZ";
	rename -uid "0647F25B-42A6-3255-CE58-B1B81151CC56";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube14_visibility";
	rename -uid "36299F8A-4032-7641-6187-6390B62772C2";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube14_rotateX";
	rename -uid "B94FC54C-40F9-0DB4-D1C8-D095A867446C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube14_rotateY";
	rename -uid "78FD1D96-4BB1-B7A1-C7B6-988D7A88AFE6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube14_rotateZ";
	rename -uid "4357A6CB-4C5E-66A5-121F-AC99B601A3FD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube14_scaleX";
	rename -uid "DC7BC77A-4745-7074-14C4-35BCD1DBDF20";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube14_scaleY";
	rename -uid "336C1A63-4CAF-9F50-F0B1-729834C79831";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube14_scaleZ";
	rename -uid "76BE6452-4E49-147B-5D76-1AAD32B9288A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube15_visibility";
	rename -uid "21C93376-4C9C-F3A4-AE7E-17B2EDE06F77";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube15_rotateX";
	rename -uid "CF9038F0-48D8-D38B-3C82-0BADDC447AAE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube15_rotateY";
	rename -uid "F6773584-4D61-B091-30B0-2B91FA7B80E4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube15_rotateZ";
	rename -uid "6EED8894-41CE-F85C-7345-B4B37AA5465E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube15_scaleX";
	rename -uid "46ADFECD-4AD7-4D8F-1B40-9F8A5333F2D7";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube15_scaleY";
	rename -uid "8F2E41FD-48E0-F2BE-024E-F1B73F181308";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube15_scaleZ";
	rename -uid "B3351D45-4FA6-0F9B-820B-79976E75228F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube16_visibility";
	rename -uid "B80B5609-47CA-FDF5-17CC-ACB4A6AC4062";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube16_rotateX";
	rename -uid "2ABAAD6F-4BD2-30EA-7567-62AD52A06119";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube16_rotateY";
	rename -uid "0E7469A2-4FE2-A04A-C85E-FBB69256207A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube16_rotateZ";
	rename -uid "49E6EB9E-4C52-B8B1-3949-C8A4A5D65002";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube16_scaleX";
	rename -uid "9D3213F3-42C8-F3FD-B147-09AF8EE05BCE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube16_scaleY";
	rename -uid "B77F6912-4ECA-B907-E6B2-559A2EFEDF2A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube16_scaleZ";
	rename -uid "0CFC8EF7-42AF-DD17-4559-7F883C058EB8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube17_visibility";
	rename -uid "D888CCC7-4146-E9A8-3B91-199D68E3B1F4";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube17_rotateX";
	rename -uid "C138308D-4591-EE18-0B49-DCA1D911C623";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube17_rotateY";
	rename -uid "0993D1CB-4CBE-6187-CCA3-EBAE2EBB7AF1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube17_rotateZ";
	rename -uid "101A834D-40EC-7CC2-FD5F-EBA67775C7E6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube17_scaleX";
	rename -uid "18A25758-4165-91D9-6AE3-0A82507E9E86";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube17_scaleY";
	rename -uid "C5195339-4284-2DD2-DF69-A080074D60C9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube17_scaleZ";
	rename -uid "B4B67ED3-4FE5-4DCC-D4C8-7E85D065B46A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube18_visibility";
	rename -uid "927F4E68-4E9E-28CF-5FC4-9BBDCA4A0139";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube18_rotateX";
	rename -uid "57D4B555-490F-CB3D-B328-08A78812743E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube18_rotateY";
	rename -uid "CEAD99AB-44D5-888C-4C5D-F3B38F8646EE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube18_rotateZ";
	rename -uid "ADD4C26A-423D-AEFA-75E4-BD894E6FC27A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube18_scaleX";
	rename -uid "5BA4EF13-4A5A-2F55-C857-EA86FB983212";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube18_scaleY";
	rename -uid "13A5F2EF-4C43-BCE3-162A-FFA61CACE49A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube18_scaleZ";
	rename -uid "3075BF15-4B4E-DD91-D3D5-9CA9CC623DB6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube19_visibility";
	rename -uid "0548F331-4383-D384-3D05-6797E0ED31C6";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube19_rotateX";
	rename -uid "05B114E7-49B9-1CE4-828E-97A84E1C3E74";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube19_rotateY";
	rename -uid "987E7658-40EC-6FC0-48E0-619D81D35B4B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube19_rotateZ";
	rename -uid "F35D2BCB-4AE4-745B-BF79-73AA42FC27A1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube19_scaleX";
	rename -uid "EF61D346-4D63-E2B4-AA41-2D90E2D30E93";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube19_scaleY";
	rename -uid "5582B96F-46A1-4239-9E23-FCA2207A24E1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube19_scaleZ";
	rename -uid "8CB3699A-47E8-CC2D-6FF1-D8B8C25E1A05";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube20_visibility";
	rename -uid "92EEAE3D-4170-CA5D-794B-7581B086F8F0";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube20_rotateX";
	rename -uid "0EC34D64-4559-CA5C-FF5D-089C81B53798";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube20_rotateY";
	rename -uid "23E74457-4D43-3E72-318D-94AA657479C8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube20_rotateZ";
	rename -uid "E6D1A205-47DD-A004-5B4B-4EAA120B183B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube20_scaleX";
	rename -uid "F313B1F3-46C2-712E-7B48-2CBA69D5CDE7";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube20_scaleY";
	rename -uid "94DDDD4C-4F61-A498-4F18-C1B664C3EF74";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube20_scaleZ";
	rename -uid "A1665B19-4296-8BFF-1E76-009EC9ACF17D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube21_visibility";
	rename -uid "E1442FA0-48F3-EE3B-0388-E99CBB1F4ED7";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube21_rotateX";
	rename -uid "82DDE449-4DD3-0A5F-458C-C9A8F629A7A3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube21_rotateY";
	rename -uid "79609B57-471A-55E6-1FDF-8D8F26BA5A20";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube21_rotateZ";
	rename -uid "0308A6F2-4669-89CC-A1F4-9ABB6A8C9DE3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube21_scaleX";
	rename -uid "CC126F1C-489D-7F8D-A76C-9EBB6DC009F2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube21_scaleY";
	rename -uid "571C68B4-4D61-585E-CECC-DC8C3F7A4667";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube21_scaleZ";
	rename -uid "AE79ADF1-4E81-3AFA-3C84-CD89435A110D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube22_visibility";
	rename -uid "E6A75D63-4FB4-FAC9-A34A-1FAF6135908D";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube22_rotateX";
	rename -uid "61716C5F-432A-24DF-76D7-7388A0E684CD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube22_rotateY";
	rename -uid "F3CD9984-4048-E0DF-04E3-F686AB5EB1D9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube22_rotateZ";
	rename -uid "B7B66928-4580-0D2D-346F-D599EAD878C6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube22_scaleX";
	rename -uid "64002428-458C-C276-B870-D880299B6EF4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube22_scaleY";
	rename -uid "A8AB391A-4F00-8EE4-7656-D799CA64219F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube22_scaleZ";
	rename -uid "4E42FA89-449E-5634-1156-739EA9EF6CBB";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube23_visibility";
	rename -uid "11767B66-4825-8586-590A-9D9E97CAE108";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube23_rotateX";
	rename -uid "33259109-4BAD-72CD-000D-719313595D0B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube23_rotateY";
	rename -uid "31D5C8AD-47F9-5B4C-6B82-53B68F9783B3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube23_rotateZ";
	rename -uid "91D6B3E1-4B28-718A-F4DB-DA90AA5D9909";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube23_scaleX";
	rename -uid "7DBEECD3-4732-76DA-8705-DD9B159263A5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube23_scaleY";
	rename -uid "E7620FE3-4BDB-A2C3-F568-6C8C79F7F1C1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube23_scaleZ";
	rename -uid "92AA828E-4DB3-4A8D-9806-11BB713CB590";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube24_visibility";
	rename -uid "85BD4A99-489E-557F-26D0-9CBB9FDC737B";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube24_rotateX";
	rename -uid "8B8BC627-41AE-164F-EF4D-3FB2D6E22F76";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube24_rotateY";
	rename -uid "0A81E374-4CD1-2871-5A99-0081119B772E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube24_rotateZ";
	rename -uid "C74FFC6D-4B12-8E88-E1DF-5A9333BCC7D9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube24_scaleX";
	rename -uid "2068063C-4C7B-D024-AE99-478E8CF0D67D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube24_scaleY";
	rename -uid "4AC9C2C2-4518-AD35-61A8-1FA2A927E27A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube24_scaleZ";
	rename -uid "8515B9DA-407B-A7E8-5ED5-5F937FE34B26";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube25_visibility";
	rename -uid "27F5CDE8-4B14-744D-0002-9D8DAA2EE26A";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube25_rotateX";
	rename -uid "86B6078B-49A1-CE83-3BC0-17A72B99E5A3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube25_rotateY";
	rename -uid "9AE7C459-4F5E-0EE8-ED7B-2BB63E973863";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube25_rotateZ";
	rename -uid "9057566C-4306-CCDB-A4CE-8E8078A2905E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube25_scaleX";
	rename -uid "FF67D384-42C9-B6B4-1C08-35A455C574D1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube25_scaleY";
	rename -uid "10F79F48-447F-7EE2-4395-D9A458397D1F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube25_scaleZ";
	rename -uid "8F85A72D-4090-52B8-92F3-ADA0AC6218F6";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube26_visibility";
	rename -uid "DFCF3603-49CC-4D6D-0307-C69551C2B80A";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube26_rotateX";
	rename -uid "0D8496D2-4D66-9B62-D456-74A0A7CF7F51";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube26_rotateY";
	rename -uid "E460BC8F-4298-A692-EBC7-87AC0E2DF6F0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube26_rotateZ";
	rename -uid "CDDCA900-44E7-9FD5-C72C-2EB73E4184E0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube26_scaleX";
	rename -uid "D1D5D30A-4E75-7D77-1D18-09AEDBE3BF2F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube26_scaleY";
	rename -uid "8E74A4F2-4FD6-7416-0D9D-4FAB86B66B01";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube26_scaleZ";
	rename -uid "763BAB4A-4A7F-98FD-993C-7CB8D759902B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube27_visibility";
	rename -uid "CFE7A4A6-44E3-D718-AD72-8F864F523048";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube27_rotateX";
	rename -uid "A9088690-4B84-BCED-D1BE-0C877DD35632";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube27_rotateY";
	rename -uid "D52D5BB0-423C-D0B7-BF65-A6B1127A05EE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube27_rotateZ";
	rename -uid "007DE906-48F8-2B23-6D80-E2B46C2041C0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube27_scaleX";
	rename -uid "4C836ACB-456C-B83C-9B88-FCB710AC211F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube27_scaleY";
	rename -uid "0E2C5C8B-4B4C-5B66-EFDE-4F8425D37C13";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube27_scaleZ";
	rename -uid "340E4C25-499E-790A-37BD-49A1BF2DFFDC";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube28_visibility";
	rename -uid "EBA895A3-44F5-046E-F172-9C9AF5BE7255";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube28_rotateX";
	rename -uid "6637C9E8-4102-A0F8-9023-4BB0153A40D9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube28_rotateY";
	rename -uid "DE38E6A7-461D-C5BD-6232-D29F48D5C73F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 90;
createNode animCurveTA -n "pCube28_rotateZ";
	rename -uid "887E7617-4C57-66B4-E25E-AC98F151FF29";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube28_scaleX";
	rename -uid "A3FF84B3-4132-77E9-D144-CA8B44F24743";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube28_scaleY";
	rename -uid "DBAE2362-411D-8A9B-BC1F-F78F6A90FC47";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube28_scaleZ";
	rename -uid "BE01697A-415C-4C47-6BAB-A980D3794D52";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0.99999999999999989;
createNode animCurveTU -n "pCube29_visibility";
	rename -uid "3C8843B1-42C8-163D-9E9C-13ABA63BFB10";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube29_rotateX";
	rename -uid "23A392DE-45DD-5636-E78B-AFA77BCD28E4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube29_rotateY";
	rename -uid "08AFCE74-4E68-7AC4-7624-D98CEF4A7348";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 90;
createNode animCurveTA -n "pCube29_rotateZ";
	rename -uid "0FC78262-4BB1-69F6-80B5-F39D076DAF19";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube29_scaleX";
	rename -uid "39901CA3-415E-8029-2643-6D9084A44733";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube29_scaleY";
	rename -uid "9660FB43-4F62-2569-0AC3-AE8CA41A09B3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube29_scaleZ";
	rename -uid "7E430B08-499F-4E08-C05A-4F88BF9681D2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube30_visibility";
	rename -uid "D1F04143-47A5-079D-99CD-06AB09E919EA";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube30_rotateX";
	rename -uid "DEBB72CC-4351-2F83-184D-509CBE342459";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube30_rotateY";
	rename -uid "BE44C34D-4C81-0E8A-11EB-93BAE9793B88";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 90;
createNode animCurveTA -n "pCube30_rotateZ";
	rename -uid "F5FD2655-42D3-D17C-2280-3F953DDD8359";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube30_scaleX";
	rename -uid "22D61C08-4D54-F7AD-C48F-BC867B1FB17B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube30_scaleY";
	rename -uid "B15A9BDE-4515-DAA5-868F-7C8E02FA7BE5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube30_scaleZ";
	rename -uid "C223DD02-4C9B-3158-7EF9-AD89D49AC661";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube31_visibility";
	rename -uid "526B3CB2-4A0D-34A2-A717-D39C3175004F";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube31_rotateX";
	rename -uid "12B793E2-4AB5-84A5-F49D-F4A8F52DBC4D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube31_rotateY";
	rename -uid "5B92CEAF-4F1E-D5C0-950C-498F7A4E555B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube31_rotateZ";
	rename -uid "7CB651FF-4E1E-F697-A8E8-A08131933BE1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube31_scaleX";
	rename -uid "1285314E-48FD-68BA-7D0E-C880623A4CF8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube31_scaleY";
	rename -uid "2FBA91CE-4529-2C8C-2AF3-14A9FF21033C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube31_scaleZ";
	rename -uid "001F98D5-46FE-298C-205C-B98D02E77899";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube32_visibility";
	rename -uid "6E2E2C00-4581-4960-99E4-0383BBE1A935";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube32_rotateX";
	rename -uid "88E7FB38-4F22-9C07-28E1-0A8ED30A2193";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube32_rotateY";
	rename -uid "F398B5AF-4F4E-82C1-6BD9-1AB5CDFB58E3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube32_rotateZ";
	rename -uid "7EF1356C-478A-1FBB-57DA-04AF8208A549";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube32_scaleX";
	rename -uid "3C3F5B99-46D6-6122-8A26-B9BF9EF7C318";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube32_scaleY";
	rename -uid "73628882-450D-E94A-5901-DBA6772BAED4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube32_scaleZ";
	rename -uid "728EC316-497B-79FB-C763-738B30355F7E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube33_visibility";
	rename -uid "12AE07FA-455E-2A2C-56B0-54917B5915BF";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube33_rotateX";
	rename -uid "65A4ED3D-4DD1-DFAE-200D-7E9518216411";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube33_rotateY";
	rename -uid "DADB6E88-419F-B98E-AE7F-57856B32CF5F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube33_rotateZ";
	rename -uid "BCC4BEF8-470E-ECDC-03E0-34891FE0A7B5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube33_scaleX";
	rename -uid "31D9087D-4745-BDB9-0FE7-83B1A9880EB9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube33_scaleY";
	rename -uid "DAE46F11-42D6-9FE4-2514-F6B6CF4F1F30";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube33_scaleZ";
	rename -uid "A305310C-4C0E-81CE-A70D-F2BB6D9ACDC3";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube34_visibility";
	rename -uid "A86A3CDD-41F5-3707-C00B-F69E2A4379BB";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube34_rotateX";
	rename -uid "D9760118-4109-36B1-D8D5-82BEC2CBD9AE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube34_rotateY";
	rename -uid "636E038C-46E9-EDA2-079A-57BE09899B1D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube34_rotateZ";
	rename -uid "A256AC03-462D-DDD4-FDB2-12B0E944725F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube34_scaleX";
	rename -uid "A827A6CE-4E80-8843-99A9-A3BC43345725";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube34_scaleY";
	rename -uid "3FF45D9D-4F01-0B3B-5E58-43BB0FEECEBA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube34_scaleZ";
	rename -uid "BC5DF263-4F17-FA11-D7D2-03A01C0E047E";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube35_visibility";
	rename -uid "F28EA419-4174-4DE0-069C-B8BEB78AB0EA";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube35_rotateX";
	rename -uid "CD0978C0-42FE-B959-9460-E1A93A04566A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube35_rotateY";
	rename -uid "003797E9-422D-5738-3538-0D8A4D6F9B60";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube35_rotateZ";
	rename -uid "56CC6B03-42EB-B9DA-7CFB-59BB515F8190";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube35_scaleX";
	rename -uid "44E4B4CC-46DD-1EAF-F842-3C88C3FF43FF";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube35_scaleY";
	rename -uid "45FE3437-4B1D-9132-1B6A-24A9E600D446";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube35_scaleZ";
	rename -uid "AA1B0BD5-4E96-34D4-5E3B-81A6B6C78D39";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube36_visibility";
	rename -uid "CA1344F1-4ECA-DD65-F8B7-44864A6FB1B1";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube36_rotateX";
	rename -uid "68FFEC10-4105-016C-BEE7-B29C900D5FCA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube36_rotateY";
	rename -uid "5508962A-4466-2CBC-733B-B6A3E9F00456";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube36_rotateZ";
	rename -uid "658DCB37-4BF1-08F1-85C3-6491EDC5465B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube36_scaleX";
	rename -uid "EF8A4D24-419D-8365-AA5B-41935C38365B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube36_scaleY";
	rename -uid "7B593C3B-4C6A-E343-6727-8DAFCBDF0110";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube36_scaleZ";
	rename -uid "0180C889-4B22-1FA0-A0FA-76ADBAB77712";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube37_visibility";
	rename -uid "D076DADC-47F5-9AC6-FFCF-E6A02FF92CE7";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube37_rotateX";
	rename -uid "FE0BF57F-444D-17D2-C855-CEB8D54DC1D9";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube37_rotateY";
	rename -uid "5A42AD3F-48CE-4FD1-DEDB-C0892054BE01";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube37_rotateZ";
	rename -uid "69B9D4DF-4511-D0B8-7F2C-9EBD2DEC94EE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube37_scaleX";
	rename -uid "26C9EEA3-4CD3-723A-EE30-32922A081DB0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube37_scaleY";
	rename -uid "AAAAE3BB-4F27-8B68-73BE-F38164D7A989";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube37_scaleZ";
	rename -uid "90685CFD-4473-5574-C23C-619208FBBE0F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube38_visibility";
	rename -uid "8A76731C-489A-C61A-19D0-D78E30000DE4";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube38_rotateX";
	rename -uid "FCC812FB-46BB-DBAC-550A-A5B2E63AD67C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube38_rotateY";
	rename -uid "8F26263B-40CE-41F6-0340-EFB4CFFD1122";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube38_rotateZ";
	rename -uid "55D5BB78-419C-C86C-7498-9195AEE35B51";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube38_scaleX";
	rename -uid "44895468-4E85-5C5C-81CC-8AAAE53B7637";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube38_scaleY";
	rename -uid "B9F033A0-4C99-7E8F-C777-98BAC0150D3A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube38_scaleZ";
	rename -uid "75FE5D4C-47F6-DF38-2032-9BA3B992AB33";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube39_visibility";
	rename -uid "23725F61-412B-9E46-2633-8C92CC7C92FC";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube39_rotateX";
	rename -uid "434D8F92-4F9F-EECB-BD1D-9EB296CE4DD8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube39_rotateY";
	rename -uid "AA83A2DC-427B-EF3F-CFC9-E380D314D693";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube39_rotateZ";
	rename -uid "A22541B9-4AFF-CE54-E71B-DB91AC50E044";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube39_scaleX";
	rename -uid "A032D5D1-46DC-9236-FFAE-869D928346F7";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube39_scaleY";
	rename -uid "31493541-4DEC-C576-EC07-398CEE4F1A5C";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube39_scaleZ";
	rename -uid "0B870A3A-448F-4627-889B-55AA06E5019A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube40_visibility";
	rename -uid "65C15183-4DCD-FC10-F6F0-1BBE55CE4546";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube40_rotateX";
	rename -uid "2F95BB87-4929-1DDC-755C-1BA040F79EF2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube40_rotateY";
	rename -uid "73955DA9-49A5-6257-FBA4-8ABED26404E1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube40_rotateZ";
	rename -uid "83097E98-472E-EE31-966E-65BCAB5B5E08";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube40_scaleX";
	rename -uid "B5156047-451F-35D3-299C-0285F811D229";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube40_scaleY";
	rename -uid "FD1739C7-4C1B-FAA0-A0CD-AB898EFC60C1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube40_scaleZ";
	rename -uid "DF9A494A-4161-3BC1-0C81-A4BA3D137449";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube41_visibility";
	rename -uid "921E1750-423E-5FBD-FFE2-D8A746483714";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube41_rotateX";
	rename -uid "AA3C62C6-464D-0EC0-C6F8-72997B18A0BE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube41_rotateY";
	rename -uid "68CB5451-4998-C0B0-6C72-6AB68F0BA1E2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube41_rotateZ";
	rename -uid "543F7D77-4BA8-E4C1-A189-DA8DD7662457";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube41_scaleX";
	rename -uid "2F471B57-4E43-6B4A-0819-98A6765F3068";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube41_scaleY";
	rename -uid "BC23203E-430A-77B0-ADF2-F588B4D14192";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube41_scaleZ";
	rename -uid "B483CFC3-4475-0180-B54B-0B9307530865";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube42_visibility";
	rename -uid "2A5E8ED8-4729-BD88-5881-A78FF097F915";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "pCube42_rotateX";
	rename -uid "A49A3C75-4F80-3471-83FF-45ADBE2D82F5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube42_rotateY";
	rename -uid "6D5DCD3D-4D57-882C-3899-258EABE6FE2B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "pCube42_rotateZ";
	rename -uid "5CEEFDF7-4F27-3457-4C42-63B8763BE1A4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "pCube42_scaleX";
	rename -uid "8D418577-4A73-2037-F7A2-4EB17E1F6ED5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube42_scaleY";
	rename -uid "0BB72284-4E8B-4DB4-4A30-CF80CBDFF96B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "pCube42_scaleZ";
	rename -uid "831B0BB1-43EC-E878-BF74-6AAE33DD75A8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTL -n "Skydome_l_translateX";
	rename -uid "19B7D319-44C3-95C7-938D-568EC51BFC48";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "Skydome_l_translateY";
	rename -uid "FDC0EE8B-432B-B547-C4F8-4AA9F1D4FFFA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "Skydome_l_translateZ";
	rename -uid "3F100D3F-47EF-30B1-450C-478470DAB8C5";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "Skydome_l_visibility";
	rename -uid "33104965-424A-4BB6-E741-5297E6ED5743";
	setAttr ".tan" 9;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
	setAttr ".kot[0]"  5;
createNode animCurveTA -n "Skydome_l_rotateX";
	rename -uid "D6EC93FC-432B-2CEB-B7A5-6C849BF23280";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "Skydome_l_rotateY";
	rename -uid "526B7DB5-41D5-F93A-D2C6-EFB99CCBADC8";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTA -n "Skydome_l_rotateZ";
	rename -uid "E8AF7102-4E2D-E684-C60C-76BFB0FBF4EE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTU -n "Skydome_l_scaleX";
	rename -uid "90DD7A62-4D38-0953-A35B-7087FB121240";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "Skydome_l_scaleY";
	rename -uid "85DC4A52-4D33-0414-EF37-4BBBAA356909";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
createNode animCurveTU -n "Skydome_l_scaleZ";
	rename -uid "53DFCE3A-4BD8-75A6-F876-47A6D9C03BEA";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 1;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 3 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 6 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
select -ne :defaultRenderingList1;
select -ne :lightList1;
select -ne :defaultTextureList1;
select -ne :standardSurface1;
	setAttr ".s" 0;
select -ne :initialShadingGroup;
	setAttr -s 42 ".dsm";
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultRenderGlobals;
	addAttr -ci true -h true -sn "dss" -ln "defaultSurfaceShader" -dt "string";
	setAttr ".ren" -type "string" "arnold";
	setAttr ".outf" 51;
	setAttr ".imfkey" -type "string" "exr";
	setAttr ".dss" -type "string" "lambert1";
select -ne :defaultResolution;
	setAttr ".w" 1024;
	setAttr ".h" 1024;
	setAttr ".pa" 1;
	setAttr ".dar" 1;
select -ne :defaultLightSet;
select -ne :defaultColorMgtGlobals;
	setAttr ".cfe" yes;
	setAttr ".cfp" -type "string" "<MAYA_RESOURCES>/OCIO-configs/Maya-legacy/config.ocio";
	setAttr ".vtn" -type "string" "sRGB gamma (legacy)";
	setAttr ".vn" -type "string" "sRGB gamma";
	setAttr ".dn" -type "string" "legacy";
	setAttr ".wsn" -type "string" "scene-linear Rec 709/sRGB";
	setAttr ".ovt" no;
	setAttr ".povt" no;
	setAttr ".otn" -type "string" "sRGB gamma (legacy)";
	setAttr ".potn" -type "string" "sRGB gamma (legacy)";
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :ikSystem;
	setAttr -s 4 ".sol";
connectAttr "Skydome_l_translateX.o" "Skydome_l.tx";
connectAttr "Skydome_l_translateY.o" "Skydome_l.ty";
connectAttr "Skydome_l_translateZ.o" "Skydome_l.tz";
connectAttr "Skydome_l_visibility.o" "Skydome_l.v";
connectAttr "Skydome_l_rotateX.o" "Skydome_l.rx";
connectAttr "Skydome_l_rotateY.o" "Skydome_l.ry";
connectAttr "Skydome_l_rotateZ.o" "Skydome_l.rz";
connectAttr "Skydome_l_scaleX.o" "Skydome_l.sx";
connectAttr "Skydome_l_scaleY.o" "Skydome_l.sy";
connectAttr "Skydome_l_scaleZ.o" "Skydome_l.sz";
connectAttr "pCube1_translateX.o" "pCube1.tx";
connectAttr "pCube1_translateY.o" "pCube1.ty";
connectAttr "pCube1_translateZ.o" "pCube1.tz";
connectAttr "pCube1_visibility.o" "pCube1.v";
connectAttr "pCube1_rotateX.o" "pCube1.rx";
connectAttr "pCube1_rotateY.o" "pCube1.ry";
connectAttr "pCube1_rotateZ.o" "pCube1.rz";
connectAttr "pCube1_scaleX.o" "pCube1.sx";
connectAttr "pCube1_scaleY.o" "pCube1.sy";
connectAttr "pCube1_scaleZ.o" "pCube1.sz";
connectAttr "pCube2_translateX.o" "pCube2.tx";
connectAttr "pCube2_translateY.o" "pCube2.ty";
connectAttr "pCube2_translateZ.o" "pCube2.tz";
connectAttr "pCube2_visibility.o" "pCube2.v";
connectAttr "pCube2_rotateX.o" "pCube2.rx";
connectAttr "pCube2_rotateY.o" "pCube2.ry";
connectAttr "pCube2_rotateZ.o" "pCube2.rz";
connectAttr "pCube2_scaleX.o" "pCube2.sx";
connectAttr "pCube2_scaleY.o" "pCube2.sy";
connectAttr "pCube2_scaleZ.o" "pCube2.sz";
connectAttr "pCube3_translateX.o" "pCube3.tx";
connectAttr "pCube3_translateY.o" "pCube3.ty";
connectAttr "pCube3_translateZ.o" "pCube3.tz";
connectAttr "pCube3_visibility.o" "pCube3.v";
connectAttr "pCube3_rotateX.o" "pCube3.rx";
connectAttr "pCube3_rotateY.o" "pCube3.ry";
connectAttr "pCube3_rotateZ.o" "pCube3.rz";
connectAttr "pCube3_scaleX.o" "pCube3.sx";
connectAttr "pCube3_scaleY.o" "pCube3.sy";
connectAttr "pCube3_scaleZ.o" "pCube3.sz";
connectAttr "pCube4_translateX.o" "pCube4.tx";
connectAttr "pCube4_translateY.o" "pCube4.ty";
connectAttr "pCube4_translateZ.o" "pCube4.tz";
connectAttr "pCube4_visibility.o" "pCube4.v";
connectAttr "pCube4_rotateX.o" "pCube4.rx";
connectAttr "pCube4_rotateY.o" "pCube4.ry";
connectAttr "pCube4_rotateZ.o" "pCube4.rz";
connectAttr "pCube4_scaleX.o" "pCube4.sx";
connectAttr "pCube4_scaleY.o" "pCube4.sy";
connectAttr "pCube4_scaleZ.o" "pCube4.sz";
connectAttr "pCube5_translateX.o" "pCube5.tx";
connectAttr "pCube5_translateY.o" "pCube5.ty";
connectAttr "pCube5_translateZ.o" "pCube5.tz";
connectAttr "pCube5_visibility.o" "pCube5.v";
connectAttr "pCube5_rotateX.o" "pCube5.rx";
connectAttr "pCube5_rotateY.o" "pCube5.ry";
connectAttr "pCube5_rotateZ.o" "pCube5.rz";
connectAttr "pCube5_scaleX.o" "pCube5.sx";
connectAttr "pCube5_scaleY.o" "pCube5.sy";
connectAttr "pCube5_scaleZ.o" "pCube5.sz";
connectAttr "pCube6_translateX.o" "pCube6.tx";
connectAttr "pCube6_translateY.o" "pCube6.ty";
connectAttr "pCube6_translateZ.o" "pCube6.tz";
connectAttr "pCube6_visibility.o" "pCube6.v";
connectAttr "pCube6_rotateX.o" "pCube6.rx";
connectAttr "pCube6_rotateY.o" "pCube6.ry";
connectAttr "pCube6_rotateZ.o" "pCube6.rz";
connectAttr "pCube6_scaleX.o" "pCube6.sx";
connectAttr "pCube6_scaleY.o" "pCube6.sy";
connectAttr "pCube6_scaleZ.o" "pCube6.sz";
connectAttr "pCube7_translateX.o" "pCube7.tx";
connectAttr "pCube7_translateY.o" "pCube7.ty";
connectAttr "pCube7_translateZ.o" "pCube7.tz";
connectAttr "pCube7_visibility.o" "pCube7.v";
connectAttr "pCube7_rotateX.o" "pCube7.rx";
connectAttr "pCube7_rotateY.o" "pCube7.ry";
connectAttr "pCube7_rotateZ.o" "pCube7.rz";
connectAttr "pCube7_scaleX.o" "pCube7.sx";
connectAttr "pCube7_scaleY.o" "pCube7.sy";
connectAttr "pCube7_scaleZ.o" "pCube7.sz";
connectAttr "pCube8_translateX.o" "pCube8.tx";
connectAttr "pCube8_translateY.o" "pCube8.ty";
connectAttr "pCube8_translateZ.o" "pCube8.tz";
connectAttr "pCube8_visibility.o" "pCube8.v";
connectAttr "pCube8_rotateX.o" "pCube8.rx";
connectAttr "pCube8_rotateY.o" "pCube8.ry";
connectAttr "pCube8_rotateZ.o" "pCube8.rz";
connectAttr "pCube8_scaleX.o" "pCube8.sx";
connectAttr "pCube8_scaleY.o" "pCube8.sy";
connectAttr "pCube8_scaleZ.o" "pCube8.sz";
connectAttr "pCube9_translateX.o" "pCube9.tx";
connectAttr "pCube9_translateY.o" "pCube9.ty";
connectAttr "pCube9_translateZ.o" "pCube9.tz";
connectAttr "pCube9_visibility.o" "pCube9.v";
connectAttr "pCube9_rotateX.o" "pCube9.rx";
connectAttr "pCube9_rotateY.o" "pCube9.ry";
connectAttr "pCube9_rotateZ.o" "pCube9.rz";
connectAttr "pCube9_scaleX.o" "pCube9.sx";
connectAttr "pCube9_scaleY.o" "pCube9.sy";
connectAttr "pCube9_scaleZ.o" "pCube9.sz";
connectAttr "pCube10_translateX.o" "pCube10.tx";
connectAttr "pCube10_translateY.o" "pCube10.ty";
connectAttr "pCube10_translateZ.o" "pCube10.tz";
connectAttr "pCube10_visibility.o" "pCube10.v";
connectAttr "pCube10_rotateX.o" "pCube10.rx";
connectAttr "pCube10_rotateY.o" "pCube10.ry";
connectAttr "pCube10_rotateZ.o" "pCube10.rz";
connectAttr "pCube10_scaleX.o" "pCube10.sx";
connectAttr "pCube10_scaleY.o" "pCube10.sy";
connectAttr "pCube10_scaleZ.o" "pCube10.sz";
connectAttr "pCube11_translateX.o" "pCube11.tx";
connectAttr "pCube11_translateY.o" "pCube11.ty";
connectAttr "pCube11_translateZ.o" "pCube11.tz";
connectAttr "pCube11_visibility.o" "pCube11.v";
connectAttr "pCube11_rotateX.o" "pCube11.rx";
connectAttr "pCube11_rotateY.o" "pCube11.ry";
connectAttr "pCube11_rotateZ.o" "pCube11.rz";
connectAttr "pCube11_scaleX.o" "pCube11.sx";
connectAttr "pCube11_scaleY.o" "pCube11.sy";
connectAttr "pCube11_scaleZ.o" "pCube11.sz";
connectAttr "pCube12_translateX.o" "pCube12.tx";
connectAttr "pCube12_translateY.o" "pCube12.ty";
connectAttr "pCube12_translateZ.o" "pCube12.tz";
connectAttr "pCube12_visibility.o" "pCube12.v";
connectAttr "pCube12_rotateX.o" "pCube12.rx";
connectAttr "pCube12_rotateY.o" "pCube12.ry";
connectAttr "pCube12_rotateZ.o" "pCube12.rz";
connectAttr "pCube12_scaleX.o" "pCube12.sx";
connectAttr "pCube12_scaleY.o" "pCube12.sy";
connectAttr "pCube12_scaleZ.o" "pCube12.sz";
connectAttr "pCube13_translateX.o" "pCube13.tx";
connectAttr "pCube13_translateY.o" "pCube13.ty";
connectAttr "pCube13_translateZ.o" "pCube13.tz";
connectAttr "pCube13_visibility.o" "pCube13.v";
connectAttr "pCube13_rotateX.o" "pCube13.rx";
connectAttr "pCube13_rotateY.o" "pCube13.ry";
connectAttr "pCube13_rotateZ.o" "pCube13.rz";
connectAttr "pCube13_scaleX.o" "pCube13.sx";
connectAttr "pCube13_scaleY.o" "pCube13.sy";
connectAttr "pCube13_scaleZ.o" "pCube13.sz";
connectAttr "pCube14_translateX.o" "pCube14.tx";
connectAttr "pCube14_translateY.o" "pCube14.ty";
connectAttr "pCube14_translateZ.o" "pCube14.tz";
connectAttr "pCube14_visibility.o" "pCube14.v";
connectAttr "pCube14_rotateX.o" "pCube14.rx";
connectAttr "pCube14_rotateY.o" "pCube14.ry";
connectAttr "pCube14_rotateZ.o" "pCube14.rz";
connectAttr "pCube14_scaleX.o" "pCube14.sx";
connectAttr "pCube14_scaleY.o" "pCube14.sy";
connectAttr "pCube14_scaleZ.o" "pCube14.sz";
connectAttr "pCube15_translateX.o" "pCube15.tx";
connectAttr "pCube15_translateY.o" "pCube15.ty";
connectAttr "pCube15_translateZ.o" "pCube15.tz";
connectAttr "pCube15_visibility.o" "pCube15.v";
connectAttr "pCube15_rotateX.o" "pCube15.rx";
connectAttr "pCube15_rotateY.o" "pCube15.ry";
connectAttr "pCube15_rotateZ.o" "pCube15.rz";
connectAttr "pCube15_scaleX.o" "pCube15.sx";
connectAttr "pCube15_scaleY.o" "pCube15.sy";
connectAttr "pCube15_scaleZ.o" "pCube15.sz";
connectAttr "pCube16_translateX.o" "pCube16.tx";
connectAttr "pCube16_translateY.o" "pCube16.ty";
connectAttr "pCube16_translateZ.o" "pCube16.tz";
connectAttr "pCube16_visibility.o" "pCube16.v";
connectAttr "pCube16_rotateX.o" "pCube16.rx";
connectAttr "pCube16_rotateY.o" "pCube16.ry";
connectAttr "pCube16_rotateZ.o" "pCube16.rz";
connectAttr "pCube16_scaleX.o" "pCube16.sx";
connectAttr "pCube16_scaleY.o" "pCube16.sy";
connectAttr "pCube16_scaleZ.o" "pCube16.sz";
connectAttr "pCube17_translateX.o" "pCube17.tx";
connectAttr "pCube17_translateY.o" "pCube17.ty";
connectAttr "pCube17_translateZ.o" "pCube17.tz";
connectAttr "pCube17_visibility.o" "pCube17.v";
connectAttr "pCube17_rotateX.o" "pCube17.rx";
connectAttr "pCube17_rotateY.o" "pCube17.ry";
connectAttr "pCube17_rotateZ.o" "pCube17.rz";
connectAttr "pCube17_scaleX.o" "pCube17.sx";
connectAttr "pCube17_scaleY.o" "pCube17.sy";
connectAttr "pCube17_scaleZ.o" "pCube17.sz";
connectAttr "pCube18_translateX.o" "pCube18.tx";
connectAttr "pCube18_translateY.o" "pCube18.ty";
connectAttr "pCube18_translateZ.o" "pCube18.tz";
connectAttr "pCube18_visibility.o" "pCube18.v";
connectAttr "pCube18_rotateX.o" "pCube18.rx";
connectAttr "pCube18_rotateY.o" "pCube18.ry";
connectAttr "pCube18_rotateZ.o" "pCube18.rz";
connectAttr "pCube18_scaleX.o" "pCube18.sx";
connectAttr "pCube18_scaleY.o" "pCube18.sy";
connectAttr "pCube18_scaleZ.o" "pCube18.sz";
connectAttr "pCube19_translateX.o" "pCube19.tx";
connectAttr "pCube19_translateY.o" "pCube19.ty";
connectAttr "pCube19_translateZ.o" "pCube19.tz";
connectAttr "pCube19_visibility.o" "pCube19.v";
connectAttr "pCube19_rotateX.o" "pCube19.rx";
connectAttr "pCube19_rotateY.o" "pCube19.ry";
connectAttr "pCube19_rotateZ.o" "pCube19.rz";
connectAttr "pCube19_scaleX.o" "pCube19.sx";
connectAttr "pCube19_scaleY.o" "pCube19.sy";
connectAttr "pCube19_scaleZ.o" "pCube19.sz";
connectAttr "pCube20_translateX.o" "pCube20.tx";
connectAttr "pCube20_translateY.o" "pCube20.ty";
connectAttr "pCube20_translateZ.o" "pCube20.tz";
connectAttr "pCube20_visibility.o" "pCube20.v";
connectAttr "pCube20_rotateX.o" "pCube20.rx";
connectAttr "pCube20_rotateY.o" "pCube20.ry";
connectAttr "pCube20_rotateZ.o" "pCube20.rz";
connectAttr "pCube20_scaleX.o" "pCube20.sx";
connectAttr "pCube20_scaleY.o" "pCube20.sy";
connectAttr "pCube20_scaleZ.o" "pCube20.sz";
connectAttr "pCube21_translateX.o" "pCube21.tx";
connectAttr "pCube21_translateY.o" "pCube21.ty";
connectAttr "pCube21_translateZ.o" "pCube21.tz";
connectAttr "pCube21_visibility.o" "pCube21.v";
connectAttr "pCube21_rotateX.o" "pCube21.rx";
connectAttr "pCube21_rotateY.o" "pCube21.ry";
connectAttr "pCube21_rotateZ.o" "pCube21.rz";
connectAttr "pCube21_scaleX.o" "pCube21.sx";
connectAttr "pCube21_scaleY.o" "pCube21.sy";
connectAttr "pCube21_scaleZ.o" "pCube21.sz";
connectAttr "pCube22_translateX.o" "pCube22.tx";
connectAttr "pCube22_translateY.o" "pCube22.ty";
connectAttr "pCube22_translateZ.o" "pCube22.tz";
connectAttr "pCube22_visibility.o" "pCube22.v";
connectAttr "pCube22_rotateX.o" "pCube22.rx";
connectAttr "pCube22_rotateY.o" "pCube22.ry";
connectAttr "pCube22_rotateZ.o" "pCube22.rz";
connectAttr "pCube22_scaleX.o" "pCube22.sx";
connectAttr "pCube22_scaleY.o" "pCube22.sy";
connectAttr "pCube22_scaleZ.o" "pCube22.sz";
connectAttr "pCube23_translateX.o" "pCube23.tx";
connectAttr "pCube23_translateY.o" "pCube23.ty";
connectAttr "pCube23_translateZ.o" "pCube23.tz";
connectAttr "pCube23_visibility.o" "pCube23.v";
connectAttr "pCube23_rotateX.o" "pCube23.rx";
connectAttr "pCube23_rotateY.o" "pCube23.ry";
connectAttr "pCube23_rotateZ.o" "pCube23.rz";
connectAttr "pCube23_scaleX.o" "pCube23.sx";
connectAttr "pCube23_scaleY.o" "pCube23.sy";
connectAttr "pCube23_scaleZ.o" "pCube23.sz";
connectAttr "pCube24_translateX.o" "pCube24.tx";
connectAttr "pCube24_translateY.o" "pCube24.ty";
connectAttr "pCube24_translateZ.o" "pCube24.tz";
connectAttr "pCube24_visibility.o" "pCube24.v";
connectAttr "pCube24_rotateX.o" "pCube24.rx";
connectAttr "pCube24_rotateY.o" "pCube24.ry";
connectAttr "pCube24_rotateZ.o" "pCube24.rz";
connectAttr "pCube24_scaleX.o" "pCube24.sx";
connectAttr "pCube24_scaleY.o" "pCube24.sy";
connectAttr "pCube24_scaleZ.o" "pCube24.sz";
connectAttr "pCube25_translateX.o" "pCube25.tx";
connectAttr "pCube25_translateY.o" "pCube25.ty";
connectAttr "pCube25_translateZ.o" "pCube25.tz";
connectAttr "pCube25_visibility.o" "pCube25.v";
connectAttr "pCube25_rotateX.o" "pCube25.rx";
connectAttr "pCube25_rotateY.o" "pCube25.ry";
connectAttr "pCube25_rotateZ.o" "pCube25.rz";
connectAttr "pCube25_scaleX.o" "pCube25.sx";
connectAttr "pCube25_scaleY.o" "pCube25.sy";
connectAttr "pCube25_scaleZ.o" "pCube25.sz";
connectAttr "pCube26_translateX.o" "pCube26.tx";
connectAttr "pCube26_translateY.o" "pCube26.ty";
connectAttr "pCube26_translateZ.o" "pCube26.tz";
connectAttr "pCube26_visibility.o" "pCube26.v";
connectAttr "pCube26_rotateX.o" "pCube26.rx";
connectAttr "pCube26_rotateY.o" "pCube26.ry";
connectAttr "pCube26_rotateZ.o" "pCube26.rz";
connectAttr "pCube26_scaleX.o" "pCube26.sx";
connectAttr "pCube26_scaleY.o" "pCube26.sy";
connectAttr "pCube26_scaleZ.o" "pCube26.sz";
connectAttr "pCube27_translateX.o" "pCube27.tx";
connectAttr "pCube27_translateY.o" "pCube27.ty";
connectAttr "pCube27_translateZ.o" "pCube27.tz";
connectAttr "pCube27_visibility.o" "pCube27.v";
connectAttr "pCube27_rotateX.o" "pCube27.rx";
connectAttr "pCube27_rotateY.o" "pCube27.ry";
connectAttr "pCube27_rotateZ.o" "pCube27.rz";
connectAttr "pCube27_scaleX.o" "pCube27.sx";
connectAttr "pCube27_scaleY.o" "pCube27.sy";
connectAttr "pCube27_scaleZ.o" "pCube27.sz";
connectAttr "pCube28_translateX.o" "pCube28.tx";
connectAttr "pCube28_translateY.o" "pCube28.ty";
connectAttr "pCube28_translateZ.o" "pCube28.tz";
connectAttr "pCube28_visibility.o" "pCube28.v";
connectAttr "pCube28_rotateX.o" "pCube28.rx";
connectAttr "pCube28_rotateY.o" "pCube28.ry";
connectAttr "pCube28_rotateZ.o" "pCube28.rz";
connectAttr "pCube28_scaleX.o" "pCube28.sx";
connectAttr "pCube28_scaleY.o" "pCube28.sy";
connectAttr "pCube28_scaleZ.o" "pCube28.sz";
connectAttr "pCube29_translateX.o" "pCube29.tx";
connectAttr "pCube29_translateY.o" "pCube29.ty";
connectAttr "pCube29_translateZ.o" "pCube29.tz";
connectAttr "pCube29_visibility.o" "pCube29.v";
connectAttr "pCube29_rotateX.o" "pCube29.rx";
connectAttr "pCube29_rotateY.o" "pCube29.ry";
connectAttr "pCube29_rotateZ.o" "pCube29.rz";
connectAttr "pCube29_scaleX.o" "pCube29.sx";
connectAttr "pCube29_scaleY.o" "pCube29.sy";
connectAttr "pCube29_scaleZ.o" "pCube29.sz";
connectAttr "pCube30_translateX.o" "pCube30.tx";
connectAttr "pCube30_translateY.o" "pCube30.ty";
connectAttr "pCube30_translateZ.o" "pCube30.tz";
connectAttr "pCube30_visibility.o" "pCube30.v";
connectAttr "pCube30_rotateX.o" "pCube30.rx";
connectAttr "pCube30_rotateY.o" "pCube30.ry";
connectAttr "pCube30_rotateZ.o" "pCube30.rz";
connectAttr "pCube30_scaleX.o" "pCube30.sx";
connectAttr "pCube30_scaleY.o" "pCube30.sy";
connectAttr "pCube30_scaleZ.o" "pCube30.sz";
connectAttr "pCube31_translateX.o" "pCube31.tx";
connectAttr "pCube31_translateY.o" "pCube31.ty";
connectAttr "pCube31_translateZ.o" "pCube31.tz";
connectAttr "pCube31_visibility.o" "pCube31.v";
connectAttr "pCube31_rotateX.o" "pCube31.rx";
connectAttr "pCube31_rotateY.o" "pCube31.ry";
connectAttr "pCube31_rotateZ.o" "pCube31.rz";
connectAttr "pCube31_scaleX.o" "pCube31.sx";
connectAttr "pCube31_scaleY.o" "pCube31.sy";
connectAttr "pCube31_scaleZ.o" "pCube31.sz";
connectAttr "pCube32_translateX.o" "pCube32.tx";
connectAttr "pCube32_translateY.o" "pCube32.ty";
connectAttr "pCube32_translateZ.o" "pCube32.tz";
connectAttr "pCube32_visibility.o" "pCube32.v";
connectAttr "pCube32_rotateX.o" "pCube32.rx";
connectAttr "pCube32_rotateY.o" "pCube32.ry";
connectAttr "pCube32_rotateZ.o" "pCube32.rz";
connectAttr "pCube32_scaleX.o" "pCube32.sx";
connectAttr "pCube32_scaleY.o" "pCube32.sy";
connectAttr "pCube32_scaleZ.o" "pCube32.sz";
connectAttr "pCube33_translateX.o" "pCube33.tx";
connectAttr "pCube33_translateY.o" "pCube33.ty";
connectAttr "pCube33_translateZ.o" "pCube33.tz";
connectAttr "pCube33_visibility.o" "pCube33.v";
connectAttr "pCube33_rotateX.o" "pCube33.rx";
connectAttr "pCube33_rotateY.o" "pCube33.ry";
connectAttr "pCube33_rotateZ.o" "pCube33.rz";
connectAttr "pCube33_scaleX.o" "pCube33.sx";
connectAttr "pCube33_scaleY.o" "pCube33.sy";
connectAttr "pCube33_scaleZ.o" "pCube33.sz";
connectAttr "pCube34_translateX.o" "pCube34.tx";
connectAttr "pCube34_translateY.o" "pCube34.ty";
connectAttr "pCube34_translateZ.o" "pCube34.tz";
connectAttr "pCube34_visibility.o" "pCube34.v";
connectAttr "pCube34_rotateX.o" "pCube34.rx";
connectAttr "pCube34_rotateY.o" "pCube34.ry";
connectAttr "pCube34_rotateZ.o" "pCube34.rz";
connectAttr "pCube34_scaleX.o" "pCube34.sx";
connectAttr "pCube34_scaleY.o" "pCube34.sy";
connectAttr "pCube34_scaleZ.o" "pCube34.sz";
connectAttr "pCube35_translateX.o" "pCube35.tx";
connectAttr "pCube35_translateY.o" "pCube35.ty";
connectAttr "pCube35_translateZ.o" "pCube35.tz";
connectAttr "pCube35_visibility.o" "pCube35.v";
connectAttr "pCube35_rotateX.o" "pCube35.rx";
connectAttr "pCube35_rotateY.o" "pCube35.ry";
connectAttr "pCube35_rotateZ.o" "pCube35.rz";
connectAttr "pCube35_scaleX.o" "pCube35.sx";
connectAttr "pCube35_scaleY.o" "pCube35.sy";
connectAttr "pCube35_scaleZ.o" "pCube35.sz";
connectAttr "pCube36_translateX.o" "pCube36.tx";
connectAttr "pCube36_translateY.o" "pCube36.ty";
connectAttr "pCube36_translateZ.o" "pCube36.tz";
connectAttr "pCube36_visibility.o" "pCube36.v";
connectAttr "pCube36_rotateX.o" "pCube36.rx";
connectAttr "pCube36_rotateY.o" "pCube36.ry";
connectAttr "pCube36_rotateZ.o" "pCube36.rz";
connectAttr "pCube36_scaleX.o" "pCube36.sx";
connectAttr "pCube36_scaleY.o" "pCube36.sy";
connectAttr "pCube36_scaleZ.o" "pCube36.sz";
connectAttr "pCube37_translateX.o" "pCube37.tx";
connectAttr "pCube37_translateY.o" "pCube37.ty";
connectAttr "pCube37_translateZ.o" "pCube37.tz";
connectAttr "pCube37_visibility.o" "pCube37.v";
connectAttr "pCube37_rotateX.o" "pCube37.rx";
connectAttr "pCube37_rotateY.o" "pCube37.ry";
connectAttr "pCube37_rotateZ.o" "pCube37.rz";
connectAttr "pCube37_scaleX.o" "pCube37.sx";
connectAttr "pCube37_scaleY.o" "pCube37.sy";
connectAttr "pCube37_scaleZ.o" "pCube37.sz";
connectAttr "pCube38_translateX.o" "pCube38.tx";
connectAttr "pCube38_translateY.o" "pCube38.ty";
connectAttr "pCube38_translateZ.o" "pCube38.tz";
connectAttr "pCube38_visibility.o" "pCube38.v";
connectAttr "pCube38_rotateX.o" "pCube38.rx";
connectAttr "pCube38_rotateY.o" "pCube38.ry";
connectAttr "pCube38_rotateZ.o" "pCube38.rz";
connectAttr "pCube38_scaleX.o" "pCube38.sx";
connectAttr "pCube38_scaleY.o" "pCube38.sy";
connectAttr "pCube38_scaleZ.o" "pCube38.sz";
connectAttr "pCube39_translateX.o" "pCube39.tx";
connectAttr "pCube39_translateY.o" "pCube39.ty";
connectAttr "pCube39_translateZ.o" "pCube39.tz";
connectAttr "pCube39_visibility.o" "pCube39.v";
connectAttr "pCube39_rotateX.o" "pCube39.rx";
connectAttr "pCube39_rotateY.o" "pCube39.ry";
connectAttr "pCube39_rotateZ.o" "pCube39.rz";
connectAttr "pCube39_scaleX.o" "pCube39.sx";
connectAttr "pCube39_scaleY.o" "pCube39.sy";
connectAttr "pCube39_scaleZ.o" "pCube39.sz";
connectAttr "pCube40_translateX.o" "pCube40.tx";
connectAttr "pCube40_translateY.o" "pCube40.ty";
connectAttr "pCube40_translateZ.o" "pCube40.tz";
connectAttr "pCube40_visibility.o" "pCube40.v";
connectAttr "pCube40_rotateX.o" "pCube40.rx";
connectAttr "pCube40_rotateY.o" "pCube40.ry";
connectAttr "pCube40_rotateZ.o" "pCube40.rz";
connectAttr "pCube40_scaleX.o" "pCube40.sx";
connectAttr "pCube40_scaleY.o" "pCube40.sy";
connectAttr "pCube40_scaleZ.o" "pCube40.sz";
connectAttr "pCube41_translateX.o" "pCube41.tx";
connectAttr "pCube41_translateY.o" "pCube41.ty";
connectAttr "pCube41_translateZ.o" "pCube41.tz";
connectAttr "pCube41_visibility.o" "pCube41.v";
connectAttr "pCube41_rotateX.o" "pCube41.rx";
connectAttr "pCube41_rotateY.o" "pCube41.ry";
connectAttr "pCube41_rotateZ.o" "pCube41.rz";
connectAttr "pCube41_scaleX.o" "pCube41.sx";
connectAttr "pCube41_scaleY.o" "pCube41.sy";
connectAttr "pCube41_scaleZ.o" "pCube41.sz";
connectAttr "pCube42_translateX.o" "pCube42.tx";
connectAttr "pCube42_translateY.o" "pCube42.ty";
connectAttr "pCube42_translateZ.o" "pCube42.tz";
connectAttr "pCube42_visibility.o" "pCube42.v";
connectAttr "pCube42_rotateX.o" "pCube42.rx";
connectAttr "pCube42_rotateY.o" "pCube42.ry";
connectAttr "pCube42_rotateZ.o" "pCube42.rz";
connectAttr "pCube42_scaleX.o" "pCube42.sx";
connectAttr "pCube42_scaleY.o" "pCube42.sy";
connectAttr "pCube42_scaleZ.o" "pCube42.sz";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr ":defaultColorMgtGlobals.cme" "groundplane.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "groundplane.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "groundplane.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "groundplane.ws";
connectAttr "place2dTexture1.c" "groundplane.c";
connectAttr "place2dTexture1.tf" "groundplane.tf";
connectAttr "place2dTexture1.rf" "groundplane.rf";
connectAttr "place2dTexture1.mu" "groundplane.mu";
connectAttr "place2dTexture1.mv" "groundplane.mv";
connectAttr "place2dTexture1.s" "groundplane.s";
connectAttr "place2dTexture1.wu" "groundplane.wu";
connectAttr "place2dTexture1.wv" "groundplane.wv";
connectAttr "place2dTexture1.re" "groundplane.re";
connectAttr "place2dTexture1.of" "groundplane.of";
connectAttr "place2dTexture1.r" "groundplane.ro";
connectAttr "place2dTexture1.n" "groundplane.n";
connectAttr "place2dTexture1.vt1" "groundplane.vt1";
connectAttr "place2dTexture1.vt2" "groundplane.vt2";
connectAttr "place2dTexture1.vt3" "groundplane.vt3";
connectAttr "place2dTexture1.vc1" "groundplane.vc1";
connectAttr "place2dTexture1.o" "groundplane.uv";
connectAttr "place2dTexture1.ofs" "groundplane.fs";
connectAttr ":defaultArnoldDisplayDriver.msg" ":defaultArnoldRenderOptions.drivers"
		 -na;
connectAttr ":defaultArnoldFilter.msg" ":defaultArnoldRenderOptions.filt";
connectAttr ":defaultArnoldDriver.msg" ":defaultArnoldRenderOptions.drvr";
connectAttr "groundplane.oc" "groundplane_shader.base_color";
connectAttr "groundplane_shader.out" "aiStandardSurface1SG.ss";
connectAttr "groundplane_GeoShape.iog" "aiStandardSurface1SG.dsm" -na;
connectAttr "aiStandardSurface1SG.msg" "materialInfo2.sg";
connectAttr "groundplane_shader.msg" "materialInfo2.m";
connectAttr "groundplane_shader.msg" "materialInfo2.t" -na;
connectAttr "groundplane.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[0].dn"
		;
connectAttr "aiStandardSurface1SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[1].dn"
		;
connectAttr "groundplane_shader.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[2].dn"
		;
connectAttr "place2dTexture1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[3].dn"
		;
connectAttr "aiStandardSurface1SG.pa" ":renderPartition.st" -na;
connectAttr "groundplane_shader.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "Skydome_lShape.ltd" ":lightList1.l" -na;
connectAttr "groundplane.msg" ":defaultTextureList1.tx" -na;
connectAttr "pCubeShape1.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape2.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape3.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape4.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape5.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape6.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape7.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape8.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape9.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape10.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape11.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape12.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape13.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape14.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape15.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape16.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape17.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape18.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape19.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape20.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape21.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape22.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape23.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape24.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape25.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape26.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape27.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape28.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape29.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape30.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape31.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape32.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape33.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape34.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape35.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape36.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape37.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape38.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape39.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape40.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape41.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape42.iog" ":initialShadingGroup.dsm" -na;
connectAttr "Skydome_l.iog" ":defaultLightSet.dsm" -na;
// End of 1DAE2_RickAstley_Assignment1.000.ma
