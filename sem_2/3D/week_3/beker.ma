//Maya ASCII 2022 scene
//Name: beker.ma
//Last modified: Fri, Mar 04, 2022 09:31:04 AM
//Codeset: 1252
requires maya "2022";
requires "stereoCamera" "10.0";
requires "mtoa" "4.2.1";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202102181415-29bfc1879c";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19044)";
fileInfo "UUID" "C9C1C056-437B-AB81-BF0B-078E43C26520";
createNode transform -s -n "persp";
	rename -uid "0FF95CA5-475F-E732-9C17-EBBEB752393C";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 2.4643629901068493 54.499898017268166 164.08757941914428 ;
	setAttr ".r" -type "double3" -7.5383527294824555 1081.3999999995317 3.7283254605883734e-17 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "5A6CF2A6-4132-B8C2-A92B-F29CCF4FCA64";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 169.327607455205;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" 0 10.385878004366614 -8.6798505292989603 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "5F167622-4789-BB02-F9C8-398D5B20895E";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -74.893145772098649 1000.1557604195614 -27.634546562028113 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "94DB7F77-4D68-6CD9-5046-DB90F48A5065";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 987.38951976621183;
	setAttr ".ow" 323.96643665965127;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".tp" -type "double3" 10.275150294362781 12.766240653349577 -2.1290103309260786 ;
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "58E03AA2-408B-CB19-830D-0C8A2AD6DBA8";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "A0151ABD-41B8-7EDD-9899-BE8992A0ED4E";
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
	rename -uid "FC6AF6DC-4FBB-A187-D9EA-F18A65611A30";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 34.491856071340393 9.2260884535263799 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "69C18F75-4DA1-BFC7-D1E9-F3A3707C4D25";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 133.24378093030052;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "left";
	rename -uid "DA734D34-42EA-8188-850B-B4B95493C8C2";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -1000.1 8.1797738293083935 -0.13632956382181405 ;
	setAttr ".r" -type "double3" 0 -90 0 ;
createNode camera -n "leftShape" -p "left";
	rename -uid "FEC2D6B3-4C08-66F1-3C5C-FFA279511A8D";
	setAttr -k off ".v";
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 69.308931751297308;
	setAttr ".imn" -type "string" "left1";
	setAttr ".den" -type "string" "left1_depth";
	setAttr ".man" -type "string" "left1_mask";
	setAttr ".hc" -type "string" "viewSet -ls %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "back";
	rename -uid "E9AEDA36-48CF-EC0D-3660-2ABA1FCBD999";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 -1000.1 ;
	setAttr ".r" -type "double3" 0 180 0 ;
createNode camera -n "backShape" -p "back";
	rename -uid "20EA4D0E-4A09-AFFB-637E-26B82A0BE307";
	setAttr -k off ".v";
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 30;
	setAttr ".imn" -type "string" "back1";
	setAttr ".den" -type "string" "back1_depth";
	setAttr ".man" -type "string" "back1_mask";
	setAttr ".hc" -type "string" "viewSet -b %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "pCylinder1";
	rename -uid "16B7EF8B-4567-B8BB-345A-F9812A9C327D";
	setAttr ".t" -type "double3" -60.267880950907227 16.98981585714694 -16.196333583119923 ;
createNode transform -n "transform2" -p "pCylinder1";
	rename -uid "119CC225-4287-CC8D-EC3E-90A77D19DD0B";
	setAttr ".v" no;
createNode mesh -n "pCylinderShape1" -p "transform2";
	rename -uid "3AA6BDA3-4D87-9C89-C7B2-568F85987BAA";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr -s 2 ".iog[0].og";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.84375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 14 ".pt[0:13]" -type "float3"  4.1471224 0 -25.948235 4.1471224 
		0 -25.948235 4.1471224 0 -25.948235 4.1471224 0 -25.948235 4.1471224 0 -25.948235 
		4.1471224 0 -25.948235 4.1471224 0 -25.948235 3.8146973e-06 0 0 3.8146973e-06 0 0 
		3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 
		0 0;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder2";
	rename -uid "809FC9BC-4A2B-0451-22AC-459A9500C0A3";
	setAttr ".t" -type "double3" -60.267880950907227 16.98981585714694 -16.196333583119923 ;
createNode transform -n "transform1" -p "pCylinder2";
	rename -uid "21ADCB99-432E-CC7E-CA3C-8E8DD001BA36";
	setAttr ".v" no;
createNode mesh -n "pCylinderShape2" -p "transform1";
	rename -uid "87E3D1AB-4843-584B-9BC7-0B90B44025B0";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.84375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 7 ".uvst[0].uvsp[0:6]" -type "float2" 0.57812506 0.70843351
		 0.42187503 0.70843351 0.34375 0.84375 0.421875 0.97906649 0.578125 0.97906649 0.65625
		 0.84375 0.5 0.83749998;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 14 ".pt[0:13]" -type "float3"  4.1471224 0 5.307591 4.1471224 
		0 5.307591 4.1471224 0 5.307591 4.1471224 0 5.307591 4.1471224 0 5.307591 4.1471224 
		0 5.307591 4.1471224 0 5.307591 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 
		0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0;
	setAttr -s 7 ".vt[0:6]"  7.52208233 16.98981667 -13.02862072 -7.52207613 16.98981667 -13.028623581
		 -15.044157028 16.98981667 -2.2417541e-06 -7.52208042 16.98981667 13.028621674 7.52207804 16.98981667 13.028622627
		 15.044157028 16.98981667 0 0 16.98981667 0;
	setAttr -s 12 ".ed[0:11]"  0 1 0 1 2 0 2 3 0 3 4 0 4 5 0 5 0 0 0 6 1
		 1 6 1 2 6 1 3 6 1 4 6 1 5 6 1;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 0 7 -7
		mu 0 3 4 3 6
		f 3 1 8 -8
		mu 0 3 3 2 6
		f 3 2 9 -9
		mu 0 3 2 1 6
		f 3 3 10 -10
		mu 0 3 1 0 6
		f 3 4 11 -11
		mu 0 3 0 5 6
		f 3 5 6 -12
		mu 0 3 5 4 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder3";
	rename -uid "28B63755-4F3D-6030-69F3-EF94EFD7AA82";
	setAttr ".t" -type "double3" -91.405759456030538 16.98981585714694 -33.534470478018129 ;
createNode transform -n "transform3" -p "pCylinder3";
	rename -uid "7E8CEFB6-4B3C-3C9A-5B3F-5EB58661365D";
	setAttr ".v" no;
createNode mesh -n "pCylinderShape3" -p "transform3";
	rename -uid "3FB9DD96-445A-8755-1DE3-FEA91273AD6F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.84375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 7 ".uvst[0].uvsp[0:6]" -type "float2" 0.57812506 0.70843351
		 0.42187503 0.70843351 0.34375 0.84375 0.421875 0.97906649 0.578125 0.97906649 0.65625
		 0.84375 0.5 0.83749998;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 14 ".pt[0:13]" -type "float3"  4.1471224 0 5.307591 4.1471224 
		0 5.307591 4.1471224 0 5.307591 4.1471224 0 5.307591 4.1471224 0 5.307591 4.1471224 
		0 5.307591 4.1471224 0 5.307591 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 
		0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0;
	setAttr -s 7 ".vt[0:6]"  7.52208233 16.98981667 -13.02862072 -7.52207613 16.98981667 -13.028623581
		 -15.044157028 16.98981667 -2.2417541e-06 -7.52208042 16.98981667 13.028621674 7.52207804 16.98981667 13.028622627
		 15.044157028 16.98981667 0 0 16.98981667 0;
	setAttr -s 12 ".ed[0:11]"  0 1 0 1 2 0 2 3 0 3 4 0 4 5 0 5 0 0 0 6 1
		 1 6 1 2 6 1 3 6 1 4 6 1 5 6 1;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 0 7 -7
		mu 0 3 4 3 6
		f 3 1 8 -8
		mu 0 3 3 2 6
		f 3 2 9 -9
		mu 0 3 2 1 6
		f 3 3 10 -10
		mu 0 3 1 0 6
		f 3 4 11 -11
		mu 0 3 0 5 6
		f 3 5 6 -12
		mu 0 3 5 4 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "pCylinder4";
	rename -uid "EFA2E80D-414D-5957-8FAA-059806195044";
	setAttr ".t" -type "double3" -91.641652475008755 16.98981585714694 -62.667258321826679 ;
createNode transform -n "transform4" -p "pCylinder4";
	rename -uid "FF7E732E-46EF-B912-DA6F-959BD1A52EA1";
	setAttr ".v" no;
createNode mesh -n "pCylinderShape4" -p "transform4";
	rename -uid "B3C8FE06-4866-A82D-D7F1-7EB055E73DED";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0:5]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.5 0.84375 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 7 ".uvst[0].uvsp[0:6]" -type "float2" 0.57812506 0.70843351
		 0.42187503 0.70843351 0.34375 0.84375 0.421875 0.97906649 0.578125 0.97906649 0.65625
		 0.84375 0.5 0.83749998;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 14 ".pt[0:13]" -type "float3"  4.1471224 0 5.307591 4.1471224 
		0 5.307591 4.1471224 0 5.307591 4.1471224 0 5.307591 4.1471224 0 5.307591 4.1471224 
		0 5.307591 4.1471224 0 5.307591 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 
		0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0 3.8146973e-06 0 0;
	setAttr -s 7 ".vt[0:6]"  7.52208233 16.98981667 -13.02862072 -7.52207613 16.98981667 -13.028623581
		 -15.044157028 16.98981667 -2.2417541e-06 -7.52208042 16.98981667 13.028621674 7.52207804 16.98981667 13.028622627
		 15.044157028 16.98981667 0 0 16.98981667 0;
	setAttr -s 12 ".ed[0:11]"  0 1 0 1 2 0 2 3 0 3 4 0 4 5 0 5 0 0 0 6 1
		 1 6 1 2 6 1 3 6 1 4 6 1 5 6 1;
	setAttr -s 6 -ch 18 ".fc[0:5]" -type "polyFaces" 
		f 3 0 7 -7
		mu 0 3 4 3 6
		f 3 1 8 -8
		mu 0 3 3 2 6
		f 3 2 9 -9
		mu 0 3 2 1 6
		f 3 3 10 -10
		mu 0 3 1 0 6
		f 3 4 11 -11
		mu 0 3 0 5 6
		f 3 5 6 -12
		mu 0 3 5 4 6;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode transform -n "revolvedSurface1";
	rename -uid "94EA6B37-4F75-5D91-286C-1682A0243DF3";
createNode mesh -n "revolvedSurfaceShape1" -p "revolvedSurface1";
	rename -uid "896109CB-4419-714A-12B7-78B3508E3BBF";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.8045201301574707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 114 ".uvst[0].uvsp[0:113]" -type "float2" 0 0 1 0.94445634
		 0.50022894 1 0.50022894 0.44443333 0 0.44443333 0 0.22218867 0.046580881 0 0.046580881
		 0.22218867 0.046580881 0.11108738 0 0.11108738 0.17184928 0 0.17184928 0.11108738
		 0.17184928 0.22218867 0.046580881 0.44443333 0 0.33330524 0.046580881 0.33330524
		 0.17184928 0.33330524 0.17184928 0.44443333 0.50022894 0.22218867 0.35982129 0 0.35982129
		 0.22218867 0.35982129 0.11108738 0.2455865 0 0.2455865 0.11108738 0.2455865 0.22218867
		 0.50022894 0.11108738 0.35982129 0.44443333 0.35982129 0.33330524 0.2455865 0.33330524
		 0.2455865 0.44443333 0.50022894 0.33330524 0 0.66669476 0.046580881 0.66669476 0
		 0.55556667 0.046580881 0.55556667 0.17184928 0.55556667 0.17184928 0.66669476 0 0.77781135
		 0.046580881 0.77781135 0 0.88891262 0.046580881 0.88891262 0.17184928 0.77781135
		 0.17184928 0.88891262 0.50022894 0.66669476 0.35982129 0.66669476 0.35982129 0.55556667
		 0.2455865 0.55556667 0.2455865 0.66669476 0.50022894 0.55556667 0.35982129 0.77781135
		 0.2455865 0.77781135 0.35982129 0.88891262 0.2455865 0.88891262 0.50022894 0.77781135
		 0.50022894 0.88891262 1 0.38886929 0.53230804 0 0.53230804 0.11108738 0.53230804
		 0.22218867 0.60904026 0 0.60904026 0.11108738 0.60904026 0.22218867 0.53230804 0.33330524
		 0.53230804 0.44443333 0.60904026 0.33330524 0.60904026 0.44443333 0.74763489 0 0.74763489
		 0.44443333 0.74763489 0.22218867 0.74763489 0.11108738 0.67952734 0 0.67952734 0.11108738
		 0.67952734 0.22218867 0.74763489 0.33330524 0.67952734 0.33330524 0.67952734 0.44443333
		 1 0.11109201 0.80934221 0 0.80934221 0.22218867 0.80934221 0.11108738 0.80934221
		 0.44443333 0.80934221 0.33330524 0.53230804 0.55556667 0.53230804 0.66669476 0.60904026
		 0.55556667 0.60904026 0.66669476 0.53230804 0.77781135 0.53230804 0.88891262 0.60904026
		 0.77781135 0.60904026 0.88891262 1 0.66669089 0.74763489 0.66669476 0.74763489 0.55556667
		 0.67952734 0.55556667 0.67952734 0.66669476 0.80934221 0.66669476 0.80934221 0.55556667
		 0.74763489 0.77781135 0.67952734 0.77781135 0.74763489 0.88891262 0.67952734 0.88891262
		 0.80934221 0.77781135 0.80934221 0.88891262 0.50022894 0 0.17184928 1 0.046580881
		 1 0 1 0.35982129 1 0.2455865 1 0.60904026 1 0.53230804 1 0.74763489 1 0.67952734
		 1 0.80934221 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 46 ".pt";
	setAttr ".pt[1]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[55]" -type "float3" 0 -2.3841858e-07 0 ;
	setAttr ".pt[56]" -type "float3" 0 -2.3841858e-07 0 ;
	setAttr ".pt[57]" -type "float3" 0 -2.3841858e-07 0 ;
	setAttr ".pt[58]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[59]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[60]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[63]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[64]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[65]" -type "float3" 1.9680939e-16 6.4356027 2.7373509 ;
	setAttr ".pt[66]" -type "float3" -0.96993357 6.4356027 -2.7668624 ;
	setAttr ".pt[67]" -type "float3" -2.7945826 6.4356027 0.39075398 ;
	setAttr ".pt[68]" -type "float3" -1.8247527 6.4356027 2.0726671 ;
	setAttr ".pt[69]" -type "float3" 1.7609278e-16 6.3442135 2.9286659 ;
	setAttr ".pt[70]" -type "float3" -1.9418197 6.3442135 2.2213414 ;
	setAttr ".pt[71]" -type "float3" -2.9738655 6.3442135 0.43152592 ;
	setAttr ".pt[72]" -type "float3" -2.4565365 6.4356027 -1.5202904 ;
	setAttr ".pt[73]" -type "float3" -2.6141334 6.3442135 -1.6021199 ;
	setAttr ".pt[74]" -type "float3" -1.0321589 6.3442135 -2.9286659 ;
	setAttr ".pt[75]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[76]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[77]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[78]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[79]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[82]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[83]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[84]" -type "float3" 0 -2.3841858e-07 0 ;
	setAttr ".pt[85]" -type "float3" 0 -2.3841858e-07 0 ;
	setAttr -av ".pt[85].px";
	setAttr -av ".pt[85].py";
	setAttr -av ".pt[85].pz";
	setAttr ".pt[86]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[87]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[88]" -type "float3" 2.4565365 6.4356027 -1.5202904 ;
	setAttr ".pt[89]" -type "float3" 0.96993357 6.4356027 -2.7668624 ;
	setAttr ".pt[90]" -type "float3" 1.0321589 6.3442135 -2.9286659 ;
	setAttr ".pt[91]" -type "float3" 2.6141334 6.3442135 -1.6021199 ;
	setAttr ".pt[92]" -type "float3" 0 3.7194262 0 ;
	setAttr -av ".pt[92].px";
	setAttr -av ".pt[92].py";
	setAttr -av ".pt[92].pz";
	setAttr ".pt[93]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[94]" -type "float3" 2.7945826 6.4356027 0.39075398 ;
	setAttr ".pt[95]" -type "float3" 2.9738655 6.3442135 0.43152592 ;
	setAttr ".pt[96]" -type "float3" 1.8247527 6.4356027 2.0726671 ;
	setAttr ".pt[97]" -type "float3" 1.9418197 6.3442135 2.2213414 ;
	setAttr ".pt[98]" -type "float3" 0 3.7194262 0 ;
	setAttr ".pt[99]" -type "float3" 0 3.7194262 0 ;
	setAttr -s 100 ".vt[0:99]"  6.505213e-19 -0.023759298 0.0097337896 -6.6227384e-09 37.58778 -0.00015475684
		 5.7880911e-17 23.26940727 0.80936849 -0.26512909 23.26940727 -0.69519508 -0.0033252665 -0.023759298 -0.0091365539
		 -0.0095807891 -0.023759298 0.0016888479 1.7361145e-15 -0.29259309 22.96452904 -22.76602745 -0.29259309 3.84800839
		 -14.8653307 -0.29259309 17.54969406 -0.0062558828 -0.023759298 0.0074550258 1.3322676e-15 2.28559113 20.32624435
		 -13.063627243 2.28559113 15.56769562 -20.0067462921 2.28559113 3.52667737 -7.9015522 -0.29259309 -21.87548637
		 -0.0084218523 -0.023759298 -0.0048628696 -20.012142181 -0.29259309 -11.72028923 -17.5866375 2.28559113 -10.15471745
		 -6.94387102 2.28559113 -19.079088211 -0.76389337 23.26940727 0.16793327 3.1616754e-16 11.22595501 5.16970921
		 -5.026062965 11.22595501 0.94934881 -3.28182364 11.22595501 3.9742744 8.1482531e-17 1.57570028 1.32024384
		 -0.82218969 1.57570028 1.020753145 -1.25916934 1.57570028 0.26292449 -0.49879038 23.26940727 0.62767708
		 -1.74442816 11.22595501 -4.72963524 -4.41808701 11.22595501 -2.48766923 -1.10685432 1.57570028 -0.59814483
		 -0.43702817 1.57570028 -1.15982103 -0.67148852 23.26940727 -0.35444844 0.0084218523 -0.023759298 -0.0048628696
		 20.012142181 -0.29259309 -11.72028923 0.0033252665 -0.023759298 -0.0091365539 7.9015522 -0.29259309 -21.87548637
		 6.94387102 2.28559113 -19.079088211 17.5866375 2.28559113 -10.15471745 0.0095807891 -0.023759298 0.0016888479
		 22.76602745 -0.29259309 3.84800839 0.0062558828 -0.023759298 0.0074550258 14.8653307 -0.29259309 17.54969406
		 20.0067462921 2.28559113 3.52667737 13.063627243 2.28559113 15.56769562 0.67148852 23.26940727 -0.35444844
		 4.41808701 11.22595501 -2.48766923 1.74442816 11.22595501 -4.72963524 0.43702817 1.57570028 -1.15982103
		 1.10685432 1.57570028 -0.59814483 0.26512909 23.26940727 -0.69519508 5.026062965 11.22595501 0.94934881
		 1.25916934 1.57570028 0.26292449 3.28182364 11.22595501 3.9742744 0.82218969 1.57570028 1.020753145
		 0.76389337 23.26940727 0.16793327 0.49879038 23.26940727 0.62767708 1.6653345e-16 31.67526627 3.43637943
		 -2.2085526 31.67526627 2.6318934 -3.38236475 31.67526627 0.59622431 1.3322676e-15 38.86698151 19.81903267
		 -12.7376442 38.86698151 15.17922688 -19.50750732 38.86698151 3.43867421 -2.9732182 31.67526627 -1.71676874
		 -1.17393923 31.67526627 -3.22553349 -17.147789 38.86698151 -9.90132141 -6.77059698 38.86698151 -18.60299683
		 1.4890044e-15 51.49363327 21.41128731 -7.33824158 51.49363327 -20.23203278 -21.14301109 51.49363327 3.65760398
		 -13.80556488 51.49363327 16.38248253 1.3322676e-15 50.80222702 22.85873222 -14.69125175 50.80222702 17.50730705
		 -22.4994278 50.80222702 3.96607327 -18.58545494 51.49363327 -10.80081272 -19.77779198 50.80222702 -11.41991425
		 -7.80902195 50.80222702 -21.45619011 1.3322676e-15 38.92636871 16.49755859 -16.2382412 38.92636871 2.86238623
		 -10.60294056 38.92636871 12.63533783 -5.63591146 38.92636871 -15.48531723 -14.27398872 38.92636871 -8.24195766
		 1.17393923 31.67526627 -3.22553349 2.9732182 31.67526627 -1.71676874 6.77059698 38.86698151 -18.60299683
		 17.147789 38.86698151 -9.90132141 3.38236475 31.67526627 0.59622431 2.2085526 31.67526627 2.6318934
		 19.50750732 38.86698151 3.43867421 12.7376442 38.86698151 15.17922688 18.58545494 51.49363327 -10.80081272
		 7.33824158 51.49363327 -20.23203278 7.80902195 50.80222702 -21.45619011 19.77779198 50.80222702 -11.41991425
		 14.27398872 38.92636871 -8.24195766 5.63591146 38.92636871 -15.48531723 21.14301109 51.49363327 3.65760398
		 22.4994278 50.80222702 3.96607327 13.80556488 51.49363327 16.38248253 14.69125175 50.80222702 17.50730705
		 16.2382412 38.92636871 2.86238623 10.60294056 38.92636871 12.63533783;
	setAttr -s 198 ".ed";
	setAttr ".ed[0:165]"  54 2 0 30 3 0 3 26 1 17 16 1 12 11 1 8 7 0 7 5 1 6 8 0
		 0 6 1 8 9 1 9 0 0 5 9 0 10 22 1 11 10 1 6 10 0 11 8 0 12 7 0 13 4 1 15 13 0 7 15 0
		 14 5 0 15 14 1 4 14 0 16 12 1 16 15 0 17 13 0 25 18 0 18 20 1 21 20 0 20 24 1 24 23 0
		 23 21 1 22 19 1 19 21 0 23 22 0 23 11 1 24 12 1 2 25 0 19 2 1 25 21 1 26 29 1 29 28 0
		 28 27 1 27 26 0 20 27 0 28 24 0 28 16 1 29 17 1 18 30 0 30 27 1 10 42 1 36 35 1 34 32 0
		 32 31 1 13 34 0 33 4 0 34 33 1 31 33 0 35 17 1 35 34 0 36 32 0 40 6 0 32 38 0 38 37 1
		 37 31 0 38 40 0 39 37 0 40 39 1 0 39 0 41 36 1 41 38 0 42 41 1 42 40 0 48 43 0 43 44 1
		 44 47 1 47 46 0 46 45 1 45 44 0 26 45 0 46 29 0 46 35 1 47 36 1 3 48 0 48 45 1 22 52 0
		 52 51 1 51 19 0 44 49 0 49 50 1 50 47 0 50 41 1 49 51 0 52 50 0 52 42 1 43 53 0 53 49 1
		 53 54 0 54 51 1 1 78 1 64 63 1 60 59 1 57 56 0 55 58 1 56 55 0 2 55 1 56 25 1 57 18 1
		 58 69 1 59 58 1 59 56 1 60 57 1 62 61 0 61 57 0 61 30 1 62 3 1 63 60 1 63 61 1 64 62 1
		 72 66 0 66 74 1 74 73 1 73 72 1 68 67 0 67 71 1 71 70 1 70 68 1 69 65 1 65 68 0 70 69 1
		 70 59 1 71 60 1 67 72 0 73 71 1 73 63 1 74 64 1 1 76 1 77 76 1 76 67 1 68 77 1 65 75 1
		 75 77 1 75 1 1 1 77 1 78 66 1 72 79 1 79 78 1 76 79 1 1 79 1 58 87 1 83 82 1 81 80 0
		 80 62 0 80 48 1 81 43 1 82 64 1 82 80 1 83 81 1 55 85 0 84 81 0 84 53 1 85 84 0 85 54 1
		 86 83 1 86 84 1 87 86 1;
	setAttr ".ed[166:197]" 87 85 1 1 92 1 88 91 1 91 90 1 90 89 1 89 88 0 66 89 0
		 90 74 1 90 82 1 91 83 1 92 88 1 89 93 1 93 92 1 78 93 1 1 93 1 69 97 1 97 96 1 96 65 0
		 88 94 0 94 95 1 95 91 1 95 86 1 94 96 0 97 95 1 97 87 1 1 98 1 98 94 1 92 98 1 96 99 1
		 99 75 1 98 99 1 1 99 1;
	setAttr -s 99 -ch 387 ".fc[0:98]" -type "polyFaces" 
		f 3 -143 -196 -198
		mu 0 3 1 113 102
		f 4 0 -39 -88 -99
		mu 0 4 54 2 107 51
		f 4 1 2 -44 -50
		mu 0 4 30 3 26 27
		f 4 3 -47 -42 47
		mu 0 4 17 16 28 29
		f 4 4 -36 -31 36
		mu 0 4 12 11 23 24
		f 4 5 6 11 -10
		mu 0 4 8 7 5 9
		f 4 7 9 10 8
		mu 0 4 6 8 9 0
		f 4 13 12 -35 35
		mu 0 4 11 10 22 23
		f 4 14 -14 15 -8
		mu 0 4 6 10 11 8
		f 4 16 -6 -16 -5
		mu 0 4 12 7 8 11
		f 4 18 17 22 -22
		mu 0 4 15 13 4 14
		f 4 -7 19 21 20
		mu 0 4 5 7 15 14
		f 4 23 -37 -46 46
		mu 0 4 16 12 24 28
		f 4 24 -20 -17 -24
		mu 0 4 16 15 7 12
		f 4 25 -19 -25 -4
		mu 0 4 17 13 15 16
		f 4 26 27 -29 -40
		mu 0 4 25 18 20 21
		f 4 28 29 30 31
		mu 0 4 21 20 24 23
		f 4 32 33 -32 34
		mu 0 4 22 19 21 23
		f 4 37 39 -34 38
		mu 0 4 103 25 21 19
		f 4 40 41 42 43
		mu 0 4 26 29 28 27
		f 4 -30 44 -43 45
		mu 0 4 24 20 27 28
		f 4 -28 48 49 -45
		mu 0 4 20 18 30 27
		f 4 -13 50 -95 -86
		mu 0 4 108 104 42 52
		f 4 51 -82 -77 82
		mu 0 4 36 35 46 47
		f 4 52 53 57 -57
		mu 0 4 34 32 31 33
		f 4 -18 54 56 55
		mu 0 4 4 13 34 33
		f 4 58 -48 -81 81
		mu 0 4 35 17 29 46
		f 4 -26 -59 59 -55
		mu 0 4 13 17 35 34
		f 4 60 -53 -60 -52
		mu 0 4 36 32 34 35
		f 4 61 -9 68 -68
		mu 0 4 40 105 106 39
		f 4 -54 62 63 64
		mu 0 4 31 32 38 37
		f 4 -64 65 67 66
		mu 0 4 37 38 40 39
		f 4 69 -83 -91 91
		mu 0 4 41 36 47 50
		f 4 -63 -61 -70 70
		mu 0 4 38 32 36 41
		f 4 71 -92 -94 94
		mu 0 4 42 41 50 52
		f 4 -66 -71 -72 72
		mu 0 4 40 38 41 42
		f 4 -15 -62 -73 -51
		mu 0 4 104 105 40 42
		f 4 73 74 -79 -85
		mu 0 4 48 43 44 45
		f 4 75 76 77 78
		mu 0 4 44 47 46 45
		f 4 -41 79 -78 80
		mu 0 4 29 26 45 46
		f 4 -3 83 84 -80
		mu 0 4 26 3 48 45
		f 4 -33 85 86 87
		mu 0 4 107 108 52 51
		f 4 -76 88 89 90
		mu 0 4 47 44 49 50
		f 4 -90 92 -87 93
		mu 0 4 50 49 51 52
		f 4 -75 95 96 -89
		mu 0 4 44 43 53 49
		f 4 -97 97 98 -93
		mu 0 4 49 53 54 51
		f 3 99 -147 -149
		mu 0 3 55 80 81
		f 4 100 -135 -122 135
		mu 0 4 65 64 74 75
		f 4 101 -131 -126 131
		mu 0 4 61 60 71 72
		f 4 102 -111 -102 111
		mu 0 4 58 57 60 61
		f 4 104 103 -110 110
		mu 0 4 57 56 59 60
		f 4 105 -105 106 -38
		mu 0 4 103 56 57 25
		f 4 107 -27 -107 -103
		mu 0 4 58 18 25 57
		f 4 109 108 -130 130
		mu 0 4 60 59 70 71
		f 4 112 -118 -101 118
		mu 0 4 63 62 64 65
		f 4 113 -112 -117 117
		mu 0 4 62 58 61 64
		f 4 -49 -108 -114 114
		mu 0 4 30 18 58 62
		f 4 115 -2 -115 -113
		mu 0 4 63 3 30 62
		f 4 116 -132 -134 134
		mu 0 4 64 61 72 74
		f 4 119 120 121 122
		mu 0 4 73 67 75 74
		f 4 123 124 125 126
		mu 0 4 69 68 72 71
		f 4 127 128 -127 129
		mu 0 4 70 66 69 71
		f 4 132 -123 133 -125
		mu 0 4 68 73 74 72
		f 3 136 -138 -144
		mu 0 3 76 78 79
		f 4 137 138 -124 139
		mu 0 4 79 78 68 69
		f 4 140 141 -140 -129
		mu 0 4 66 77 79 69
		f 3 143 -142 142
		mu 0 3 76 79 77
		f 4 144 -120 145 146
		mu 0 4 80 67 73 81
		f 4 -133 -139 147 -146
		mu 0 4 73 68 78 81
		f 3 -137 148 -148
		mu 0 3 78 76 81
		f 4 -109 149 -191 -182
		mu 0 4 112 109 89 100
		f 4 150 -175 -170 175
		mu 0 4 85 84 93 94
		f 4 151 -157 -151 157
		mu 0 4 83 82 84 85
		f 4 152 -119 -156 156
		mu 0 4 82 63 65 84
		f 4 -84 -116 -153 153
		mu 0 4 48 3 63 82
		f 4 -74 -154 -152 154
		mu 0 4 43 48 82 83
		f 4 155 -136 -174 174
		mu 0 4 84 65 75 93
		f 4 -104 158 -167 -150
		mu 0 4 109 110 87 89
		f 4 159 -158 -164 164
		mu 0 4 86 83 85 88
		f 4 -96 -155 -160 160
		mu 0 4 53 43 83 86
		f 4 161 -165 -166 166
		mu 0 4 87 86 88 89
		f 4 -98 -161 -162 162
		mu 0 4 54 53 86 87
		f 4 -106 -1 -163 -159
		mu 0 4 110 2 54 87
		f 4 163 -176 -187 187
		mu 0 4 88 85 94 98
		f 4 165 -188 -190 190
		mu 0 4 89 88 98 100
		f 3 167 -179 -181
		mu 0 3 90 95 96
		f 4 168 169 170 171
		mu 0 4 91 94 93 92
		f 4 -121 172 -171 173
		mu 0 4 75 67 92 93
		f 4 176 -172 177 178
		mu 0 4 95 91 92 96
		f 4 -173 -145 179 -178
		mu 0 4 92 67 80 96
		f 3 -100 180 -180
		mu 0 3 80 55 96
		f 4 -128 181 182 183
		mu 0 4 111 112 100 99
		f 4 -169 184 185 186
		mu 0 4 94 91 97 98
		f 4 -186 188 -183 189
		mu 0 4 98 97 99 100
		f 3 -168 191 -194
		mu 0 3 95 90 101
		f 4 192 -185 -177 193
		mu 0 4 101 97 91 95
		f 4 -141 -184 194 195
		mu 0 4 113 111 99 102
		f 4 -189 -193 196 -195
		mu 0 4 99 97 101 102
		f 3 -192 197 -197
		mu 0 3 101 90 102;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "B7599344-4EFA-21E0-A515-868D33089EAC";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "F46CB24F-4AC8-6E26-DDA3-1C977629EC9D";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "BA82B270-4A15-5A11-2ECC-2CA26992C76E";
createNode displayLayerManager -n "layerManager";
	rename -uid "1511C65E-435B-DD4B-EDC7-FDB11ED21A2E";
createNode displayLayer -n "defaultLayer";
	rename -uid "AB367BD8-4B15-08AB-2FF5-7A85AEA3F390";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "3A03B4B4-435E-53B6-F76D-95984D127945";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "82799A0A-4813-470F-7E5D-92BE6F4FB9DC";
	setAttr ".g" yes;
createNode polyCylinder -n "polyCylinder1";
	rename -uid "803127F5-4FF1-BEA0-2A81-219F3B0E279B";
	setAttr ".r" 15.04415729744119;
	setAttr ".h" 33.97963171429388;
	setAttr ".sa" 6;
	setAttr ".sc" 1;
	setAttr ".cuv" 3;
createNode deleteComponent -n "deleteComponent1";
	rename -uid "472D6EA9-458D-D3A7-D1E6-3B919E2DD4C4";
	setAttr ".dc" -type "componentList" 1 "f[0:11]";
createNode groupId -n "groupId1";
	rename -uid "6EA68D9B-4C2D-019A-FBEC-78A5288BFFE0";
	setAttr ".ihi" 0;
createNode groupId -n "groupId2";
	rename -uid "B2C4E642-407F-1010-8097-6093B8AC6FA5";
	setAttr ".ihi" 0;
createNode groupId -n "groupId3";
	rename -uid "15ED2BFD-49C4-C7B1-2F82-F680AC49A396";
	setAttr ".ihi" 0;
createNode groupId -n "groupId4";
	rename -uid "27F98350-4E1E-6DCA-D0B4-C086BD365C03";
	setAttr ".ihi" 0;
createNode groupId -n "groupId5";
	rename -uid "B104D8B4-410A-55EC-2200-1E89F73F55F1";
	setAttr ".ihi" 0;
createNode groupParts -n "groupParts1";
	rename -uid "5CC97D40-4059-97CD-B220-5587FDC15C2E";
	setAttr ".ihi" 0;
	setAttr ".ic" -type "componentList" 1 "f[0:5]";
createNode groupId -n "groupId6";
	rename -uid "7D1A8475-42FF-032D-D54A-D58B03FD6244";
	setAttr ".ihi" 0;
createNode groupId -n "groupId7";
	rename -uid "7585541E-402F-C9C7-16AD-8C965AA04291";
	setAttr ".ihi" 0;
createNode groupId -n "groupId8";
	rename -uid "3EC57664-4916-E2A8-0E8C-93A30C11ADCC";
	setAttr ".ihi" 0;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "65286E47-4209-D041-E111-A49D6E6067E0";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 556\n            -height 326\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n"
		+ "\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n"
		+ "            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n"
		+ "            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1119\n            -height 696\n"
		+ "            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n"
		+ "            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n"
		+ "            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n"
		+ "            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 556\n            -height 326\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n"
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 1\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
		+ "            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n"
		+ "            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 556\n            -height 326\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n        modelEditor -e \n            -pluginObjects \"gpuCacheDisplayFilter\" 1 \n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n"
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
		+ "\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Side View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Side View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -camera \\\"persp\\\" \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1119\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Side View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -camera \\\"persp\\\" \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1119\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 10 -size 100 -divisions 1 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "32C59FC1-46AA-8847-8562-B4B740AC5170";
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
	setAttr -s 9 ".dsm";
	setAttr ".ro" yes;
	setAttr -s 8 ".gn";
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
connectAttr "groupId5.id" "pCylinderShape1.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pCylinderShape1.iog.og[0].gco";
connectAttr "groupParts1.og" "pCylinderShape1.i";
connectAttr "groupId6.id" "pCylinderShape1.ciog.cog[0].cgid";
connectAttr "groupId7.id" "pCylinderShape2.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pCylinderShape2.iog.og[0].gco";
connectAttr "groupId8.id" "pCylinderShape2.ciog.cog[0].cgid";
connectAttr "groupId3.id" "pCylinderShape3.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pCylinderShape3.iog.og[0].gco";
connectAttr "groupId4.id" "pCylinderShape3.ciog.cog[0].cgid";
connectAttr "groupId1.id" "pCylinderShape4.iog.og[0].gid";
connectAttr ":initialShadingGroup.mwc" "pCylinderShape4.iog.og[0].gco";
connectAttr "groupId2.id" "pCylinderShape4.ciog.cog[0].cgid";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "polyCylinder1.out" "deleteComponent1.ig";
connectAttr "deleteComponent1.og" "groupParts1.ig";
connectAttr "groupId5.id" "groupParts1.gi";
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "pCylinderShape4.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape4.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape3.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape3.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape1.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape1.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape2.iog.og[0]" ":initialShadingGroup.dsm" -na;
connectAttr "pCylinderShape2.ciog.cog[0]" ":initialShadingGroup.dsm" -na;
connectAttr "revolvedSurfaceShape1.iog" ":initialShadingGroup.dsm" -na;
connectAttr "groupId1.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId2.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId3.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId4.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId5.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId6.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId7.msg" ":initialShadingGroup.gn" -na;
connectAttr "groupId8.msg" ":initialShadingGroup.gn" -na;
// End of beker.ma
