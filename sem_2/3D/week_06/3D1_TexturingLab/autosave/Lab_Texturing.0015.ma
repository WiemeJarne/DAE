//Maya ASCII 2022 scene
//Name: Lab_Texturing.0015.ma
//Last modified: Fri, Mar 25, 2022 11:10:57 AM
//Codeset: 1252
requires maya "2022";
requires "stereoCamera" "10.0";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" -nodeType "aiSkyDomeLight"
		 -nodeType "aiAmbientOcclusion" -nodeType "aiStandardSurface" "mtoa" "4.2.1";
requires "stereoCamera" "10.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "exportedFrom" "C:/Users/Jarne/Documents/DAE/sem_2/3D/week_06/3D1_TexturingLab/Lab_Texturing.ma";
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202102181415-29bfc1879c";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19044)";
fileInfo "UUID" "C81A8713-4DAD-04AC-8BB9-03855E8C9242";
fileInfo "license" "education";
createNode transform -s -n "persp";
	rename -uid "DB7CFA40-4A03-289C-89C1-A79DBD07BBBA";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -60.333331426373029 201.20949210188402 222.93534535012662 ;
	setAttr ".r" -type "double3" -35.738352717127185 -1090.6000000003237 -1.213414500335167e-15 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "12DBCC36-4319-2405-1C40-2094631A0C59";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 164.98290252261174;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" -55.272205146488332 167.56516269793144 2.5791928708034995 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "7AE56991-41DA-6FBB-B959-A893FF741C1F";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 1000.1 0 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "736E08D7-4FDE-B92E-09C1-F5921F9560A4";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 220.49250512538336;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "9059F9B8-4D8E-A9BF-36F6-9BAD09933965";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 47.594081366891132 62.703261993878755 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "1ACEF960-4BA4-CD62-DBEB-24989CB89CFF";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 270.89878664107584;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "EA2A6B28-4676-EF1E-0462-9C95798E2BDF";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 0 0 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "63CFE748-468B-883B-1DB5-409D89794A4E";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 221.28507071679417;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "groundplane_Geo";
	rename -uid "93B082F4-43D7-BCB7-EB4F-ADB89626E2DC";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 7.1054273576010019e-15 0 0 ;
createNode mesh -n "groundplane_GeoShape" -p "groundplane_Geo";
	rename -uid "F94F96C3-4BFE-14CD-833E-D089B2BBAF00";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.49999998509883881 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 10 ".uvst[0].uvsp[0:9]" -type "float2" 0.99502838 0.99502838
		 0.0049716234 0.99502838 0.0049716234 0.0049715936 0.99502838 0.0049715936 0.99502838
		 0.5 0.0049716234 0.5 0.5 0.99502838 0.5 0.5 0.5 0.0049715936 0.5 0.0049715936;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr -s 2 ".clst";
	setAttr ".clst[0].clsn" -type "string" "SculptFreezeColorTemp";
	setAttr ".clst[1].clsn" -type "string" "SculptMaskColorTemp";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 9 ".pt[0:8]" -type "float3"  0 0.060856722 -91.829712 
		0 0.060856722 -91.829712 0 0.060856722 -91.829712 0 0.060856722 -91.829712 0 0.060856722 
		-91.829712 0 0.060856722 -91.829712 -7.1054274e-15 0.060856722 -91.829712 -7.1054274e-15 
		0.060856722 -91.829712 -7.1054274e-15 0.060856722 -91.829712;
	setAttr -s 9 ".vt[0:8]"  100 -0.060864076 -8.17028809 -100 -0.060864076 -8.17028809
		 100 -0.060864076 191.82971191 -100 -0.060864076 191.82971191 100 -0.060849369 91.82971191
		 -100 -0.060849369 91.82971191 -1.8277673e-13 -0.060849369 -8.17028809 7.1054274e-15 -0.060849369 91.82971191
		 1.9698758e-13 -0.060849369 191.82971191;
	setAttr -s 12 ".ed[0:11]"  0 6 0 0 4 0 1 5 0 2 8 0 4 2 0 5 3 0 4 7 0
		 6 1 0 7 5 0 8 3 0 6 7 0 7 8 0;
	setAttr -s 4 -ch 16 ".fc[0:3]" -type "polyFaces" 
		f 4 7 2 -9 -11
		mu 0 4 6 1 5 7
		f 4 5 -10 -12 8
		mu 0 4 5 2 9 7
		f 4 0 10 -7 -2
		mu 0 4 0 6 7 4
		f 4 -4 -5 6 11
		mu 0 4 8 3 4 7;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 5 
		4 0 
		5 0 
		6 0 
		7 0 
		8 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "amp_geo1";
	rename -uid "E239D12C-4D95-5BE7-99D2-D2A3BD30CC9D";
	setAttr ".rp" -type "double3" -5.5961990356445312 55.812780499458313 84.454109191894531 ;
	setAttr ".sp" -type "double3" -5.5961990356445312 55.812780499458313 84.454109191894531 ;
createNode transform -n "polySurface1" -p "amp_geo1";
	rename -uid "C9889CFD-4C3E-8575-00D6-BBB03119E90D";
	setAttr ".t" -type "double3" 47.442124732157282 0 -83.962929016403535 ;
	setAttr ".rp" -type "double3" -84.511421203613281 56.864182472229004 86.542121887207031 ;
	setAttr ".sp" -type "double3" -84.511421203613281 56.864182472229004 86.542121887207031 ;
createNode transform -n "transform1" -p "polySurface1";
	rename -uid "163E966B-42BC-EB3C-AEAD-C1BB8E3DC011";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape2" -p "transform1";
	rename -uid "D72D4D9B-4790-1090-FD0F-F19018063480";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:4]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.025982849 0.47555804
		 0.025982849 0.02222901 0.39073053 0.02222901 0.39073053 0.47555804 0.62208951 0.02222901
		 0.62208951 0.47555804 0.98683715 0.02222901 0.98683715 0.47555804 0.56341791 0.72142935
		 0.11009486 0.72142935 0.11009486 0.49013409 0.56341791 0.49013409 0.98683715 0.70669937
		 0.62208951 0.70669937;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".vt[0:7]"  -129.11201477 112.2963028 114.82480621 -129.11201477 1.43205452 114.82480621
		 -39.91082764 112.29631042 114.82479095 -39.91082764 1.43205452 114.82479095 -39.91083145 112.2963028 58.25943756
		 -39.91083145 1.43205452 58.25943756 -129.11201477 112.29631042 58.25943756 -129.11201477 1.43205452 58.25943756;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 5 -ch 20 ".fc[0:4]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 2 3
		f 4 1 7 -3 -7
		mu 0 4 3 2 4 5
		f 4 2 9 -4 -9
		mu 0 4 5 4 6 7
		f 4 3 11 -1 -11
		mu 0 4 8 9 10 11
		f 4 10 4 6 8
		mu 0 4 7 12 13 5;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface2" -p "amp_geo1";
	rename -uid "4C224849-4A63-114F-3886-918B2AD5CC1C";
	setAttr ".t" -type "double3" 18.202908675032333 0 -83.962929016403535 ;
	setAttr ".rp" -type "double3" 29.725194931030273 27.523674130439758 82.277835845947266 ;
	setAttr ".sp" -type "double3" 29.725194931030273 27.523674130439758 82.277835845947266 ;
createNode transform -n "transform2" -p "|amp_geo1|polySurface2";
	rename -uid "C80DAF8D-4774-3CA7-31A2-AAB1D4395814";
	setAttr ".v" no;
createNode mesh -n "polySurfaceShape3" -p "transform2";
	rename -uid "044A7B33-43B8-3978-C4B7-0083A406908E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:44]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 56 ".uvst[0].uvsp[0:55]" -type "float2" 0.71366179 0.94276059
		 0.56308657 0.94212902 0.5637182 0.79157811 0.7142328 0.79221791 0.067448996 0.78976238
		 0.21798921 0.78976238 0.21798921 0.94030273 0.067448996 0.94030273 0.5637182 0.79157811
		 0.7142328 0.79221791 0.71366179 0.94276059 0.56308663 0.94212902 0.94893253 0.94270146
		 0.79838502 0.94270146 0.79838502 0.79215878 0.94893253 0.79215878 0.48041052 0.94214135
		 0.32986552 0.94214135 0.32986552 0.79159498 0.48041052 0.79159498 0.75553775 0.9844147
		 0.52121282 0.98376524 0.55320537 0.95223689 0.72378111 0.9526335 0.52187788 0.74949908
		 0.55360568 0.78169471 0.75607073 0.75015175 0.724105 0.78209651 0.025592171 0.74790537
		 0.25984633 0.74790537 0.22798637 0.77976531 0.057451881 0.77976531 0.25984633 0.98215961
		 0.22798637 0.95029998 0.025592171 0.98215961 0.057451881 0.95029998 0.52187788 0.74949908
		 0.75607061 0.75015175 0.72410488 0.78209651 0.55360568 0.78169471 0.75553775 0.9844147
		 0.72378111 0.9526335 0.52121282 0.98376524 0.55320537 0.95223689 0.99078882 0.98408586
		 0.78838933 0.95269424 0.95892763 0.95269424 0.78838933 0.78216159 0.99078882 0.74982655
		 0.95892763 0.78216159 0.28800815 0.98408586 0.31986809 0.95212775 0.49040598 0.95212775
		 0.28800815 0.74982655 0.31986809 0.78158867 0.49040598 0.78158867;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 48 ".vt[0:47]"  1.53077316 -0.67074943 110.47225952 57.9196167 -0.67074943 110.47225952
		 1.53077316 55.71809769 110.47225952 57.9196167 55.71809769 110.47225952 1.53078651 55.71809769 54.08341217
		 57.9196167 55.71809769 54.083427429 1.53078651 -0.67074943 54.08341217 57.9196167 -0.67074943 54.083427429
		 9.53077888 7.32925129 110.47225952 49.91960907 7.32925129 110.47225952 49.91960907 47.71808624 110.47225952
		 9.53077888 47.71808624 110.47225952 9.53077316 55.71809769 102.47225952 49.9196167 55.71809769 102.47225952
		 49.9196167 55.71809769 62.083435059 9.53076553 55.71809769 62.0834198 9.53077888 47.71808624 54.083423615
		 49.91960907 47.71808624 54.083427429 49.91960907 7.32925129 54.083427429 9.53077888 7.32925129 54.083423615
		 57.91960907 7.32925129 62.083435059 57.91960907 7.32925129 102.47225952 57.91960907 47.71808624 62.083435059
		 57.91960907 47.71808624 102.47225952 1.53077316 7.32925129 62.083423615 1.53077316 7.32925129 102.47227478
		 1.53077316 47.71808624 102.47227478 1.53077316 47.71808624 62.083423615 9.53077888 7.32925129 106.37225342
		 49.91960907 7.32925129 106.37226105 49.91960907 47.71808624 106.37226105 9.53077888 47.71808624 106.37225342
		 9.53077316 51.61809921 102.47225952 49.9196167 51.61809921 102.47225952 49.9196167 51.61809921 62.083435059
		 9.53076553 51.61809921 62.0834198 9.53077888 47.71808624 58.18341064 49.9196167 47.71808624 58.18342972
		 49.9196167 7.32925129 58.18342972 9.53077888 7.32925129 58.18341064 53.81960297 7.32925129 62.083435059
		 53.8196106 7.32925129 102.47227478 53.81960297 47.71808624 62.083435059 53.8196106 47.71808624 102.47227478
		 5.63078117 7.32925129 62.083415985 5.63078117 7.32925129 102.47225189 5.63078117 47.71808624 102.47225189
		 5.63078117 47.71808624 62.083415985;
	setAttr -s 92 ".ed[0:91]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0 0 8 1 1 9 1 8 9 0 3 10 1 9 10 0 2 11 1 11 10 0 8 11 0
		 2 12 1 3 13 1 12 13 0 5 14 1 13 14 0 4 15 1 15 14 0 12 15 0 4 16 1 5 17 1 16 17 0
		 7 18 1 17 18 0 6 19 1 19 18 0 16 19 0 7 20 1 1 21 1 20 21 0 5 22 1 22 20 0 3 23 1
		 23 22 0 21 23 0 6 24 1 0 25 1 24 25 0 2 26 1 25 26 0 4 27 1 26 27 0 27 24 0 8 28 0
		 9 29 0 28 29 0 10 30 0 29 30 0 11 31 0 31 30 0 28 31 0 12 32 0 13 33 0 32 33 0 14 34 0
		 33 34 0 15 35 0 35 34 0 32 35 0 16 36 0 17 37 0 36 37 0 18 38 0 37 38 0 19 39 0 39 38 0
		 36 39 0 20 40 0 21 41 0 40 41 0 22 42 0 42 40 0 23 43 0 43 42 0 41 43 0 24 44 0 25 45 0
		 44 45 0 26 46 0 45 46 0 27 47 0 46 47 0 47 44 0;
	setAttr -s 45 -ch 180 ".fc[0:44]" -type "polyFaces" 
		f 4 54 56 -59 -60
		mu 0 4 0 1 2 3
		f 4 62 64 -67 -68
		mu 0 4 4 5 6 7
		f 4 70 72 -75 -76
		mu 0 4 8 9 10 11
		f 4 -79 -81 -83 -84
		mu 0 4 12 13 14 15
		f 4 86 88 90 91
		mu 0 4 16 17 18 19
		f 4 0 13 -15 -13
		mu 0 4 20 21 22 23
		f 4 5 15 -17 -14
		mu 0 4 21 24 25 22
		f 4 -2 17 18 -16
		mu 0 4 24 26 27 25
		f 4 -5 12 19 -18
		mu 0 4 26 20 23 27
		f 4 1 21 -23 -21
		mu 0 4 28 29 30 31
		f 4 7 23 -25 -22
		mu 0 4 29 32 33 30
		f 4 -3 25 26 -24
		mu 0 4 32 34 35 33
		f 4 -7 20 27 -26
		mu 0 4 34 28 31 35
		f 4 2 29 -31 -29
		mu 0 4 36 37 38 39
		f 4 9 31 -33 -30
		mu 0 4 37 40 41 38
		f 4 -4 33 34 -32
		mu 0 4 40 42 43 41
		f 4 -9 28 35 -34
		mu 0 4 42 36 39 43
		f 4 -12 36 38 -38
		mu 0 4 44 40 45 46
		f 4 -10 39 40 -37
		mu 0 4 40 37 47 45
		f 4 -8 41 42 -40
		mu 0 4 37 48 49 47
		f 4 -6 37 43 -42
		mu 0 4 48 44 46 49
		f 4 10 45 -47 -45
		mu 0 4 42 50 51 52
		f 4 4 47 -49 -46
		mu 0 4 50 53 54 51
		f 4 6 49 -51 -48
		mu 0 4 53 36 55 54
		f 4 8 44 -52 -50
		mu 0 4 36 42 52 55
		f 4 14 53 -55 -53
		mu 0 4 23 22 1 0
		f 4 16 55 -57 -54
		mu 0 4 22 25 2 1
		f 4 -19 57 58 -56
		mu 0 4 25 27 3 2
		f 4 -20 52 59 -58
		mu 0 4 27 23 0 3
		f 4 22 61 -63 -61
		mu 0 4 31 30 5 4
		f 4 24 63 -65 -62
		mu 0 4 30 33 6 5
		f 4 -27 65 66 -64
		mu 0 4 33 35 7 6
		f 4 -28 60 67 -66
		mu 0 4 35 31 4 7
		f 4 30 69 -71 -69
		mu 0 4 39 38 9 8
		f 4 32 71 -73 -70
		mu 0 4 38 41 10 9
		f 4 -35 73 74 -72
		mu 0 4 41 43 11 10
		f 4 -36 68 75 -74
		mu 0 4 43 39 8 11
		f 4 -39 76 78 -78
		mu 0 4 46 45 13 12
		f 4 -41 79 80 -77
		mu 0 4 45 47 14 13
		f 4 -43 81 82 -80
		mu 0 4 47 49 15 14
		f 4 -44 77 83 -82
		mu 0 4 49 46 12 15
		f 4 46 85 -87 -85
		mu 0 4 52 51 17 16
		f 4 48 87 -89 -86
		mu 0 4 51 54 18 17
		f 4 50 89 -91 -88
		mu 0 4 54 55 19 18
		f 4 51 84 -92 -90
		mu 0 4 55 52 16 19;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "aiSkyDomeLight1";
	rename -uid "38CD25EF-4597-445E-393E-32A7CFDAA0DD";
	setAttr ".r" -type "double3" -5 0 0 ;
createNode aiSkyDomeLight -n "aiSkyDomeLightShape1" -p "aiSkyDomeLight1";
	rename -uid "BFA354AF-410D-9296-10F3-A2BCCB278E23";
	addAttr -ci true -h true -sn "aal" -ln "attributeAliasList" -dt "attributeAlias";
	setAttr -k off ".v";
	setAttr ".csh" no;
	setAttr ".rcsh" no;
	setAttr ".aal" -type "attributeAlias" {"exposure","aiExposure"} ;
createNode transform -n "directionalLight1";
	rename -uid "171ECD6C-406A-4F00-061C-86B9C4D9B9A0";
	setAttr ".t" -type "double3" 5.6843418860808015e-14 125.06041284072049 211.20358247467212 ;
	setAttr ".r" -type "double3" -80.000000000000028 0 0 ;
	setAttr ".s" -type "double3" 59.788668868074964 59.788668868074964 59.788668868074964 ;
createNode directionalLight -n "directionalLightShape1" -p "directionalLight1";
	rename -uid "262CEF1F-4EE4-48CF-E95F-5ABD2D3B043A";
	setAttr -k off ".v";
createNode transform -n "polySurface2";
	rename -uid "C98E97BD-4A05-7F46-B266-219DDB957863";
	setAttr ".rp" -type "double3" -2.7736823320497237 55.812780499458313 0.49118017549099591 ;
	setAttr ".sp" -type "double3" -2.7736823320497237 55.812780499458313 0.49118017549099591 ;
createNode transform -n "polySurface3" -p "|polySurface2";
	rename -uid "346ED433-4791-65FC-ECB9-2092AEB9079B";
createNode mesh -n "polySurfaceShape4" -p "polySurface3";
	rename -uid "5AE92377-43E3-86B4-D4E8-9A94C9D49E13";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface4" -p "|polySurface2";
	rename -uid "6291F825-4955-7B72-A7AD-AE8FE9B71201";
	setAttr ".rp" -type "double3" -37.069301605224609 112.29631805419922 -56.455577850341797 ;
	setAttr ".sp" -type "double3" -37.069301605224609 112.29631805419922 -56.455577850341797 ;
createNode mesh -n "polySurfaceShape5" -p "polySurface4";
	rename -uid "2AFE6F67-43BB-60EB-1CF1-34935F1B52B7";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "transform3" -p "|polySurface2";
	rename -uid "7A9495FB-4181-0952-F354-4B95C5983AD0";
	setAttr ".v" no;
createNode mesh -n "polySurface2Shape" -p "transform3";
	rename -uid "A70943B2-4C92-166D-9A6A-359339255E39";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.50819049403071404 0.86616003513336182 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 56 ".pt[0:55]" -type "float3"  -8.9399137 -5.6843419e-14 
		-29.825518 -10.513118 -5.6843419e-14 -16.598757 -8.9399137 -5.6843419e-14 -29.825518 
		-10.513118 -5.6843419e-14 -16.598757 4.2868466 -5.6843419e-14 -28.252312 2.7136402 
		-5.6843419e-14 -15.025553 4.2868466 -5.6843419e-14 -28.252312 2.7136402 -5.6843419e-14 
		-15.025553 -9.1631088 -5.6843419e-14 -27.949011 -10.289924 -5.6843419e-14 -18.475264 
		-10.289924 -5.6843419e-14 -18.475264 -9.1631088 -5.6843419e-14 -27.949011 -7.2866001 
		-5.6843419e-14 -27.725815 -8.4134159 -5.6843419e-14 -18.252069 1.0603249 -5.6843419e-14 
		-17.125256 2.1871445 -5.6843419e-14 -26.599001 4.0636511 -5.6843419e-14 -26.375807 
		2.9368341 -5.6843419e-14 -16.902061 2.9368341 -5.6843419e-14 -16.902061 4.0636511 
		-5.6843419e-14 -26.375807 0.83713192 -5.6843419e-14 -15.248751 -8.636611 -5.6843419e-14 
		-16.375563 0.83713192 -5.6843419e-14 -15.248751 -8.636611 -5.6843419e-14 -16.375563 
		2.4103372 -5.6843419e-14 -28.47551 -7.0634108 -5.6843419e-14 -29.602322 -7.0634108 
		-5.6843419e-14 -29.602322 2.4103372 -5.6843419e-14 -28.47551 -8.201396 -5.6843419e-14 
		-27.834618 -9.3282137 -5.6843419e-14 -18.360878 -9.3282137 -5.6843419e-14 -18.360878 
		-8.201396 -5.6843419e-14 -27.834618 -7.2866001 -5.6843419e-14 -27.725815 -8.4134159 
		-5.6843419e-14 -18.252069 1.0603249 -5.6843419e-14 -17.125256 2.1871445 -5.6843419e-14 
		-26.599001 3.1019442 -5.6843419e-14 -26.490192 1.9751241 -5.6843419e-14 -17.016453 
		1.9751241 -5.6843419e-14 -17.016453 3.1019442 -5.6843419e-14 -26.490192 0.95151889 
		-5.6843419e-14 -16.210461 -8.5222273 -5.6843419e-14 -17.337275 0.95151889 -5.6843419e-14 
		-16.210461 -8.5222273 -5.6843419e-14 -17.337275 2.2959521 -5.6843419e-14 -27.513798 
		-7.1777925 -5.6843419e-14 -28.640612 -7.1777925 -5.6843419e-14 -28.640612 2.2959521 
		-5.6843419e-14 -27.513798 0 0 -59.034763 0 0 -59.034763 0 0 -59.034763 0 0 -59.034763 
		0 0 -59.034763 0 0 -59.034763 0 0 -59.034763 0 0 -59.034763;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface5" -p "|polySurface2";
	rename -uid "DDDBFE61-4BCE-0D43-2EFF-77BF9FD4DF89";
	setAttr ".t" -type "double3" -0.20815661577461242 56.422012257277814 -21.760630207933151 ;
	setAttr ".r" -type "double3" 0 -43.18389717987727 0 ;
	setAttr ".rp" -type "double3" 44.814964294433601 51.618099212646484 -24.110622406005863 ;
	setAttr ".rpt" -type "double3" 6.0611372301763886 0 22.95934868793238 ;
	setAttr ".sp" -type "double3" 44.814964294433601 51.618099212646484 -24.110622406005863 ;
createNode mesh -n "polySurfaceShape5" -p "polySurface5";
	rename -uid "ECB1DA27-43D6-9477-4D87-76810F8ED288";
	setAttr -k off ".v";
	setAttr ".iog[0].og[0].gcl" -type "componentList" 45 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]" "f[8]" "f[9]" "f[10]" "f[11]" "f[12]" "f[13]" "f[14]" "f[15]" "f[16]" "f[17]" "f[18]" "f[19]" "f[20]" "f[21]" "f[22]" "f[23]" "f[24]" "f[25]" "f[26]" "f[27]" "f[28]" "f[29]" "f[30]" "f[31]" "f[32]" "f[33]" "f[34]" "f[35]" "f[36]" "f[37]" "f[38]" "f[39]" "f[40]" "f[41]" "f[42]" "f[43]" "f[44]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 56 ".uvst[0].uvsp[0:55]" -type "float2" 0.71366179 0.94276059
		 0.56308657 0.94212902 0.5637182 0.79157811 0.7142328 0.79221791 0.067448996 0.78976238
		 0.21798921 0.78976238 0.21798921 0.94030273 0.067448996 0.94030273 0.5637182 0.79157811
		 0.7142328 0.79221791 0.71366179 0.94276059 0.56308663 0.94212902 0.94893253 0.94270146
		 0.79838502 0.94270146 0.79838502 0.79215878 0.94893253 0.79215878 0.48041052 0.94214135
		 0.32986552 0.94214135 0.32986552 0.79159498 0.48041052 0.79159498 0.75553775 0.9844147
		 0.52121282 0.98376524 0.55320537 0.95223689 0.72378111 0.9526335 0.52187788 0.74949908
		 0.55360568 0.78169471 0.75607073 0.75015175 0.724105 0.78209651 0.025592171 0.74790537
		 0.25984633 0.74790537 0.22798637 0.77976531 0.057451881 0.77976531 0.25984633 0.98215961
		 0.22798637 0.95029998 0.025592171 0.98215961 0.057451881 0.95029998 0.52187788 0.74949908
		 0.75607061 0.75015175 0.72410488 0.78209651 0.55360568 0.78169471 0.75553775 0.9844147
		 0.72378111 0.9526335 0.52121282 0.98376524 0.55320537 0.95223689 0.99078882 0.98408586
		 0.78838933 0.95269424 0.95892763 0.95269424 0.78838933 0.78216159 0.99078882 0.74982655
		 0.95892763 0.78216159 0.28800815 0.98408586 0.31986809 0.95212775 0.49040598 0.95212775
		 0.28800815 0.74982655 0.31986809 0.78158867 0.49040598 0.78158867;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 48 ".vt[0:47]"  10.79376888 -0.67074943 -3.3161869 65.60941315 -0.67074943 9.91057396
		 10.79376888 55.71809769 -3.3161869 65.60941315 55.71809769 9.91057396 24.020542145 55.71809769 -58.13182831
		 78.83616638 55.71809769 -44.90505219 24.020542145 -0.67074943 -58.13182831 78.83616638 -0.67074943 -44.90505219
		 18.57057953 7.32925129 -1.4396801 57.83259583 7.32925129 8.034067154 57.83259583 47.71808624 8.034067154
		 18.57057953 47.71808624 -1.4396801 20.44708252 55.71809769 -9.21648407 59.70911407 55.71809769 0.25726128
		 69.1828537 55.71809769 -39.0047492981 29.92082024 55.71809769 -48.478508 31.79734039 47.71808624 -56.25531006
		 71.059356689 47.71808624 -46.78156281 71.059356689 7.32925129 -46.78156281 31.79734039 7.32925129 -56.25531006
		 76.95965576 7.32925129 -37.12824249 67.48590851 7.32925129 2.13376808 76.95965576 47.71808624 -37.12824249
		 67.48590851 47.71808624 2.13376808 22.14402008 7.32925129 -50.3550148 12.67027187 7.32925129 -11.092975616
		 12.67027187 47.71808624 -11.092975616 22.14402008 47.71808624 -50.3550148 19.53229141 7.32925129 -5.42529297
		 58.79430771 7.32925129 4.048454285 58.79430771 47.71808624 4.048454285 19.53229141 47.71808624 -5.42529297
		 20.44708252 51.61809921 -9.21648407 59.70911407 51.61809921 0.25726128 69.1828537 51.61809921 -39.0047492981
		 29.92082024 51.61809921 -48.478508 30.83563232 47.71808624 -52.26971054 70.097648621 47.71808624 -42.79595184
		 70.097648621 7.32925129 -42.79595184 30.83563232 7.32925129 -52.26971054 72.97402954 7.32925129 -38.089954376
		 63.50029373 7.32925129 1.17207146 72.97402954 47.71808624 -38.089954376 63.50029373 47.71808624 1.17207146
		 26.12964249 7.32925129 -49.39331055 16.65589905 7.32925129 -10.13128853 16.65589905 47.71808624 -10.13128853
		 26.12964249 47.71808624 -49.39331055;
	setAttr -s 92 ".ed[0:91]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0 0 8 1 1 9 1 8 9 0 3 10 1 9 10 0 2 11 1 11 10 0 8 11 0
		 2 12 1 3 13 1 12 13 0 5 14 1 13 14 0 4 15 1 15 14 0 12 15 0 4 16 1 5 17 1 16 17 0
		 7 18 1 17 18 0 6 19 1 19 18 0 16 19 0 7 20 1 1 21 1 20 21 0 5 22 1 22 20 0 3 23 1
		 23 22 0 21 23 0 6 24 1 0 25 1 24 25 0 2 26 1 25 26 0 4 27 1 26 27 0 27 24 0 8 28 0
		 9 29 0 28 29 0 10 30 0 29 30 0 11 31 0 31 30 0 28 31 0 12 32 0 13 33 0 32 33 0 14 34 0
		 33 34 0 15 35 0 35 34 0 32 35 0 16 36 0 17 37 0 36 37 0 18 38 0 37 38 0 19 39 0 39 38 0
		 36 39 0 20 40 0 21 41 0 40 41 0 22 42 0 42 40 0 23 43 0 43 42 0 41 43 0 24 44 0 25 45 0
		 44 45 0 26 46 0 45 46 0 27 47 0 46 47 0 47 44 0;
	setAttr -s 45 -ch 180 ".fc[0:44]" -type "polyFaces" 
		f 4 54 56 -59 -60
		mu 0 4 0 1 2 3
		f 4 62 64 -67 -68
		mu 0 4 4 5 6 7
		f 4 70 72 -75 -76
		mu 0 4 8 9 10 11
		f 4 -79 -81 -83 -84
		mu 0 4 12 13 14 15
		f 4 86 88 90 91
		mu 0 4 16 17 18 19
		f 4 0 13 -15 -13
		mu 0 4 20 21 22 23
		f 4 5 15 -17 -14
		mu 0 4 21 24 25 22
		f 4 -2 17 18 -16
		mu 0 4 24 26 27 25
		f 4 -5 12 19 -18
		mu 0 4 26 20 23 27
		f 4 1 21 -23 -21
		mu 0 4 28 29 30 31
		f 4 7 23 -25 -22
		mu 0 4 29 32 33 30
		f 4 -3 25 26 -24
		mu 0 4 32 34 35 33
		f 4 -7 20 27 -26
		mu 0 4 34 28 31 35
		f 4 2 29 -31 -29
		mu 0 4 36 37 38 39
		f 4 9 31 -33 -30
		mu 0 4 37 40 41 38
		f 4 -4 33 34 -32
		mu 0 4 40 42 43 41
		f 4 -9 28 35 -34
		mu 0 4 42 36 39 43
		f 4 -12 36 38 -38
		mu 0 4 44 40 45 46
		f 4 -10 39 40 -37
		mu 0 4 40 37 47 45
		f 4 -8 41 42 -40
		mu 0 4 37 48 49 47
		f 4 -6 37 43 -42
		mu 0 4 48 44 46 49
		f 4 10 45 -47 -45
		mu 0 4 42 50 51 52
		f 4 4 47 -49 -46
		mu 0 4 50 53 54 51
		f 4 6 49 -51 -48
		mu 0 4 53 36 55 54
		f 4 8 44 -52 -50
		mu 0 4 36 42 52 55
		f 4 14 53 -55 -53
		mu 0 4 23 22 1 0
		f 4 16 55 -57 -54
		mu 0 4 22 25 2 1
		f 4 -19 57 58 -56
		mu 0 4 25 27 3 2
		f 4 -20 52 59 -58
		mu 0 4 27 23 0 3
		f 4 22 61 -63 -61
		mu 0 4 31 30 5 4
		f 4 24 63 -65 -62
		mu 0 4 30 33 6 5
		f 4 -27 65 66 -64
		mu 0 4 33 35 7 6
		f 4 -28 60 67 -66
		mu 0 4 35 31 4 7
		f 4 30 69 -71 -69
		mu 0 4 39 38 9 8
		f 4 32 71 -73 -70
		mu 0 4 38 41 10 9
		f 4 -35 73 74 -72
		mu 0 4 41 43 11 10
		f 4 -36 68 75 -74
		mu 0 4 43 39 8 11
		f 4 -39 76 78 -78
		mu 0 4 46 45 13 12
		f 4 -41 79 80 -77
		mu 0 4 45 47 14 13
		f 4 -43 81 82 -80
		mu 0 4 47 49 15 14
		f 4 -44 77 83 -82
		mu 0 4 49 46 12 15
		f 4 46 85 -87 -85
		mu 0 4 52 51 17 16
		f 4 48 87 -89 -86
		mu 0 4 51 54 18 17
		f 4 50 89 -91 -88
		mu 0 4 54 55 19 18
		f 4 51 84 -92 -90
		mu 0 4 55 52 16 19;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface6" -p "|polySurface2";
	rename -uid "6422C30C-4B7E-5B0C-929D-9993F8476DC0";
	setAttr ".t" -type "double3" 64.598468768432582 -4.5191168268065104e-06 -21.322324724827254 ;
	setAttr ".r" -type "double3" 0 -47.571456621919921 0 ;
createNode mesh -n "polySurfaceShape6" -p "polySurface6";
	rename -uid "CE28680E-4B00-7C5F-4A22-95826E83278C";
	setAttr -k off ".v";
	setAttr ".iog[0].og[0].gcl" -type "componentList" 45 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]" "f[8]" "f[9]" "f[10]" "f[11]" "f[12]" "f[13]" "f[14]" "f[15]" "f[16]" "f[17]" "f[18]" "f[19]" "f[20]" "f[21]" "f[22]" "f[23]" "f[24]" "f[25]" "f[26]" "f[27]" "f[28]" "f[29]" "f[30]" "f[31]" "f[32]" "f[33]" "f[34]" "f[35]" "f[36]" "f[37]" "f[38]" "f[39]" "f[40]" "f[41]" "f[42]" "f[43]" "f[44]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 56 ".uvst[0].uvsp[0:55]" -type "float2" 0.71366179 0.94276059
		 0.56308657 0.94212902 0.5637182 0.79157811 0.7142328 0.79221791 0.067448996 0.78976238
		 0.21798921 0.78976238 0.21798921 0.94030273 0.067448996 0.94030273 0.5637182 0.79157811
		 0.7142328 0.79221791 0.71366179 0.94276059 0.56308663 0.94212902 0.94893253 0.94270146
		 0.79838502 0.94270146 0.79838502 0.79215878 0.94893253 0.79215878 0.48041052 0.94214135
		 0.32986552 0.94214135 0.32986552 0.79159498 0.48041052 0.79159498 0.75553775 0.9844147
		 0.52121282 0.98376524 0.55320537 0.95223689 0.72378111 0.9526335 0.52187788 0.74949908
		 0.55360568 0.78169471 0.75607073 0.75015175 0.724105 0.78209651 0.025592171 0.74790537
		 0.25984633 0.74790537 0.22798637 0.77976531 0.057451881 0.77976531 0.25984633 0.98215961
		 0.22798637 0.95029998 0.025592171 0.98215961 0.057451881 0.95029998 0.52187788 0.74949908
		 0.75607061 0.75015175 0.72410488 0.78209651 0.55360568 0.78169471 0.75553775 0.9844147
		 0.72378111 0.9526335 0.52121282 0.98376524 0.55320537 0.95223689 0.99078882 0.98408586
		 0.78838933 0.95269424 0.95892763 0.95269424 0.78838933 0.78216159 0.99078882 0.74982655
		 0.95892763 0.78216159 0.28800815 0.98408586 0.31986809 0.95212775 0.49040598 0.95212775
		 0.28800815 0.74982655 0.31986809 0.78158867 0.49040598 0.78158867;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 48 ".vt[0:47]"  10.79376888 -0.67074943 -3.3161869 65.60941315 -0.67074943 9.91057396
		 10.79376888 55.71809769 -3.3161869 65.60941315 55.71809769 9.91057396 24.020542145 55.71809769 -58.13182831
		 78.83616638 55.71809769 -44.90505219 24.020542145 -0.67074943 -58.13182831 78.83616638 -0.67074943 -44.90505219
		 18.57057953 7.32925129 -1.4396801 57.83259583 7.32925129 8.034067154 57.83259583 47.71808624 8.034067154
		 18.57057953 47.71808624 -1.4396801 20.44708252 55.71809769 -9.21648407 59.70911407 55.71809769 0.25726128
		 69.1828537 55.71809769 -39.0047492981 29.92082024 55.71809769 -48.478508 31.79734039 47.71808624 -56.25531006
		 71.059356689 47.71808624 -46.78156281 71.059356689 7.32925129 -46.78156281 31.79734039 7.32925129 -56.25531006
		 76.95965576 7.32925129 -37.12824249 67.48590851 7.32925129 2.13376808 76.95965576 47.71808624 -37.12824249
		 67.48590851 47.71808624 2.13376808 22.14402008 7.32925129 -50.3550148 12.67027187 7.32925129 -11.092975616
		 12.67027187 47.71808624 -11.092975616 22.14402008 47.71808624 -50.3550148 19.53229141 7.32925129 -5.42529297
		 58.79430771 7.32925129 4.048454285 58.79430771 47.71808624 4.048454285 19.53229141 47.71808624 -5.42529297
		 20.44708252 51.61809921 -9.21648407 59.70911407 51.61809921 0.25726128 69.1828537 51.61809921 -39.0047492981
		 29.92082024 51.61809921 -48.478508 30.83563232 47.71808624 -52.26971054 70.097648621 47.71808624 -42.79595184
		 70.097648621 7.32925129 -42.79595184 30.83563232 7.32925129 -52.26971054 72.97402954 7.32925129 -38.089954376
		 63.50029373 7.32925129 1.17207146 72.97402954 47.71808624 -38.089954376 63.50029373 47.71808624 1.17207146
		 26.12964249 7.32925129 -49.39331055 16.65589905 7.32925129 -10.13128853 16.65589905 47.71808624 -10.13128853
		 26.12964249 47.71808624 -49.39331055;
	setAttr -s 92 ".ed[0:91]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0 0 8 1 1 9 1 8 9 0 3 10 1 9 10 0 2 11 1 11 10 0 8 11 0
		 2 12 1 3 13 1 12 13 0 5 14 1 13 14 0 4 15 1 15 14 0 12 15 0 4 16 1 5 17 1 16 17 0
		 7 18 1 17 18 0 6 19 1 19 18 0 16 19 0 7 20 1 1 21 1 20 21 0 5 22 1 22 20 0 3 23 1
		 23 22 0 21 23 0 6 24 1 0 25 1 24 25 0 2 26 1 25 26 0 4 27 1 26 27 0 27 24 0 8 28 0
		 9 29 0 28 29 0 10 30 0 29 30 0 11 31 0 31 30 0 28 31 0 12 32 0 13 33 0 32 33 0 14 34 0
		 33 34 0 15 35 0 35 34 0 32 35 0 16 36 0 17 37 0 36 37 0 18 38 0 37 38 0 19 39 0 39 38 0
		 36 39 0 20 40 0 21 41 0 40 41 0 22 42 0 42 40 0 23 43 0 43 42 0 41 43 0 24 44 0 25 45 0
		 44 45 0 26 46 0 45 46 0 27 47 0 46 47 0 47 44 0;
	setAttr -s 45 -ch 180 ".fc[0:44]" -type "polyFaces" 
		f 4 54 56 -59 -60
		mu 0 4 0 1 2 3
		f 4 62 64 -67 -68
		mu 0 4 4 5 6 7
		f 4 70 72 -75 -76
		mu 0 4 8 9 10 11
		f 4 -79 -81 -83 -84
		mu 0 4 12 13 14 15
		f 4 86 88 90 91
		mu 0 4 16 17 18 19
		f 4 0 13 -15 -13
		mu 0 4 20 21 22 23
		f 4 5 15 -17 -14
		mu 0 4 21 24 25 22
		f 4 -2 17 18 -16
		mu 0 4 24 26 27 25
		f 4 -5 12 19 -18
		mu 0 4 26 20 23 27
		f 4 1 21 -23 -21
		mu 0 4 28 29 30 31
		f 4 7 23 -25 -22
		mu 0 4 29 32 33 30
		f 4 -3 25 26 -24
		mu 0 4 32 34 35 33
		f 4 -7 20 27 -26
		mu 0 4 34 28 31 35
		f 4 2 29 -31 -29
		mu 0 4 36 37 38 39
		f 4 9 31 -33 -30
		mu 0 4 37 40 41 38
		f 4 -4 33 34 -32
		mu 0 4 40 42 43 41
		f 4 -9 28 35 -34
		mu 0 4 42 36 39 43
		f 4 -12 36 38 -38
		mu 0 4 44 40 45 46
		f 4 -10 39 40 -37
		mu 0 4 40 37 47 45
		f 4 -8 41 42 -40
		mu 0 4 37 48 49 47
		f 4 -6 37 43 -42
		mu 0 4 48 44 46 49
		f 4 10 45 -47 -45
		mu 0 4 42 50 51 52
		f 4 4 47 -49 -46
		mu 0 4 50 53 54 51
		f 4 6 49 -51 -48
		mu 0 4 53 36 55 54
		f 4 8 44 -52 -50
		mu 0 4 36 42 52 55
		f 4 14 53 -55 -53
		mu 0 4 23 22 1 0
		f 4 16 55 -57 -54
		mu 0 4 22 25 2 1
		f 4 -19 57 58 -56
		mu 0 4 25 27 3 2
		f 4 -20 52 59 -58
		mu 0 4 27 23 0 3
		f 4 22 61 -63 -61
		mu 0 4 31 30 5 4
		f 4 24 63 -65 -62
		mu 0 4 30 33 6 5
		f 4 -27 65 66 -64
		mu 0 4 33 35 7 6
		f 4 -28 60 67 -66
		mu 0 4 35 31 4 7
		f 4 30 69 -71 -69
		mu 0 4 39 38 9 8
		f 4 32 71 -73 -70
		mu 0 4 38 41 10 9
		f 4 -35 73 74 -72
		mu 0 4 41 43 11 10
		f 4 -36 68 75 -74
		mu 0 4 43 39 8 11
		f 4 -39 76 78 -78
		mu 0 4 46 45 13 12
		f 4 -41 79 80 -77
		mu 0 4 45 47 14 13
		f 4 -43 81 82 -80
		mu 0 4 47 49 15 14
		f 4 -44 77 83 -82
		mu 0 4 49 46 12 15
		f 4 46 85 -87 -85
		mu 0 4 52 51 17 16
		f 4 48 87 -89 -86
		mu 0 4 51 54 18 17
		f 4 50 89 -91 -88
		mu 0 4 54 55 19 18
		f 4 51 84 -92 -90
		mu 0 4 55 52 16 19;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "polySurface7" -p "|polySurface2";
	rename -uid "D20C3037-4797-DE80-55AF-389A890933B2";
	setAttr ".t" -type "double3" 0 110.82414318957265 0 ;
	setAttr ".r" -type "double3" 0 -42.815089015483821 0 ;
	setAttr ".rp" -type "double3" -37.069301605224609 112.29631805419922 -56.455577850341797 ;
	setAttr ".sp" -type "double3" -37.069301605224609 112.29631805419922 -56.455577850341797 ;
createNode mesh -n "polySurfaceShape7" -p "polySurface7";
	rename -uid "8BAAF722-42BB-1E43-5688-4F81AA2598E8";
	setAttr -k off ".v";
	setAttr ".iog[0].og[0].gcl" -type "componentList" 5 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 14 ".uvst[0].uvsp[0:13]" -type "float2" 0.025982849 0.47555804
		 0.025982849 0.02222901 0.39073053 0.02222901 0.39073053 0.47555804 0.62208951 0.02222901
		 0.62208951 0.47555804 0.98683715 0.02222901 0.98683715 0.47555804 0.56341791 0.72142935
		 0.11009486 0.72142935 0.11009486 0.49013409 0.56341791 0.49013409 0.98683715 0.70669937
		 0.62208951 0.70669937;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 8 ".vt[0:7]"  -81.66989136 112.2963028 -28.17288589 -81.66989136 1.43205452 -28.17288589
		 7.53129578 112.29631042 -28.17290115 7.53129578 1.43205452 -28.17290115 7.53129196 112.2963028 -84.73825073
		 7.53129196 1.43205452 -84.73825073 -81.66989136 112.29631042 -84.73825073 -81.66989136 1.43205452 -84.73825073;
	setAttr -s 12 ".ed[0:11]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 4 0
		 3 5 0 4 6 0 5 7 0 6 0 0 7 1 0;
	setAttr -s 5 -ch 20 ".fc[0:4]" -type "polyFaces" 
		f 4 0 5 -2 -5
		mu 0 4 0 1 2 3
		f 4 1 7 -3 -7
		mu 0 4 3 2 4 5
		f 4 2 9 -4 -9
		mu 0 4 5 4 6 7
		f 4 3 11 -1 -11
		mu 0 4 8 9 10 11
		f 4 10 4 6 8
		mu 0 4 7 12 13 5;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pPlane1";
	rename -uid "E4F8EB4C-474E-4940-AA9D-40BB659C5884";
	setAttr ".t" -type "double3" 2.1033683856903593 0 -1.136556360519009 ;
	setAttr ".s" -type "double3" 1.8511719798915287 1.8511719798915287 1.8511719798915287 ;
createNode mesh -n "pPlaneShape1" -p "pPlane1";
	rename -uid "46CC374A-4202-CFE1-65BA-EF9E3E646933";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "09915A03-4AD0-6B4A-0FD6-BE8CD9CB4E7C";
	setAttr -s 5 ".lnk";
	setAttr -s 5 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "5496CF98-4AD0-E081-9F19-199E32FC6020";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "B55B9B3F-4AAF-CE26-06FF-81A60800664C";
createNode displayLayerManager -n "layerManager";
	rename -uid "EF40D430-41E2-E488-DCC7-3F830963C196";
createNode displayLayer -n "defaultLayer";
	rename -uid "9583C148-480F-2CB9-B73D-54A3EE4BCC73";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "FE838AF9-4BFE-ED00-089A-87BE8F10F519";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "114FBCDF-4E81-0090-E448-79B97934D033";
	setAttr ".g" yes;
createNode nodeGraphEditorInfo -n "lawnmower_Unwrap:hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "E704987E-4238-20A2-6A99-4CAC298A3DFE";
	setAttr ".def" no;
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -622.61902287839052 -376.19046124201031 ;
	setAttr ".tgi[0].vh" -type "double2" 682.14283003693652 394.04760338957419 ;
createNode aiStandardSurface -n "groundplane";
	rename -uid "E9C5E389-45E2-6745-3B07-95A0CAE1B378";
	setAttr ".specular" 0;
createNode shadingEngine -n "aiStandardSurface2SG";
	rename -uid "6E4B690D-449F-70D8-95F6-0D936CD612FE";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo5";
	rename -uid "0A7D7F34-4876-5D3E-240D-88A25DD7F1D9";
createNode aiOptions -s -n "defaultArnoldRenderOptions";
	rename -uid "5DF57A58-47EE-B29B-297F-6CBD3CA2EF01";
	setAttr ".version" -type "string" "4.0.0";
createNode aiAOVFilter -s -n "defaultArnoldFilter";
	rename -uid "F03FCC2C-4848-866E-887A-E3B0BAD8AD2B";
	setAttr ".ai_translator" -type "string" "gaussian";
createNode aiAOVDriver -s -n "defaultArnoldDriver";
	rename -uid "E0464530-42FE-95D1-10CB-83AFCE1134A9";
	setAttr ".ai_translator" -type "string" "exr";
createNode aiAOVDriver -s -n "defaultArnoldDisplayDriver";
	rename -uid "C0580BBD-4DD2-A831-28FF-45BB61A425F9";
	setAttr ".output_mode" 0;
	setAttr ".ai_translator" -type "string" "maya";
createNode file -n "groundplane1";
	rename -uid "168B72C1-427D-FD36-419A-A3833641C725";
	setAttr ".ftn" -type "string" "C:/Users/goedele.godfroid/Desktop/New folder/3D1_Template/sourceimages/tex_template.jpg";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture1";
	rename -uid "9ED4ECEF-4A6D-13D1-BFED-67B20CE5FEC6";
createNode script -n "uiConfigurationScriptNode";
	rename -uid "8D8E3BC6-4C1F-395B-3F33-2F9610DBAC93";
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
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"flat\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1130\n            -height 811\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n"
		+ "            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -selectCommand \"print(\\\"\\\")\" \n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n"
		+ "            -selectionOrder \"chronological\" \n            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n"
		+ "            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n"
		+ "            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n"
		+ "                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n"
		+ "                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showPlayRangeShades \"on\" \n                -lockPlayRangeShades \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n"
		+ "                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -keyMinScale 1\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -valueLinesToggle 1\n                -highlightAffectedCurves 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n"
		+ "                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n"
		+ "                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n"
		+ "                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n"
		+ "            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n"
		+ "                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n"
		+ "                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n"
		+ "                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\n{ string $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n"
		+ "                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 32768\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n"
		+ "                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -controllers 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n"
		+ "                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 0\n                -height 0\n                -sceneRenderFilter 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName;\n            stereoCameraView -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName; };\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n"
		+ "        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"flat\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1130\\n    -height 811\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"flat\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1130\\n    -height 811\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 100 -size 100 -divisions 10 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "7A7C127A-4165-9178-D8F0-A589B714C371";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "EF7B648C-434D-1BA2-1D54-A58ECFA6AAB1";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -628.57140359424511 -107.73809095696818 ;
	setAttr ".tgi[0].vh" -type "double2" 573.80950100838288 500.59521820337136 ;
createNode polyUnite -n "polyUnite1";
	rename -uid "84AC09E9-4519-97A3-4ADD-B4835BFEE28C";
	setAttr -s 2 ".ip";
	setAttr -s 2 ".im";
createNode groupId -n "groupId1";
	rename -uid "6ACC2926-4F77-45BC-FEEA-C69EF7697588";
	setAttr ".ihi" 0;
createNode groupId -n "groupId2";
	rename -uid "B667F490-4401-ADD9-0591-93B57329187A";
	setAttr ".ihi" 0;
createNode groupId -n "groupId3";
	rename -uid "38AF29BC-42C8-FFC7-0538-F8B8AC250B7B";
	setAttr ".ihi" 0;
createNode groupId -n "groupId4";
	rename -uid "40DA12DA-47F6-8F2D-BE0D-54B2921B3C4E";
	setAttr ".ihi" 0;
createNode polyPlane -n "polyPlane1";
	rename -uid "6CC6F6A2-4CBD-09D1-3E40-719273A00215";
	setAttr ".w" 197.31843842170034;
	setAttr ".h" 202.32663119194481;
	setAttr ".sw" 1;
	setAttr ".sh" 1;
	setAttr ".cuv" 2;
createNode aiAmbientOcclusion -n "aiAmbientOcclusion1";
	rename -uid "97293D68-4668-E349-7722-3E910CE2F9AC";
createNode shadingEngine -n "aiAmbientOcclusion1SG";
	rename -uid "CF0B644A-4460-44D1-0B04-E5831A560960";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo6";
	rename -uid "DD7A8AD7-468B-4C37-B4F5-6FA2D5220B78";
createNode aiStandardSurface -n "aiStandardSurface3";
	rename -uid "00049FBE-49D5-0C17-D5EB-C0A0186E038E";
createNode shadingEngine -n "aiStandardSurface3SG";
	rename -uid "2476B472-4763-5368-94F5-5890CBDE221C";
	setAttr ".ihi" 0;
	setAttr -s 7 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 7 ".gn";
createNode materialInfo -n "materialInfo7";
	rename -uid "E444C4B4-4C60-9F4F-3586-9A8DAE148006";
createNode psdFileTex -n "psdFileTex1";
	rename -uid "880B5869-45B7-4555-0219-058EBB81572E";
	setAttr ".ftn" -type "string" "C:/Users/Jarne/Documents/DAE/sem_2/3D/week_06/3D1_TexturingLab//sourceimages/texture.psd";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture2";
	rename -uid "701D4CAD-4835-CCD0-7FFD-3F8BFB1B6B1B";
createNode polySeparate -n "polySeparate1";
	rename -uid "71BFC4C9-4CA9-215A-A9D1-1299CABF3755";
	setAttr ".ic" 2;
	setAttr -s 2 ".out";
createNode groupId -n "groupId5";
	rename -uid "D2FC7A78-440A-3833-6146-8C9FFD6713F0";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts1";
	rename -uid "5EFBAA12-425F-0E1A-4E04-F1A206FF122C";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:49]";
createNode groupId -n "groupId6";
	rename -uid "9A0364B3-4D53-AD9A-75E4-D3A3DF11E64F";
	setAttr ".ihi" 0;
createNode groupId -n "groupId7";
	rename -uid "E695F264-4761-253B-EC1C-6F8628280289";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts2";
	rename -uid "B416A4AD-4CB5-6836-6FFE-16B5B9C5E734";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 45 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]" "f[5]" "f[6]" "f[7]" "f[8]" "f[9]" "f[10]" "f[11]" "f[12]" "f[13]" "f[14]" "f[15]" "f[16]" "f[17]" "f[18]" "f[19]" "f[20]" "f[21]" "f[22]" "f[23]" "f[24]" "f[25]" "f[26]" "f[27]" "f[28]" "f[29]" "f[30]" "f[31]" "f[32]" "f[33]" "f[34]" "f[35]" "f[36]" "f[37]" "f[38]" "f[39]" "f[40]" "f[41]" "f[42]" "f[43]" "f[44]";
createNode groupId -n "groupId8";
	rename -uid "5AD3E167-45C3-6F6B-6889-91998EA83A34";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts3";
	rename -uid "A2DC6E95-4B20-023E-9F2F-DA933A42C136";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 5 "f[0]" "f[1]" "f[2]" "f[3]" "f[4]";
createNode groupId -n "groupId9";
	rename -uid "05574202-4AA2-02B0-2DC9-AF819A26AB2D";
	setAttr ".ihi" 0;
createNode groupId -n "groupId10";
	rename -uid "9842B614-4A3D-C038-1260-47A99AF7E011";
	setAttr ".ihi" 0;
createNode groupId -n "groupId11";
	rename -uid "C3E97868-42D0-AFFC-0450-6C883262C34E";
	setAttr ".ihi" 0;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".aoon" yes;
	setAttr ".aoam" 0.94405591487884521;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 5 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 8 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 2 ".u";
select -ne :defaultRenderingList1;
select -ne :lightList1;
	setAttr -s 2 ".l";
select -ne :defaultTextureList1;
	setAttr -s 2 ".tx";
select -ne :initialShadingGroup;
	setAttr -s 5 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 4 ".gn";
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
	setAttr -s 2 ".dsm";
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
connectAttr "groupId3.id" "polySurfaceShape2.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape2.iog.og[0].gco";
connectAttr "groupId4.id" "polySurfaceShape2.ciog.cog[0].cgid";
connectAttr "groupId1.id" "polySurfaceShape3.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "polySurfaceShape3.iog.og[0].gco";
connectAttr "groupId2.id" "polySurfaceShape3.ciog.cog[0].cgid";
connectAttr "groupParts2.og" "polySurfaceShape4.i";
connectAttr "groupId7.id" "polySurfaceShape4.iog.og[0].gid";
connectAttr "aiStandardSurface3SG.mwc" "polySurfaceShape4.iog.og[0].gco";
connectAttr "groupParts3.og" "|polySurface2|polySurface4|polySurfaceShape5.i";
connectAttr "groupId8.id" "|polySurface2|polySurface4|polySurfaceShape5.iog.og[0].gid"
		;
connectAttr "aiStandardSurface3SG.mwc" "|polySurface2|polySurface4|polySurfaceShape5.iog.og[0].gco"
		;
connectAttr "groupParts1.og" "polySurface2Shape.i";
connectAttr "groupId5.id" "polySurface2Shape.iog.og[1].gid";
connectAttr "aiStandardSurface3SG.mwc" "polySurface2Shape.iog.og[1].gco";
connectAttr "groupId6.id" "polySurface2Shape.ciog.cog[0].cgid";
connectAttr "groupId9.id" "|polySurface2|polySurface5|polySurfaceShape5.iog.og[0].gid"
		;
connectAttr "aiStandardSurface3SG.mwc" "|polySurface2|polySurface5|polySurfaceShape5.iog.og[0].gco"
		;
connectAttr "groupId10.id" "polySurfaceShape6.iog.og[0].gid";
connectAttr "aiStandardSurface3SG.mwc" "polySurfaceShape6.iog.og[0].gco";
connectAttr "groupId11.id" "polySurfaceShape7.iog.og[0].gid";
connectAttr "aiStandardSurface3SG.mwc" "polySurfaceShape7.iog.og[0].gco";
connectAttr "polyPlane1.out" "pPlaneShape1.i";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface2SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiAmbientOcclusion1SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface3SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface2SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiAmbientOcclusion1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface3SG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "groundplane1.oc" "groundplane.base_color";
connectAttr "groundplane.out" "aiStandardSurface2SG.ss";
connectAttr "groundplane_GeoShape.iog" "aiStandardSurface2SG.dsm" -na;
connectAttr "aiStandardSurface2SG.msg" "materialInfo5.sg";
connectAttr "groundplane.msg" "materialInfo5.m";
connectAttr "groundplane1.msg" "materialInfo5.t" -na;
connectAttr ":defaultColorMgtGlobals.cme" "groundplane1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "groundplane1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "groundplane1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "groundplane1.ws";
connectAttr "place2dTexture1.c" "groundplane1.c";
connectAttr "place2dTexture1.tf" "groundplane1.tf";
connectAttr "place2dTexture1.rf" "groundplane1.rf";
connectAttr "place2dTexture1.mu" "groundplane1.mu";
connectAttr "place2dTexture1.mv" "groundplane1.mv";
connectAttr "place2dTexture1.s" "groundplane1.s";
connectAttr "place2dTexture1.wu" "groundplane1.wu";
connectAttr "place2dTexture1.wv" "groundplane1.wv";
connectAttr "place2dTexture1.re" "groundplane1.re";
connectAttr "place2dTexture1.of" "groundplane1.of";
connectAttr "place2dTexture1.r" "groundplane1.ro";
connectAttr "place2dTexture1.n" "groundplane1.n";
connectAttr "place2dTexture1.vt1" "groundplane1.vt1";
connectAttr "place2dTexture1.vt2" "groundplane1.vt2";
connectAttr "place2dTexture1.vt3" "groundplane1.vt3";
connectAttr "place2dTexture1.vc1" "groundplane1.vc1";
connectAttr "place2dTexture1.o" "groundplane1.uv";
connectAttr "place2dTexture1.ofs" "groundplane1.fs";
connectAttr "polySurfaceShape3.o" "polyUnite1.ip[0]";
connectAttr "polySurfaceShape2.o" "polyUnite1.ip[1]";
connectAttr "polySurfaceShape3.wm" "polyUnite1.im[0]";
connectAttr "polySurfaceShape2.wm" "polyUnite1.im[1]";
connectAttr "aiAmbientOcclusion1.out" "aiAmbientOcclusion1SG.ss";
connectAttr "aiAmbientOcclusion1SG.msg" "materialInfo6.sg";
connectAttr "aiAmbientOcclusion1.msg" "materialInfo6.m";
connectAttr "aiAmbientOcclusion1.msg" "materialInfo6.t" -na;
connectAttr "psdFileTex1.oc" "aiStandardSurface3.base_color";
connectAttr "aiStandardSurface3.out" "aiStandardSurface3SG.ss";
connectAttr "polySurface2Shape.iog.og[1]" "aiStandardSurface3SG.dsm" -na;
connectAttr "polySurface2Shape.ciog.cog[0]" "aiStandardSurface3SG.dsm" -na;
connectAttr "polySurfaceShape4.iog.og[0]" "aiStandardSurface3SG.dsm" -na;
connectAttr "|polySurface2|polySurface4|polySurfaceShape5.iog.og[0]" "aiStandardSurface3SG.dsm"
		 -na;
connectAttr "|polySurface2|polySurface5|polySurfaceShape5.iog.og[0]" "aiStandardSurface3SG.dsm"
		 -na;
connectAttr "polySurfaceShape6.iog.og[0]" "aiStandardSurface3SG.dsm" -na;
connectAttr "polySurfaceShape7.iog.og[0]" "aiStandardSurface3SG.dsm" -na;
connectAttr "groupId5.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "groupId6.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "groupId7.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "groupId8.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "groupId9.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "groupId10.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "groupId11.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "aiStandardSurface3SG.msg" "materialInfo7.sg";
connectAttr "aiStandardSurface3.msg" "materialInfo7.m";
connectAttr "psdFileTex1.msg" "materialInfo7.t" -na;
connectAttr ":defaultColorMgtGlobals.cme" "psdFileTex1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "psdFileTex1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "psdFileTex1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "psdFileTex1.ws";
connectAttr "place2dTexture2.c" "psdFileTex1.c";
connectAttr "place2dTexture2.tf" "psdFileTex1.tf";
connectAttr "place2dTexture2.rf" "psdFileTex1.rf";
connectAttr "place2dTexture2.mu" "psdFileTex1.mu";
connectAttr "place2dTexture2.mv" "psdFileTex1.mv";
connectAttr "place2dTexture2.s" "psdFileTex1.s";
connectAttr "place2dTexture2.wu" "psdFileTex1.wu";
connectAttr "place2dTexture2.wv" "psdFileTex1.wv";
connectAttr "place2dTexture2.re" "psdFileTex1.re";
connectAttr "place2dTexture2.of" "psdFileTex1.of";
connectAttr "place2dTexture2.r" "psdFileTex1.ro";
connectAttr "place2dTexture2.n" "psdFileTex1.n";
connectAttr "place2dTexture2.vt1" "psdFileTex1.vt1";
connectAttr "place2dTexture2.vt2" "psdFileTex1.vt2";
connectAttr "place2dTexture2.vt3" "psdFileTex1.vt3";
connectAttr "place2dTexture2.vc1" "psdFileTex1.vc1";
connectAttr "place2dTexture2.o" "psdFileTex1.uv";
connectAttr "place2dTexture2.ofs" "psdFileTex1.fs";
connectAttr "polySurface2Shape.o" "polySeparate1.ip";
connectAttr "polyUnite1.out" "groupParts1.ig";
connectAttr "groupId5.id" "groupParts1.gi";
connectAttr "polySeparate1.out[0]" "groupParts2.ig";
connectAttr "groupId7.id" "groupParts2.gi";
connectAttr "polySeparate1.out[1]" "groupParts3.ig";
connectAttr "groupId8.id" "groupParts3.gi";
connectAttr "aiStandardSurface2SG.pa" ":renderPartition.st" -na;
connectAttr "aiAmbientOcclusion1SG.pa" ":renderPartition.st" -na;
connectAttr "aiStandardSurface3SG.pa" ":renderPartition.st" -na;
connectAttr "groundplane.msg" ":defaultShaderList1.s" -na;
connectAttr "aiAmbientOcclusion1.msg" ":defaultShaderList1.s" -na;
connectAttr "aiStandardSurface3.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "aiSkyDomeLightShape1.ltd" ":lightList1.l" -na;
connectAttr "directionalLightShape1.ltd" ":lightList1.l" -na;
connectAttr "groundplane1.msg" ":defaultTextureList1.tx" -na;
connectAttr "psdFileTex1.msg" ":defaultTextureList1.tx" -na;
connectAttr "polySurfaceShape3.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape3.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape2.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "polySurfaceShape2.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pPlaneShape1.iog" ":initialShadingGroup.dsm" -na;
connectAttr "groupId1.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId2.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId3.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId4.msg" ":initialShadingGroup.gn" -na;
connectAttr "aiSkyDomeLight1.iog" ":defaultLightSet.dsm" -na;
connectAttr "directionalLight1.iog" ":defaultLightSet.dsm" -na;
// End of Lab_Texturing.0015.ma
