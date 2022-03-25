//Maya ASCII 2022 scene
//Name: satellite_dish.ma
//Last modified: Fri, Feb 25, 2022 11:27:02 AM
//Codeset: 1252
requires maya "2022";
requires "mtoa" "4.2.1";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202102181415-29bfc1879c";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19044)";
fileInfo "UUID" "93816B6A-41CC-40B2-39FF-D69F16D4BC04";
createNode transform -s -n "persp";
	rename -uid "97DFE6E8-4D49-4754-0B98-03B78E78B091";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 228.75188424523503 28.84910081713647 37.411687785293594 ;
	setAttr ".r" -type "double3" -1.5383527266615862 -1349.0000000000077 0 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "C118E3F5-48D0-6EF2-7BC1-AFA95F87EB1B";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 228.23457203182579;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "4D27FDF7-47F3-F838-7981-BA98E02C8609";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -1.4226219080142783 1000.1 62.466034688263107 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "2F880E1F-4305-DA41-A26C-6999B78084DA";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 57.313332743071498;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "D2C66DA5-4F3F-D0A2-E1D6-D7AB0CB10C4B";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -12.032845285432183 13.690045540927292 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "A4CA7DA2-411A-957B-D318-CDB37FA4FF98";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 61.648856029614421;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "BC91BA40-4261-4549-E0EB-15B2C2DBC0EA";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 7.3461860645238826 9.2295623493168648 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "BD7001EE-4934-0F66-0A98-C2ABF7DAB88C";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 44.842358544141625;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "pCylinder1";
	rename -uid "67A009C6-4781-F6BA-568F-EAA227C121F5";
	setAttr ".t" -type "double3" -9.7398554181229855 53.100374912581444 15.485531103344808 ;
	setAttr ".r" -type "double3" -295.65330600889604 10.381984721952229 8.5334194286374956 ;
createNode mesh -n "pCylinderShape1" -p "pCylinder1";
	rename -uid "FDD85562-49E6-52A4-DF62-69B3F9525EBE";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 10 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "bottom";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[12:23]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottomRing";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "e[0:11]";
	setAttr ".gtag[2].gtagnm" -type "string" "cylBottomCap";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 2 "vtx[0:11]" "vtx[24]";
	setAttr ".gtag[3].gtagnm" -type "string" "cylBottomRing";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "vtx[0:11]";
	setAttr ".gtag[4].gtagnm" -type "string" "cylSides";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "vtx[0:23]";
	setAttr ".gtag[5].gtagnm" -type "string" "cylTopCap";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 2 "vtx[12:23]" "vtx[25]";
	setAttr ".gtag[6].gtagnm" -type "string" "cylTopRing";
	setAttr ".gtag[6].gtagcmp" -type "componentList" 1 "vtx[12:23]";
	setAttr ".gtag[7].gtagnm" -type "string" "sides";
	setAttr ".gtag[7].gtagcmp" -type "componentList" 1 "f[0:11]";
	setAttr ".gtag[8].gtagnm" -type "string" "top";
	setAttr ".gtag[8].gtagcmp" -type "componentList" 1 "f[24:35]";
	setAttr ".gtag[9].gtagnm" -type "string" "topRing";
	setAttr ".gtag[9].gtagcmp" -type "componentList" 1 "e[12:23]";
	setAttr ".pv" -type "double2" 0.4609375 0.22078323364257812 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 52 ".uvst[0].uvsp[0:51]" -type "float2" 0.63531649 0.078125
		 0.578125 0.020933539 0.5 0 0.421875 0.020933539 0.36468354 0.078125 0.34375 0.15625
		 0.36468354 0.234375 0.421875 0.29156646 0.5 0.3125 0.578125 0.29156646 0.63531649
		 0.234375 0.65625 0.15625 0.375 0.3125 0.39583334 0.3125 0.41666669 0.3125 0.43750003
		 0.3125 0.45833337 0.3125 0.47916672 0.3125 0.50000006 0.3125 0.52083337 0.3125 0.54166669
		 0.3125 0.5625 0.3125 0.58333331 0.3125 0.60416663 0.3125 0.62499994 0.3125 0.375
		 0.68843985 0.39583334 0.68843985 0.41666669 0.68843985 0.43750003 0.68843985 0.45833337
		 0.68843985 0.47916672 0.68843985 0.50000006 0.68843985 0.52083337 0.68843985 0.54166669
		 0.68843985 0.5625 0.68843985 0.58333331 0.68843985 0.60416663 0.68843985 0.62499994
		 0.68843985 0.63531649 0.765625 0.578125 0.70843351 0.5 0.6875 0.421875 0.70843351
		 0.36468354 0.765625 0.34375 0.84375 0.36468354 0.921875 0.421875 0.97906649 0.5 1
		 0.578125 0.97906649 0.63531649 0.921875 0.65625 0.84375 0.5 0.15000001 0.5 0.83749998;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 24 ".pt[0:23]" -type "float3"  0 6.821629 0 0 6.821629 0 
		0 6.821629 0 0 6.821629 0 0 6.821629 0 0 6.821629 0 0 6.821629 0 0 6.821629 0 0 6.821629 
		0 0 6.821629 0 0 6.821629 0 0 6.821629 0 0 4.8956456 0 0 4.8956456 0 0 4.8956456 
		0 0 4.8956456 0 0 4.8956456 0 0 4.8956456 0 0 4.8956456 0 0 4.8956456 0 0 4.8956456 
		0 0 4.8956456 0 0 4.8956456 0 0 4.8956456 0;
	setAttr -s 26 ".vt[0:25]"  25.98076248 -1.5 -15 15 -1.5 -25.98076248
		 0 -1.5 -30 -15 -1.5 -25.98076248 -25.98076248 -1.5 -15 -30 -1.5 0 -25.98076248 -1.5 15
		 -15 -1.5 25.98076248 0 -1.5 30 15 -1.5 25.98076248 25.98076248 -1.5 15 30 -1.5 0
		 25.98076248 1.5 -15 15 1.5 -25.98076248 0 1.5 -30 -15 1.5 -25.98076248 -25.98076248 1.5 -15
		 -30 1.5 0 -25.98076248 1.5 15 -15 1.5 25.98076248 0 1.5 30 15 1.5 25.98076248 25.98076248 1.5 15
		 30 1.5 0 0 -1.5 0 0 1.5 0;
	setAttr -s 60 ".ed[0:59]"  0 1 0 1 2 0 2 3 0 3 4 0 4 5 0 5 6 0 6 7 0
		 7 8 0 8 9 0 9 10 0 10 11 0 11 0 0 12 13 0 13 14 0 14 15 0 15 16 0 16 17 0 17 18 0
		 18 19 0 19 20 0 20 21 0 21 22 0 22 23 0 23 12 0 0 12 0 1 13 0 2 14 0 3 15 0 4 16 0
		 5 17 0 6 18 0 7 19 0 8 20 0 9 21 0 10 22 0 11 23 0 24 0 1 24 1 1 24 2 1 24 3 1 24 4 1
		 24 5 1 24 6 1 24 7 1 24 8 1 24 9 1 24 10 1 24 11 1 12 25 1 13 25 1 14 25 1 15 25 1
		 16 25 1 17 25 1 18 25 1 19 25 1 20 25 1 21 25 1 22 25 1 23 25 1;
	setAttr -s 36 -ch 120 ".fc[0:35]" -type "polyFaces" 
		f 4 0 25 -13 -25
		mu 0 4 12 13 26 25
		f 4 1 26 -14 -26
		mu 0 4 13 14 27 26
		f 4 2 27 -15 -27
		mu 0 4 14 15 28 27
		f 4 3 28 -16 -28
		mu 0 4 15 16 29 28
		f 4 4 29 -17 -29
		mu 0 4 16 17 30 29
		f 4 5 30 -18 -30
		mu 0 4 17 18 31 30
		f 4 6 31 -19 -31
		mu 0 4 18 19 32 31
		f 4 7 32 -20 -32
		mu 0 4 19 20 33 32
		f 4 8 33 -21 -33
		mu 0 4 20 21 34 33
		f 4 9 34 -22 -34
		mu 0 4 21 22 35 34
		f 4 10 35 -23 -35
		mu 0 4 22 23 36 35
		f 4 11 24 -24 -36
		mu 0 4 23 24 37 36
		f 3 -1 -37 37
		mu 0 3 1 0 50
		f 3 -2 -38 38
		mu 0 3 2 1 50
		f 3 -3 -39 39
		mu 0 3 3 2 50
		f 3 -4 -40 40
		mu 0 3 4 3 50
		f 3 -5 -41 41
		mu 0 3 5 4 50
		f 3 -6 -42 42
		mu 0 3 6 5 50
		f 3 -7 -43 43
		mu 0 3 7 6 50
		f 3 -8 -44 44
		mu 0 3 8 7 50
		f 3 -9 -45 45
		mu 0 3 9 8 50
		f 3 -10 -46 46
		mu 0 3 10 9 50
		f 3 -11 -47 47
		mu 0 3 11 10 50
		f 3 -12 -48 36
		mu 0 3 0 11 50
		f 3 12 49 -49
		mu 0 3 48 47 51
		f 3 13 50 -50
		mu 0 3 47 46 51
		f 3 14 51 -51
		mu 0 3 46 45 51
		f 3 15 52 -52
		mu 0 3 45 44 51
		f 3 16 53 -53
		mu 0 3 44 43 51
		f 3 17 54 -54
		mu 0 3 43 42 51
		f 3 18 55 -55
		mu 0 3 42 41 51
		f 3 19 56 -56
		mu 0 3 41 40 51
		f 3 20 57 -57
		mu 0 3 40 39 51
		f 3 21 58 -58
		mu 0 3 39 38 51
		f 3 22 59 -59
		mu 0 3 38 49 51
		f 3 23 48 -60
		mu 0 3 49 48 51;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder2";
	rename -uid "4BA0954B-41A9-8DEE-E9D0-B8B1FC4FB9DF";
	setAttr ".t" -type "double3" -9.5527072384559872 36.668666982077326 12.302835158885754 ;
createNode mesh -n "pCylinderShape2" -p "pCylinder2";
	rename -uid "0AF318A6-448C-4360-CED1-9499D4857191";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 10 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "bottom";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[8:15]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottomRing";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "e[0:7]";
	setAttr ".gtag[2].gtagnm" -type "string" "cylBottomCap";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 2 "vtx[0:7]" "vtx[16]";
	setAttr ".gtag[3].gtagnm" -type "string" "cylBottomRing";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "vtx[0:7]";
	setAttr ".gtag[4].gtagnm" -type "string" "cylSides";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "vtx[0:15]";
	setAttr ".gtag[5].gtagnm" -type "string" "cylTopCap";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 2 "vtx[8:15]" "vtx[17]";
	setAttr ".gtag[6].gtagnm" -type "string" "cylTopRing";
	setAttr ".gtag[6].gtagcmp" -type "componentList" 1 "vtx[8:15]";
	setAttr ".gtag[7].gtagnm" -type "string" "sides";
	setAttr ".gtag[7].gtagcmp" -type "componentList" 1 "f[0:7]";
	setAttr ".gtag[8].gtagnm" -type "string" "top";
	setAttr ".gtag[8].gtagcmp" -type "componentList" 1 "f[16:23]";
	setAttr ".gtag[9].gtagnm" -type "string" "topRing";
	setAttr ".gtag[9].gtagcmp" -type "componentList" 1 "e[8:15]";
	setAttr ".pv" -type "double2" 0.50000014901161194 0.31969016790390015 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 78 ".uvst[0].uvsp[0:77]" -type "float2" 0.61048543 0.73326457
		 0.5 0.6875 0.38951457 0.73326457 0.34375 0.84375 0.38951457 0.95423543 0.5 1 0.61048543
		 0.95423543 0.65625 0.84375 0.5 0.15000001 0.5 0.83749998 0.40625 0.32679048 0.375
		 0.68843985 0.4375 0.32710335 0.40625 0.68843985 0.46875 0.32759812 0.4375 0.68843985
		 0.5 0.32705969 0.46875 0.68843985 0.53125 0.32673997 0.5 0.68843985 0.5625 0.32715985
		 0.53125 0.68843985 0.59375 0.32617125 0.5625 0.68843985 0.625 0.32709676 0.625 0.68843985
		 0.59375 0.68843985 0.61048543 0.04576461 0.5 1.4901161e-08 0.5 2.6530712e-08 0.38951457
		 0.04576458 0.38951457 0.04576458 0.34375 0.15625 0.34375 0.15625 0.38951457 0.26673543
		 0.38951457 0.26673543 0.5 0.3125 0.49999923 0.31249967 0.61048543 0.26673543 0.61048543
		 0.26673543 0.65625 0.15625 0.65625 0.15625004 0.61048543 0.04576458 0.3750006 0.3270863
		 0.625 0.31979838 0.3750003 0.31979316 0.625 0.3125 0.61048543 0.04576458 0.375 0.3125
		 0.60817623 0.049701259 0.40624994 0.31964353 0.5 1.4901161e-08 0.40625 0.3125 0.5001682
		 0.0040255636 0.4375 0.31980136 0.38951457 0.04576458 0.4375 0.3125 0.39192116 0.048999019
		 0.46875 0.32004923 0.34375 0.15625 0.46875 0.3125 0.34762365 0.15622272 0.5 0.31977975
		 0.38951457 0.26673543 0.5 0.3125 0.39189941 0.26351553 0.53125 0.31962016 0.5 0.3125
		 0.53125 0.3125 0.50017303 0.30852345 0.56249994 0.31983137 0.61048543 0.26673543
		 0.5625 0.3125 0.60839808 0.26297781 0.59375012 0.31933111 0.65625 0.15625 0.59375
		 0.3125 0.6507234 0.15627795;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 41 ".pt";
	setAttr ".pt[0]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[1]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[2]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[3]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[4]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[5]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[6]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[7]" -type "float3" 0 0 1.15484e-07 ;
	setAttr ".pt[19]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[20]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[21]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[22]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[24]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[25]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[26]" -type "float3" 0 0 -0.47654182 ;
	setAttr ".pt[27]" -type "float3" 0 0 -0.47654182 ;
	setAttr ".pt[29]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[30]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[31]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[32]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[34]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[35]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[36]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[37]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[39]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[40]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[41]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[42]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[44]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[45]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[46]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[47]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[49]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[50]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[51]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[52]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[54]" -type "float3" 0 0 -0.20779166 ;
	setAttr ".pt[55]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[56]" -type "float3" 0 0 -0.47654194 ;
	setAttr ".pt[57]" -type "float3" 0 0 -0.47654194 ;
	setAttr -s 58 ".vt[0:57]"  2.12132025 17.5 -2.12132072 0 17.5 -3 -2.12132072 17.5 -2.12132072
		 -3 17.5 0 -2.12132072 17.5 2.12132072 0 17.5 3 2.12132025 17.5 2.12132072 3 17.5 0
		 0 17.5 0 2.051055908 -28.72884369 -11.60091877 -0.09703064 -27.96106529 -11.8623085
		 0 -30.85173607 -11.065659523 -2.18827915 -28.88661194 -11.65702343 -2.99766254 -30.96329498 -11.10533237
		 -2.051056862 -32.97462463 -10.53039646 0.097031593 -33.74240112 -10.26901436 2.18827915 -32.81686401 -10.47429276
		 2.99766254 -30.74017715 -11.025989532 2.12114668 -16.13710976 -2.12123394 2.12114334 -16.81650543 -2.12123203
		 2.12113953 -17.49590111 -2.12123013 2.11779165 -18.032512665 -2.57408524 2.11444378 -18.56912231 -3.026941299
		 0 -16.16941261 -3 0 -16.83470535 -3 0 -17.5 -3 -0.0048503876 -18.023000717 -3.44307137
		 -0.0097017288 -18.54600143 -3.88614178 -2.12132072 -16.14095497 -2.12132072 -2.12132072 -16.82047653 -2.12132072
		 -2.12132072 -17.5 -2.12132072 -2.12447739 -18.036857605 -2.57091141 -2.127635 -18.57371521 -3.02050209
		 -3 -16.094402313 0 -3 -16.79720116 0 -3 -17.5 0 -2.99990654 -18.042156219 -0.44720459
		 -2.99981213 -18.58431435 -0.89440823 -2.12132072 -16.14477921 2.12132072 -2.12132072 -16.8223896 2.12132072
		 -2.12132072 -17.5 2.12132072 -2.11886787 -18.040245056 1.67962646 -2.11641502 -18.58049202 1.23793316
		 0 -16.17425919 3 0 -16.83712959 3 0 -17.5 3 0.0031604767 -18.02907753 2.56777763
		 0.0063209534 -18.55815506 2.13555431 2.12132025 -16.13551521 2.12132072 2.12132025 -16.81775665 2.12132072
		 2.12132025 -17.5 2.12132072 2.12366629 -18.036678314 1.67998981 2.12601233 -18.57335854 1.23865891
		 3.0001745224 -16.23115921 -8.7738037e-05 3.00017786026 -16.86763 -8.9645386e-05 3.00018119812 -17.50409889 -9.059906e-05
		 3.000065803528 -18.10900307 -0.50398636 2.99995089 -18.71390724 -1.0078830719;
	setAttr -s 120 ".ed[0:119]"  0 1 0 1 2 0 2 3 0 3 4 0 4 5 0 5 6 0 6 7 0
		 7 0 0 0 8 1 1 8 1 2 8 1 3 8 1 4 8 1 5 8 1 6 8 1 7 8 1 9 10 0 11 9 1 11 10 1 10 12 0
		 11 12 1 12 13 0 11 13 1 13 14 0 11 14 1 14 15 0 11 15 1 15 16 0 11 16 1 16 17 0 11 17 1
		 17 9 0 24 23 0 23 18 1 25 24 0 26 25 0 22 27 1 27 26 0 22 21 0 57 22 1 21 20 0 20 19 0
		 19 18 0 18 53 1 29 28 0 28 23 1 30 29 0 31 30 0 27 32 1 32 31 0 34 33 0 33 28 1 35 34 0
		 36 35 0 32 37 1 37 36 0 39 38 0 38 33 1 40 39 0 41 40 0 37 42 1 42 41 0 44 43 0 43 38 1
		 45 44 0 46 45 0 42 47 1 47 46 0 49 48 0 48 43 1 50 49 0 51 50 0 47 52 1 52 51 0 54 53 0
		 53 48 1 55 54 0 56 55 0 52 57 1 57 56 0 23 1 0 0 18 0 28 2 0 33 3 0 38 4 0 43 5 0
		 48 6 0 53 7 0 22 9 0 10 27 0 12 32 0 13 37 0 14 42 0 15 47 0 16 52 0 17 57 0 21 26 1
		 20 25 0 19 24 1 26 31 1 25 30 0 24 29 1 31 36 1 30 35 1 29 34 1 36 41 1 35 40 1 34 39 1
		 41 46 1 40 45 0 39 44 1 46 51 1 45 50 0 44 49 1 51 56 1 50 55 1 49 54 1 21 56 1 20 55 1
		 19 54 1;
	setAttr -s 64 -ch 240 ".fc[0:63]" -type "polyFaces" 
		f 3 -17 -18 18
		mu 0 3 28 42 8
		f 3 -20 -19 20
		mu 0 3 30 28 8
		f 3 -22 -21 22
		mu 0 3 32 30 8
		f 3 -24 -23 24
		mu 0 3 34 32 8
		f 3 -26 -25 26
		mu 0 3 36 34 8
		f 3 -28 -27 28
		mu 0 3 38 36 8
		f 3 -30 -29 30
		mu 0 3 40 38 8
		f 3 -32 -31 17
		mu 0 3 42 40 8
		f 3 0 9 -9
		mu 0 3 6 5 9
		f 3 1 10 -10
		mu 0 3 5 4 9
		f 3 2 11 -11
		mu 0 3 4 3 9
		f 3 3 12 -12
		mu 0 3 3 2 9
		f 3 4 13 -13
		mu 0 3 2 1 9
		f 3 5 14 -14
		mu 0 3 1 0 9
		f 3 6 15 -15
		mu 0 3 0 7 9
		f 3 7 8 -16
		mu 0 3 7 6 9
		f 4 -34 80 -1 81
		mu 0 4 43 10 13 11
		f 4 -46 82 -2 -81
		mu 0 4 10 12 15 13
		f 4 -52 83 -3 -83
		mu 0 4 12 14 17 15
		f 4 -58 84 -4 -84
		mu 0 4 14 16 19 17
		f 4 -64 85 -5 -85
		mu 0 4 16 18 21 19
		f 4 -70 86 -6 -86
		mu 0 4 18 20 23 21
		f 4 -76 87 -7 -87
		mu 0 4 20 22 26 23
		f 4 -44 -82 -8 -88
		mu 0 4 22 24 25 26
		f 4 -37 88 16 89
		mu 0 4 29 27 42 28
		f 4 -49 -90 19 90
		mu 0 4 31 29 28 30
		f 4 -55 -91 21 91
		mu 0 4 33 31 30 32
		f 4 -61 -92 23 92
		mu 0 4 35 33 32 34
		f 4 -67 -93 25 93
		mu 0 4 37 35 34 36
		f 4 -73 -94 27 94
		mu 0 4 39 37 36 38
		f 4 -79 -95 29 95
		mu 0 4 41 39 38 40
		f 4 -40 -96 31 -89
		mu 0 4 27 41 40 42
		f 4 -39 36 37 -97
		mu 0 4 49 27 29 53
		f 4 -41 96 35 -98
		mu 0 4 47 49 53 51
		f 4 -43 98 32 33
		mu 0 4 43 45 50 10
		f 4 -42 97 34 -99
		mu 0 4 45 48 52 50
		f 4 -38 48 49 -100
		mu 0 4 53 29 31 57
		f 4 -36 99 47 -101
		mu 0 4 51 53 57 55
		f 4 -33 101 44 45
		mu 0 4 10 50 54 12
		f 4 -35 100 46 -102
		mu 0 4 50 52 56 54
		f 4 -50 54 55 -103
		mu 0 4 57 31 33 61
		f 4 -48 102 53 -104
		mu 0 4 55 57 61 59
		f 4 -45 104 50 51
		mu 0 4 12 54 58 14
		f 4 -47 103 52 -105
		mu 0 4 54 56 60 58
		f 4 -56 60 61 -106
		mu 0 4 61 33 35 65
		f 4 -54 105 59 -107
		mu 0 4 59 61 65 63
		f 4 -51 107 56 57
		mu 0 4 14 58 62 16
		f 4 -53 106 58 -108
		mu 0 4 58 60 64 62
		f 4 -62 66 67 -109
		mu 0 4 65 35 37 69
		f 4 -60 108 65 -110
		mu 0 4 63 65 69 67
		f 4 -57 110 62 63
		mu 0 4 16 62 66 18
		f 4 -59 109 64 -111
		mu 0 4 62 64 68 66
		f 4 -68 72 73 -112
		mu 0 4 69 37 39 73
		f 4 -66 111 71 -113
		mu 0 4 67 69 73 71
		f 4 -63 113 68 69
		mu 0 4 18 66 70 20
		f 4 -65 112 70 -114
		mu 0 4 66 68 72 70
		f 4 -74 78 79 -115
		mu 0 4 73 39 41 77
		f 4 -72 114 77 -116
		mu 0 4 71 73 77 75
		f 4 -69 116 74 75
		mu 0 4 20 70 74 22
		f 4 -71 115 76 -117
		mu 0 4 70 72 76 74
		f 4 38 117 -80 39
		mu 0 4 27 49 77 41
		f 4 40 118 -78 -118
		mu 0 4 49 47 75 77
		f 4 41 119 -77 -119
		mu 0 4 46 44 74 76
		f 4 42 43 -75 -120
		mu 0 4 44 24 22 74;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".dr" 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube1";
	rename -uid "C88029A0-43EA-F9A9-0B9F-51AEDD42BCF5";
	setAttr ".t" -type "double3" -9.5242715538536409 44.15986658012428 18.855882249026777 ;
	setAttr ".r" -type "double3" 63.151653992455905 0 0 ;
createNode mesh -n "pCubeShape1" -p "pCube1";
	rename -uid "330629C0-4FBD-2774-CEC6-4EA3E210B883";
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
	setAttr ".pv" -type "double2" 0.5 0.125 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 30 ".uvst[0].uvsp[0:29]" -type "float2" 0.375 0 0.625 0 0.375
		 0.25 0.625 0.25 0.375 0.5 0.625 0.5 0.375 0.75 0.625 0.75 0.375 1 0.625 1 0.875 0
		 0.875 0.25 0.125 0 0.125 0.25 0.625 0.89051473 0.73448533 0 0.2655147 0 0.375 0.89051473
		 0.2655147 0.25 0.375 0.3594853 0.625 0.3594853 0.73448533 0.25 0.375 0 0.625 0 0.625
		 0.25 0.375 0.25 0.375 0 0.625 0 0.625 0.25 0.375 0.25;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 20 ".vt[0:19]"  -3.32973099 2.78872299 13.95725441 3.29065704 2.86138153 13.96386147
		 -3.34157181 3.89115524 13.69884872 3.27881527 3.96381378 13.70545578 -3.31039524 0.566185 -16.72309685
		 3.31039476 0.566185 -16.72309685 -3.31039524 -0.566185 -16.72310066 3.31039476 -0.566185 -16.72310066
		 3.34157181 -0.48080444 -0.29711342 -3.27881527 -0.5534668 -0.30372238 -3.29065704 0.54896545 -0.56212997
		 3.32973099 0.62162781 -0.55552483 -3.34191895 5.4421463 21.66544533 3.2771368 5.52285385 21.79370308
		 3.29100323 6.0099754333 20.77154922 -3.32805157 5.92926788 20.64329147 -3.34191895 26.98991966 21.84482384
		 3.2771368 27.070627213 21.97308159 3.29100323 27.55774879 20.95092773 -3.32805157 27.47704124 20.82266998;
	setAttr -s 36 ".ed[0:35]"  0 1 0 2 3 0 4 5 0 6 7 0 0 2 0 1 3 0 2 10 0
		 3 11 0 4 6 0 5 7 0 6 9 0 7 8 0 8 1 0 9 0 0 8 9 1 10 4 0 9 10 1 11 5 0 10 11 1 11 8 1
		 0 12 0 1 13 0 12 13 0 3 14 0 13 14 0 2 15 0 15 14 0 12 15 0 12 16 0 13 17 0 16 17 0
		 14 18 0 17 18 0 15 19 0 19 18 0 16 19 0;
	setAttr -s 17 -ch 68 ".fc[0:16]" -type "polyFaces" 
		f 4 18 17 -3 -16
		mu 0 4 19 20 5 4
		f 4 2 9 -4 -9
		mu 0 4 4 5 7 6
		f 4 3 11 14 -11
		mu 0 4 6 7 14 17
		f 4 19 -12 -10 -18
		mu 0 4 21 15 10 11
		f 4 10 16 15 8
		mu 0 4 12 16 18 13
		f 4 -15 12 -1 -14
		mu 0 4 17 14 9 8
		f 4 -17 13 4 6
		mu 0 4 18 16 0 2
		f 4 1 7 -19 -7
		mu 0 4 2 3 20 19
		f 4 -13 -20 -8 -6
		mu 0 4 1 15 21 3
		f 4 0 21 -23 -21
		mu 0 4 0 1 23 22
		f 4 5 23 -25 -22
		mu 0 4 1 3 24 23
		f 4 -2 25 26 -24
		mu 0 4 3 2 25 24
		f 4 -5 20 27 -26
		mu 0 4 2 0 22 25
		f 4 22 29 -31 -29
		mu 0 4 22 23 27 26
		f 4 24 31 -33 -30
		mu 0 4 23 24 28 27
		f 4 -27 33 34 -32
		mu 0 4 24 25 29 28
		f 4 -28 28 35 -34
		mu 0 4 25 22 26 29;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube2";
	rename -uid "7437FEFB-48BF-488C-2A46-CA8A3B042A80";
	setAttr ".t" -type "double3" -9.6539909325554341 39.844197899311304 55.515549931810725 ;
	setAttr ".r" -type "double3" 114.45809949555519 0 0 ;
createNode mesh -n "pCubeShape2" -p "pCube2";
	rename -uid "0E6329CE-4060-E43D-9121-6B833A225D28";
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
	setAttr ".pv" -type "double2" 0.50000001490116119 0.62499994039535522 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 18 ".uvst[0].uvsp[0:17]" -type "float2" 0.375 0 0.625 0.25
		 0.375 0.4791953 0.625 0.7708047 0.625 1 0.375 1 0.14580473 0.24999982 0.1458047 3.7252903e-09
		 0.375 0.24999982 0.3999975 0.75 0.60000247 0.49999988 0.62500006 -5.7312484e-09 0.85419524
		 9.3132257e-09 0.8541953 0.24999982 0.3999975 0.49999988 0.375 0.7708047 0.62500006
		 0.4791953 0.60000253 0.75;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".pt";
	setAttr ".pt[5]" -type "float3" 0 -5.2154064e-08 -2.3841858e-07 ;
	setAttr ".pt[7]" -type "float3" 0 -5.2154064e-08 -2.3841858e-07 ;
	setAttr ".pt[8]" -type "float3" 0 -5.2154064e-08 -2.3841858e-07 ;
	setAttr ".pt[11]" -type "float3" 0 -5.2154064e-08 -2.3841858e-07 ;
	setAttr -s 12 ".vt[0:11]"  -5.74544048 -1.98550415 6.90335083 5.74544048 -1.98550415 6.90335083
		 -5.74544048 1.98549652 6.90335083 5.74544048 1.98549652 6.90335083 -5.74544048 1.98549652 -5.75437164
		 -4.59646702 1.98549652 -6.90333557 -5.74544048 -1.98550415 -5.75437164 -4.59646702 -1.98549652 -6.90335083
		 4.59646749 1.98549652 -6.90333557 5.74544048 1.98549652 -5.75437164 5.74544048 -1.98550415 -5.75437164
		 4.59646749 -1.98549652 -6.90335083;
	setAttr -s 20 ".ed[0:19]"  0 1 0 2 3 0 0 2 0 1 3 0 2 4 0 3 9 0 5 8 0
		 5 4 0 6 0 0 7 11 0 7 6 0 9 8 0 10 1 0 11 10 0 4 6 0 7 5 0 8 11 0 10 9 0 4 9 1 10 6 1;
	setAttr -s 10 -ch 40 ".fc[0:9]" -type "polyFaces" 
		f 4 0 3 -2 -3
		mu 0 4 0 11 1 8
		f 4 18 11 -7 7
		mu 0 4 2 16 10 14
		f 4 15 6 16 -10
		mu 0 4 9 14 10 17
		f 4 -13 17 -6 -4
		mu 0 4 11 12 13 1
		f 4 14 8 2 4
		mu 0 4 6 7 0 8
		f 4 -11 9 13 19
		mu 0 4 15 9 17 3
		f 4 -8 -16 10 -15
		mu 0 4 2 14 9 15
		f 4 -12 -18 -14 -17
		mu 0 4 10 16 3 17
		f 4 1 5 -19 -5
		mu 0 4 8 1 16 2
		f 4 -20 12 -1 -9
		mu 0 4 15 3 4 5;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder3";
	rename -uid "3224E340-46B6-4A50-FD56-1D8F02DAE3D7";
	setAttr ".t" -type "double3" -9.4506869803073332 44.71110006658278 54.544848092538899 ;
	setAttr ".r" -type "double3" -65.541900504444811 0 0 ;
createNode mesh -n "pCylinderShape3" -p "pCylinder3";
	rename -uid "40F7A2B3-49D4-6F12-E3D5-8091E4E2730E";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 10 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "bottom";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[8:15]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottomRing";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "e[0:7]";
	setAttr ".gtag[2].gtagnm" -type "string" "cylBottomCap";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 2 "vtx[0:7]" "vtx[16]";
	setAttr ".gtag[3].gtagnm" -type "string" "cylBottomRing";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "vtx[0:7]";
	setAttr ".gtag[4].gtagnm" -type "string" "cylSides";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "vtx[0:15]";
	setAttr ".gtag[5].gtagnm" -type "string" "cylTopCap";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 2 "vtx[8:15]" "vtx[17]";
	setAttr ".gtag[6].gtagnm" -type "string" "cylTopRing";
	setAttr ".gtag[6].gtagcmp" -type "componentList" 1 "vtx[8:15]";
	setAttr ".gtag[7].gtagnm" -type "string" "sides";
	setAttr ".gtag[7].gtagcmp" -type "componentList" 1 "f[0:7]";
	setAttr ".gtag[8].gtagnm" -type "string" "top";
	setAttr ".gtag[8].gtagcmp" -type "componentList" 1 "f[16:23]";
	setAttr ".gtag[9].gtagnm" -type "string" "topRing";
	setAttr ".gtag[9].gtagcmp" -type "componentList" 1 "e[8:15]";
	setAttr ".pv" -type "double2" 0.609375 0.50046992301940918 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 50 ".uvst[0].uvsp[0:49]" -type "float2" 0.375 0.3125 0.40625
		 0.3125 0.4375 0.3125 0.46875 0.3125 0.5 0.3125 0.53125 0.3125 0.5625 0.3125 0.59375
		 0.3125 0.625 0.3125 0.375 0.68843985 0.40625 0.68843985 0.4375 0.68843985 0.46875
		 0.68843985 0.5 0.68843985 0.53125 0.68843985 0.5625 0.68843985 0.59375 0.68843985
		 0.625 0.68843985 0.61048543 0.73326457 0.5 0.6875 0.38951457 0.73326457 0.34375 0.84375
		 0.38951457 0.95423543 0.5 1 0.61048543 0.95423543 0.65625 0.84375 0.65625 0.84375
		 0.61048543 0.95423543 0.5 1 0.38951457 0.95423543 0.34375 0.84375 0.38951457 0.73326457
		 0.5 0.6875 0.61048543 0.73326457 0.65625 0.84375 0.61048543 0.95423543 0.5 1 0.38951457
		 0.95423543 0.34375 0.84375 0.38951457 0.73326457 0.5 0.6875 0.61048543 0.73326457
		 0.65625 0.84375 0.61048543 0.95423543 0.5 1 0.38951457 0.95423543 0.34375 0.84375
		 0.38951457 0.73326457 0.5 0.6875 0.61048543 0.73326457;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 10 ".pt";
	setAttr ".pt[32]" -type "float3" 0 0.94224292 -6.2450045e-15 ;
	setAttr ".pt[33]" -type "float3" 0 0.94224292 -5.1070259e-15 ;
	setAttr ".pt[34]" -type "float3" 0 0.94224292 -5.1070259e-15 ;
	setAttr ".pt[35]" -type "float3" 0 0.94224292 -5.1070259e-15 ;
	setAttr ".pt[36]" -type "float3" 0 0.94224292 -6.2450045e-15 ;
	setAttr ".pt[37]" -type "float3" 0 0.94224292 -5.1070259e-15 ;
	setAttr ".pt[38]" -type "float3" 0 0.94224292 -5.1070259e-15 ;
	setAttr ".pt[39]" -type "float3" 0 0.94224292 -5.1070259e-15 ;
	setAttr -s 40 ".vt[0:39]"  1.060660362 -2.000007629395 -1.060657501
		 0 -2 -1.49998474 -1.060660362 -2.000007629395 -1.060657501 -1.5 -2 7.6293945e-06
		 -1.060660362 -2 1.060657501 0 -2 1.50000381 1.060660362 -2 1.060657501 1.5 -2 7.6293945e-06
		 1.060660362 1.99999046 -1.060653687 0 2 -1.49998856 -1.060660362 1.99999046 -1.060653687
		 -1.5 2.000005722046 1.1444092e-05 -1.060660362 1.99999428 1.06067276 0 1.99999428 1.50001907
		 1.060660362 1.99999428 1.06067276 1.5 2.000005722046 1.1444092e-05 1.5 2.000005722046 1.1444092e-05
		 1.060660362 1.99999046 -1.060653687 0 1.99999619 -1.49998856 -1.060660362 1.99999046 -1.060653687
		 -1.5 2.000005722046 1.1444092e-05 -1.060660362 1.99999428 1.06067276 0 1.99999428 1.50001907
		 1.060660362 1.99999428 1.06067276 1.93893623 2.000003814697 7.6293945e-06 1.37103462 1.99999237 -1.3710289
		 0 1.99999809 -1.93893051 -1.37103462 1.99999237 -1.3710289 -1.93893623 2.000003814697 7.6293945e-06
		 -1.37103462 1.99999428 1.37105179 0 1.99999237 1.9389534 1.37103462 1.99999428 1.37105179
		 1.93893623 2.000003814697 7.6293945e-06 1.37103462 1.99999237 -1.3710289 0 1.99999809 -1.93893051
		 -1.37103462 1.99999237 -1.3710289 -1.93893623 2.000003814697 7.6293945e-06 -1.37103462 1.99999428 1.37105179
		 0 1.99999237 1.9389534 1.37103462 1.99999428 1.37105179;
	setAttr -s 72 ".ed[0:71]"  0 1 0 1 2 0 2 3 0 3 4 0 4 5 0 5 6 0 6 7 0
		 7 0 0 8 9 0 9 10 0 10 11 0 11 12 0 12 13 0 13 14 0 14 15 0 15 8 0 0 8 0 1 9 0 2 10 0
		 3 11 0 4 12 0 5 13 0 6 14 0 7 15 0 15 16 0 8 17 0 16 17 0 9 18 0 17 18 0 10 19 0
		 18 19 0 11 20 0 19 20 0 12 21 0 20 21 0 13 22 0 21 22 0 14 23 0 22 23 0 23 16 0 16 24 0
		 17 25 0 24 25 0 18 26 0 25 26 0 19 27 0 26 27 0 20 28 0 27 28 0 21 29 0 28 29 0 22 30 0
		 29 30 0 23 31 0 30 31 0 31 24 0 24 32 0 25 33 0 32 33 0 26 34 0 33 34 0 27 35 0 34 35 0
		 28 36 0 35 36 0 29 37 0 36 37 0 30 38 0 37 38 0 31 39 0 38 39 0 39 32 0;
	setAttr -s 33 -ch 136 ".fc[0:32]" -type "polyFaces" 
		f 4 0 17 -9 -17
		mu 0 4 0 1 10 9
		f 4 1 18 -10 -18
		mu 0 4 1 2 11 10
		f 4 2 19 -11 -19
		mu 0 4 2 3 12 11
		f 4 3 20 -12 -20
		mu 0 4 3 4 13 12
		f 4 4 21 -13 -21
		mu 0 4 4 5 14 13
		f 4 5 22 -14 -22
		mu 0 4 5 6 15 14
		f 4 6 23 -15 -23
		mu 0 4 6 7 16 15
		f 4 7 16 -16 -24
		mu 0 4 7 8 17 16
		f 8 58 60 62 64 66 68 70 71
		mu 0 8 42 43 44 45 46 47 48 49
		f 4 15 25 -27 -25
		mu 0 4 25 24 27 26
		f 4 8 27 -29 -26
		mu 0 4 24 23 28 27
		f 4 9 29 -31 -28
		mu 0 4 23 22 29 28
		f 4 10 31 -33 -30
		mu 0 4 22 21 30 29
		f 4 11 33 -35 -32
		mu 0 4 21 20 31 30
		f 4 12 35 -37 -34
		mu 0 4 20 19 32 31
		f 4 13 37 -39 -36
		mu 0 4 19 18 33 32
		f 4 14 24 -40 -38
		mu 0 4 18 25 26 33
		f 4 26 41 -43 -41
		mu 0 4 26 27 35 34
		f 4 28 43 -45 -42
		mu 0 4 27 28 36 35
		f 4 30 45 -47 -44
		mu 0 4 28 29 37 36
		f 4 32 47 -49 -46
		mu 0 4 29 30 38 37
		f 4 34 49 -51 -48
		mu 0 4 30 31 39 38
		f 4 36 51 -53 -50
		mu 0 4 31 32 40 39
		f 4 38 53 -55 -52
		mu 0 4 32 33 41 40
		f 4 39 40 -56 -54
		mu 0 4 33 26 34 41
		f 4 42 57 -59 -57
		mu 0 4 34 35 43 42
		f 4 44 59 -61 -58
		mu 0 4 35 36 44 43
		f 4 46 61 -63 -60
		mu 0 4 36 37 45 44
		f 4 48 63 -65 -62
		mu 0 4 37 38 46 45
		f 4 50 65 -67 -64
		mu 0 4 38 39 47 46
		f 4 52 67 -69 -66
		mu 0 4 39 40 48 47
		f 4 54 69 -71 -68
		mu 0 4 40 41 49 48
		f 4 55 56 -72 -70
		mu 0 4 41 34 42 49;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder4";
	rename -uid "409CAED0-44BA-1408-8FEC-C487FE8E8C67";
	setAttr ".t" -type "double3" -6.0697441333612447 2.7909049491322371 0.48182178510267981 ;
	setAttr ".r" -type "double3" 0 0 -90.112528591845091 ;
	setAttr ".s" -type "double3" 1.4055970718845265 1.4055970718845265 1.4055970718845265 ;
createNode mesh -n "pCylinderShape4" -p "pCylinder4";
	rename -uid "BC4D48E6-4869-0D3D-0E23-52BD68528E91";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 10 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "bottom";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[8:15]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottomRing";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "e[0:7]";
	setAttr ".gtag[2].gtagnm" -type "string" "cylBottomCap";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 2 "vtx[0:7]" "vtx[16]";
	setAttr ".gtag[3].gtagnm" -type "string" "cylBottomRing";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "vtx[0:7]";
	setAttr ".gtag[4].gtagnm" -type "string" "cylSides";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "vtx[0:15]";
	setAttr ".gtag[5].gtagnm" -type "string" "cylTopCap";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 2 "vtx[8:15]" "vtx[17]";
	setAttr ".gtag[6].gtagnm" -type "string" "cylTopRing";
	setAttr ".gtag[6].gtagcmp" -type "componentList" 1 "vtx[8:15]";
	setAttr ".gtag[7].gtagnm" -type "string" "sides";
	setAttr ".gtag[7].gtagcmp" -type "componentList" 1 "f[0:7]";
	setAttr ".gtag[8].gtagnm" -type "string" "top";
	setAttr ".gtag[8].gtagcmp" -type "componentList" 1 "f[16:23]";
	setAttr ".gtag[9].gtagnm" -type "string" "topRing";
	setAttr ".gtag[9].gtagcmp" -type "componentList" 1 "e[8:15]";
	setAttr ".pv" -type "double2" 0.515625 0.5000000074505806 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 22 ".uvst[0].uvsp[0:21]" -type "float2" 0.5 1.4901161e-08
		 0.38951457 0.04576458 0.34375 0.15625 0.38951457 0.26673543 0.5 0.3125 0.40625 0.3125
		 0.4375 0.3125 0.46875 0.3125 0.5 0.3125 0.53125 0.3125 0.40625 0.68843985 0.4375
		 0.68843985 0.46875 0.68843985 0.5 0.68843985 0.53125 0.68843985 0.5 0.6875 0.38951457
		 0.73326457 0.34375 0.84375 0.38951457 0.95423543 0.5 1 0.5 0.15000001 0.5 0.83749998;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 12 ".vt[0:11]"  0 -0.34364286 -4.29943037 -3.040156364 -0.34364286 -3.040156364
		 -4.29943037 -0.34364286 0 -3.040156364 -0.34364286 3.040156364 0 -0.34364286 4.29943037
		 0 0.34364286 -4.29943037 -3.040156364 0.34364286 -3.040156364 -4.29943037 0.34364286 0
		 -3.040156364 0.34364286 3.040156364 0 0.34364286 4.29943037 0 -0.34364286 0 0 0.34364286 0;
	setAttr -s 23 ".ed[0:22]"  0 1 0 1 2 0 2 3 0 3 4 0 5 6 0 6 7 0 7 8 0
		 8 9 0 0 5 0 1 6 0 2 7 0 3 8 0 4 9 0 10 0 1 10 1 1 10 2 1 10 3 1 10 4 1 5 11 1 6 11 1
		 7 11 1 8 11 1 9 11 1;
	setAttr -s 12 -ch 40 ".fc[0:11]" -type "polyFaces" 
		f 4 0 9 -5 -9
		mu 0 4 5 6 11 10
		f 4 1 10 -6 -10
		mu 0 4 6 7 12 11
		f 4 2 11 -7 -11
		mu 0 4 7 8 13 12
		f 4 3 12 -8 -12
		mu 0 4 8 9 14 13
		f 3 -1 -14 14
		mu 0 3 1 0 20
		f 3 -2 -15 15
		mu 0 3 2 1 20
		f 3 -3 -16 16
		mu 0 3 3 2 20
		f 3 -4 -17 17
		mu 0 3 4 3 20
		f 3 4 19 -19
		mu 0 3 19 18 21
		f 3 5 20 -20
		mu 0 3 18 17 21
		f 3 6 21 -21
		mu 0 3 17 16 21
		f 3 7 22 -22
		mu 0 3 16 15 21;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder5";
	rename -uid "B5121EFD-4D4D-5189-0D8C-CFAEE813593A";
	setAttr ".t" -type "double3" -13.222082023798665 2.8049521189741564 0.48182178510267987 ;
	setAttr ".r" -type "double3" 0 0 -90.112528591845091 ;
	setAttr ".s" -type "double3" 1.4055970718845265 1.4055970718845265 1.4055970718845265 ;
createNode mesh -n "pCylinderShape5" -p "pCylinder5";
	rename -uid "E68D7343-4DE3-1EEE-C6E9-E3AEAB50DFA1";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.515625 0.5000000074505806 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 22 ".uvst[0].uvsp[0:21]" -type "float2" 0.5 1.4901161e-08
		 0.38951457 0.04576458 0.34375 0.15625 0.38951457 0.26673543 0.5 0.3125 0.40625 0.3125
		 0.4375 0.3125 0.46875 0.3125 0.5 0.3125 0.53125 0.3125 0.40625 0.68843985 0.4375
		 0.68843985 0.46875 0.68843985 0.5 0.68843985 0.53125 0.68843985 0.5 0.6875 0.38951457
		 0.73326457 0.34375 0.84375 0.38951457 0.95423543 0.5 1 0.5 0.15000001 0.5 0.83749998;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 12 ".vt[0:11]"  0 -0.34364286 -4.29943037 -3.040156364 -0.34364286 -3.040156364
		 -4.29943037 -0.34364286 0 -3.040156364 -0.34364286 3.040156364 0 -0.34364286 4.29943037
		 0 0.34364286 -4.29943037 -3.040156364 0.34364286 -3.040156364 -4.29943037 0.34364286 0
		 -3.040156364 0.34364286 3.040156364 0 0.34364286 4.29943037 0 -0.34364286 0 0 0.34364286 0;
	setAttr -s 23 ".ed[0:22]"  0 1 0 1 2 0 2 3 0 3 4 0 5 6 0 6 7 0 7 8 0
		 8 9 0 0 5 0 1 6 0 2 7 0 3 8 0 4 9 0 10 0 1 10 1 1 10 2 1 10 3 1 10 4 1 5 11 1 6 11 1
		 7 11 1 8 11 1 9 11 1;
	setAttr -s 12 -ch 40 ".fc[0:11]" -type "polyFaces" 
		f 4 0 9 -5 -9
		mu 0 4 5 6 11 10
		f 4 1 10 -6 -10
		mu 0 4 6 7 12 11
		f 4 2 11 -7 -11
		mu 0 4 7 8 13 12
		f 4 3 12 -8 -12
		mu 0 4 8 9 14 13
		f 3 -1 -14 14
		mu 0 3 1 0 20
		f 3 -2 -15 15
		mu 0 3 2 1 20
		f 3 -3 -16 16
		mu 0 3 3 2 20
		f 3 -4 -17 17
		mu 0 3 4 3 20
		f 3 4 19 -19
		mu 0 3 19 18 21
		f 3 5 20 -20
		mu 0 3 18 17 21
		f 3 6 21 -21
		mu 0 3 17 16 21
		f 3 7 22 -22
		mu 0 3 16 15 21;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCube3";
	rename -uid "3CB1E0C7-4771-C918-B25A-0088ED9431C4";
	setAttr ".t" -type "double3" -9.6119135883381279 2.6966119664353556 0.34736479728425307 ;
	setAttr ".s" -type "double3" 1.4333333490424387 1 1 ;
createNode mesh -n "pCubeShape3" -p "pCube3";
	rename -uid "E7528CDC-4383-F868-5B3A-C4970C39D8D5";
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
	setAttr -s 8 ".vt[0:7]"  -2.87939358 -0.18967141 6.4800725 2.87939358 -0.18967141 6.4800725
		 -2.87939358 0.18967141 6.4800725 2.87939358 0.18967141 6.4800725 -2.87939358 0.18967141 -6.4800725
		 2.87939358 0.18967141 -6.4800725 -2.87939358 -0.18967141 -6.4800725 2.87939358 -0.18967141 -6.4800725;
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
	rename -uid "FF4D8544-48B2-C785-DA64-E2B2E9F2FDC3";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "D55D6702-4810-D0CE-189D-BB88734E5C2B";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "D7E2EA2F-4FBF-B2A1-A544-BB8492037E9D";
createNode displayLayerManager -n "layerManager";
	rename -uid "93853E9B-4DC6-5F7F-61D3-549EBD3EC961";
createNode displayLayer -n "defaultLayer";
	rename -uid "21E45006-49C3-2DB9-A364-DFB1E47E2EA3";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "018CEC64-494F-2483-6B5B-87A648C1872C";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "132C5878-4393-4EEC-36D0-0B89FFA232FC";
	setAttr ".g" yes;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "35AF0E0D-43BA-EE36-2D02-B9A57C343BC4";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 656\n            -height 326\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n"
		+ "            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 656\n            -height 326\n"
		+ "            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n"
		+ "            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 656\n            -height 326\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1319\n            -height 696\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n"
		+ "            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n"
		+ "            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n"
		+ "            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"0\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n"
		+ "            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n"
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
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1319\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1319\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 10 -size 100 -divisions 1 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "F88DDD1C-4F2D-9B08-5AF7-A38A579F111C";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
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
	setAttr -s 2 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 5 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderingList1;
select -ne :initialShadingGroup;
	setAttr -s 8 ".dsm";
	setAttr ".ro" yes;
select -ne :initialParticleSE;
	setAttr ".ro" yes;
select -ne :defaultRenderGlobals;
	addAttr -ci true -h true -sn "dss" -ln "defaultSurfaceShader" -dt "string";
	setAttr ".ren" -type "string" "arnold";
	setAttr ".dss" -type "string" "lambert1";
select -ne :defaultResolution;
	setAttr ".pa" 1;
select -ne :defaultColorMgtGlobals;
	setAttr ".cfe" yes;
	setAttr ".cfp" -type "string" "<MAYA_RESOURCES>/OCIO-configs/Maya2022-default/config.ocio";
	setAttr ".wsn" -type "string" "ACEScg";
select -ne :hardwareRenderGlobals;
	setAttr ".ctrs" 256;
	setAttr ".btrs" 512;
select -ne :ikSystem;
	setAttr -s 4 ".sol";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "pCylinderShape1.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape2.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape1.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape2.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape3.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape4.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape5.iog" ":initialShadingGroup.dsm" -na;
connectAttr "pCubeShape3.iog" ":initialShadingGroup.dsm" -na;
// End of satellite_dish.ma
