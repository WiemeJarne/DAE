//Maya ASCII 2022 scene
//Name: tree.ma
//Last modified: Fri, May 06, 2022 05:02:34 PM
//Codeset: 1252
requires maya "2022";
requires "stereoCamera" "10.0";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" -nodeType "aiStandardSurface"
		 "mtoa" "5.0.0.1";
requires "stereoCamera" "10.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202110272215-ad32f8f1e6";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19043)";
fileInfo "UUID" "4118099D-436C-CF80-A432-BB8A3792FCBE";
fileInfo "license" "education";
createNode transform -s -n "persp";
	rename -uid "CBB20537-40F8-A23F-4B21-26837A14FFF1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 665.29997141469062 148.5948253578411 694.06367951984953 ;
	setAttr ".r" -type "double3" -4.538352667459872 -3199.0000000004557 2.6339226743540088e-16 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "6CB0EF23-4C47-136F-7BC7-2C89212700F0";
	setAttr -k off ".v" no;
	setAttr ".pze" yes;
	setAttr ".zom" 1.0019175449547049;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 892.9742170518582;
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
createNode transform -n "polySurface5";
	rename -uid "80905089-4A41-A6A5-7BFC-15A856A98549";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -3.199516281744387 -29.882375601536751 -4.7870623168246738 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape8" -p "polySurface5";
	rename -uid "3D71ADA0-4772-0B66-822C-23B4C402E181";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface6";
	rename -uid "75F56B57-417D-447A-24DA-82A14C94F927";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -14.266605543139617 -301.57194105060654 -8.9464678945453802 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape9" -p "polySurface6";
	rename -uid "35BA3D97-4CD5-EE81-B705-93B85F7196CC";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface7";
	rename -uid "4A064FCE-4832-30ED-81EF-2C8ED8016B4E";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -40.340230969217885 -772.45372949043258 -1066.6351720876964 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape10" -p "polySurface7";
	rename -uid "FED34FA0-4EE9-00EB-7B01-EB8C56DCD95E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface8";
	rename -uid "E53C73D8-4121-3D8F-0459-D58776105CB1";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -175.77276905359909 -679.6928251563204 -190.27671454807265 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape11" -p "polySurface8";
	rename -uid "D592B399-4135-5E66-3C2F-03AB570EC216";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface9";
	rename -uid "5CCB0BFE-4AAF-F5C7-34A4-80A9C6CCB313";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -17.762725175238767 -149.92796677094287 -5.1481124890810692 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape12" -p "polySurface9";
	rename -uid "A925A8E1-4DAF-7A66-0A12-18AB51684BFB";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface10";
	rename -uid "276711C3-4B70-DE71-846D-56AB68DD6FD2";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -26.693593118646344 -208.63805971786132 -5.609137493090226 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape13" -p "polySurface10";
	rename -uid "72277E07-43BE-9FBA-CCDB-90BC7F604E7C";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface11";
	rename -uid "9EEB6949-4399-8EA8-EF95-419BE9779345";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" 28.117154060094208 -316.54748699417718 0.06270881039675931 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape14" -p "polySurface11";
	rename -uid "FDF804CA-4C70-B78E-0D0E-49B8A4B3F48B";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface12";
	rename -uid "0D5ADE39-4B1F-EFAB-5648-F19D4A365EEF";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -124.45156331356227 -106.2219711537105 88.626111446304051 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape15" -p "polySurface12";
	rename -uid "4F1DFBC3-4066-5AB6-3701-50AA8640FC79";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface13";
	rename -uid "8B0372AB-4CEA-96C8-E1FC-84883B794C31";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -192.41402614735765 -751.73705265842182 -878.94257696779744 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape16" -p "polySurface13";
	rename -uid "CF8D29AE-4422-9E9B-0E00-6CBC43E50AD2";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface14";
	rename -uid "81A76459-487E-9CDD-7ADC-C1BFD820ABB4";
	setAttr ".t" -type "double3" 8.0403174298420481 185.53708706068025 -8.1591765088576818 ;
	setAttr ".r" -type "double3" 149.59315981234812 51.962990442891552 -207.6493368545045 ;
	setAttr ".s" -type "double3" 4.1369184767740057 11.144413286275515 4.1369184767740057 ;
	setAttr ".rp" -type "double3" -5.1055709107203047 0 9.1554512279869957 ;
	setAttr ".sp" -type "double3" -2.3738880157470694 0 4.2569217681884757 ;
	setAttr ".spt" -type "double3" -2.7316828949732357 0 4.8985294597985201 ;
createNode mesh -n "polySurfaceShape17" -p "polySurface14";
	rename -uid "C2CDDEC5-43E2-8B96-4068-FBB8A357EA21";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 0.394411 0 0.39232874
		 0.42413801 0 0.423592;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -7.49999952 0 7.49999952 -7.49999952 0 1.14612007
		 -1.58383536 0 7.49999952 -1.61506903 0 1.13792992;
	setAttr -s 4 ".ed[0:3]"  0 2 0 0 1 0 3 1 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 0 3 2 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface15";
	rename -uid "1EC19AD5-4C1C-0E8B-2665-338F5F6D838E";
	setAttr ".t" -type "double3" 3.7696378220651638 191.11105274551699 -8.4779556234587421 ;
	setAttr ".r" -type "double3" 72.945081277898154 58.182777792611184 -287.08710667220237 ;
	setAttr ".s" -type "double3" 4.1369184767740057 11.144413286275515 4.1369184767740057 ;
	setAttr ".rp" -type "double3" -5.1055709107203047 0 9.1554512279869957 ;
	setAttr ".sp" -type "double3" -2.3738880157470694 0 4.2569217681884757 ;
	setAttr ".spt" -type "double3" -2.7316828949732357 0 4.8985294597985201 ;
createNode mesh -n "polySurfaceShape18" -p "polySurface15";
	rename -uid "A18E9732-4ABE-5B35-A1A0-18AC98762020";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 0.394411 0 0.39232874
		 0.42413801 0 0.423592;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -7.49999952 0 7.49999952 -7.49999952 0 1.14612007
		 -1.58383536 0 7.49999952 -1.61506903 0 1.13792992;
	setAttr -s 4 ".ed[0:3]"  0 2 0 0 1 0 3 1 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 0 3 2 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface16";
	rename -uid "4DDAD8E7-471F-78A4-B947-769A31D67967";
	setAttr ".t" -type "double3" 4.0564185542483919 191.29286033610288 -12.084110757915894 ;
	setAttr ".r" -type "double3" -14.657973408462787 -27.254755180625299 -325.46743195938092 ;
	setAttr ".s" -type "double3" 4.1369184767740057 11.144413286275515 4.1369184767740057 ;
	setAttr ".rp" -type "double3" -5.1055709107203047 0 9.1554512279869957 ;
	setAttr ".sp" -type "double3" -2.3738880157470694 0 4.2569217681884757 ;
	setAttr ".spt" -type "double3" -2.7316828949732357 0 4.8985294597985201 ;
createNode mesh -n "polySurfaceShape19" -p "polySurface16";
	rename -uid "23F3888A-4BA0-469C-ACA9-54AB8E2DDE22";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 0.394411 0 0.39232874
		 0.42413801 0 0.423592;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -7.49999952 0 7.49999952 -7.49999952 0 1.14612007
		 -1.58383536 0 7.49999952 -1.61506903 0 1.13792992;
	setAttr -s 4 ".ed[0:3]"  0 2 0 0 1 0 3 1 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 0 3 2 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface17";
	rename -uid "944F4859-41E1-5868-4B23-E796749F2947";
	setAttr ".t" -type "double3" 6.9803857603258628 193.08717873757769 -9.9592013193115783 ;
	setAttr ".r" -type "double3" -99.261002191982584 -59.17620088723492 -259.57404776289559 ;
	setAttr ".s" -type "double3" 4.1369184767740057 11.144413286275515 4.1369184767740057 ;
	setAttr ".rp" -type "double3" -5.1055709107203047 0 9.1554512279869957 ;
	setAttr ".sp" -type "double3" -2.3738880157470694 0 4.2569217681884757 ;
	setAttr ".spt" -type "double3" -2.7316828949732357 0 4.8985294597985201 ;
createNode mesh -n "polySurfaceShape20" -p "polySurface17";
	rename -uid "CF109CC4-4991-3431-EE1A-37A9C4F343D4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 0.394411 0 0.39232874
		 0.42413801 0 0.423592;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -7.49999952 0 7.49999952 -7.49999952 0 1.14612007
		 -1.58383536 0 7.49999952 -1.61506903 0 1.13792992;
	setAttr -s 4 ".ed[0:3]"  0 2 0 0 1 0 3 1 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 0 3 2 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface18";
	rename -uid "12B47AF9-4841-C876-046D-398C3619AE42";
	setAttr ".t" -type "double3" -9.4920468367808528 -3.0963955158236285 -9.9334805012543992 ;
	setAttr ".r" -type "double3" -175.66675781446011 -10.139484512445229 -438.89603322607059 ;
	setAttr ".s" -type "double3" 10.121963904603696 27.267481739120822 10.121963904603696 ;
	setAttr ".rp" -type "double3" -5.1055709107203047 0 9.1554512279869957 ;
	setAttr ".sp" -type "double3" -2.3738880157470694 0 4.2569217681884757 ;
	setAttr ".spt" -type "double3" -2.7316828949732357 0 4.8985294597985201 ;
createNode mesh -n "polySurfaceShape21" -p "polySurface18";
	rename -uid "EC991A09-4783-7B2D-EAF2-35A1534C91A6";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 0.394411 0 0.39232874
		 0.42413801 0 0.423592;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -7.49999952 0 7.49999952 -7.49999952 0 1.14612007
		 -1.58383536 0 7.49999952 -1.61506903 0 1.13792992;
	setAttr -s 4 ".ed[0:3]"  0 2 0 0 1 0 3 1 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 0 3 2 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface19";
	rename -uid "ACDCE879-48A6-F6CD-9B0B-869867C8DA54";
	setAttr ".t" -type "double3" 17.492793346003069 -1.1577684647612698 6.1116889259649483 ;
	setAttr ".r" -type "double3" -293.70224645937702 10.293025929796293 -438.45858528399253 ;
	setAttr ".s" -type "double3" 10.121963904603696 27.267481739120822 10.121963904603696 ;
	setAttr ".rp" -type "double3" -5.1055709107203047 0 9.1554512279869957 ;
	setAttr ".sp" -type "double3" -2.3738880157470694 0 4.2569217681884757 ;
	setAttr ".spt" -type "double3" -2.7316828949732357 0 4.8985294597985201 ;
createNode mesh -n "polySurfaceShape22" -p "polySurface19";
	rename -uid "D65F2F7F-4A4F-417E-7088-88B30A154973";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0 0 0.394411 0 0.39232874
		 0.42413801 0 0.423592;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".vt[0:3]"  -7.49999952 0 7.49999952 -7.49999952 0 1.14612007
		 -1.58383536 0 7.49999952 -1.61506903 0 1.13792992;
	setAttr -s 4 ".ed[0:3]"  0 2 0 0 1 0 3 1 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 0 3 2 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface20";
	rename -uid "92888240-4433-40C6-9D4A-D9A50A9F6AB5";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" 21.779706251616258 -405.08649329975668 2.0075234225262477 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape23" -p "polySurface20";
	rename -uid "69604F2F-4143-6B55-3B01-3BBBEB82840E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface21";
	rename -uid "E4188523-4CAA-B428-A685-45B476B4E457";
	setAttr ".t" -type "double3" -2.1666350435412376 194.02225365547267 -19.723992269389235 ;
	setAttr ".r" -type "double3" -36.4148946188092 32.189732135933966 -15.460153536738554 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape24" -p "polySurface21";
	rename -uid "7B2758F1-4F95-9C5F-DE71-3B9BFE1F8446";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface22";
	rename -uid "017C213B-405F-50A5-0178-F8AE6F6F618A";
	setAttr ".t" -type "double3" -2.1666350435412376 194.02225365547267 -19.723992269389235 ;
	setAttr ".r" -type "double3" 110.59897778205354 -42.871269808839159 -162.03137260328535 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape25" -p "polySurface22";
	rename -uid "747A5798-440A-9DCC-D0B5-DA90399F8B86";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface23";
	rename -uid "71EA03A9-4E30-C2E1-215C-DDB6714ABD04";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -67.988035569517635 -262.93297728711025 -33.497504945504666 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape26" -p "polySurface23";
	rename -uid "5339C2C7-4DCD-278C-F923-63B2C379BBD4";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface24";
	rename -uid "50A9309B-4941-DA79-9209-21B0A771B683";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -200.61179291270756 -673.02171762542196 -195.42112887329858 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape27" -p "polySurface24";
	rename -uid "CC877834-4119-5C9A-32D8-598B0AB8B801";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface25";
	rename -uid "1045C730-4AE5-EFC9-FA54-1BA4B27FABAC";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -446.07175253463492 -637.04773194969493 -430.46903502806271 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape28" -p "polySurface25";
	rename -uid "E20A851F-4BBB-3CFD-579A-699F057C7B02";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface26";
	rename -uid "9D310EF3-4053-4E50-30C3-C6954EB7AB8E";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -193.55732662487284 -717.99274825145744 -904.10936579116844 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape29" -p "polySurface26";
	rename -uid "67D0CADC-4CA4-640A-470A-2C8904907737";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface27";
	rename -uid "6BAC73E2-4E70-91E8-F879-B994BEF00E81";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -211.62992111349209 -201.92631535192797 -179.12209053704026 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape30" -p "polySurface27";
	rename -uid "B3116E4A-498B-F9C1-93FE-9D9546639F6F";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface28";
	rename -uid "BEB44EC2-4234-F08E-5144-2298A1285052";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -171.78629040568924 -205.52429261515789 -171.61989025612735 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape31" -p "polySurface28";
	rename -uid "538D1F98-4CBB-E3BB-B9E4-FC9C68A3F1D6";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface29";
	rename -uid "CAE36909-4CEC-F094-0EFB-60883A323777";
	setAttr ".t" -type "double3" -8.0165969557809706 193.32293046142769 -14.000271585986706 ;
	setAttr -av ".ty";
	setAttr ".r" -type "double3" -361.42366551084365 -122.50352094441263 4.5262772024228246 ;
	setAttr ".s" -type "double3" 7.2933271103102104 19.647438547707903 7.2933271103102104 ;
	setAttr ".rp" -type "double3" 11.103476633873655 -1.0098408131622225 15.785694896533936 ;
	setAttr ".sp" -type "double3" 5.1626763343811026 -0.1742964684963226 7.3397221565246573 ;
	setAttr ".spt" -type "double3" 5.940800299492552 -0.8355443446659 8.4459727400092781 ;
createNode mesh -n "polySurfaceShape32" -p "polySurface29";
	rename -uid "E21C0CE0-42A5-2961-9971-F1BCD43526C5";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.85168004035949707 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 4 ".uvst[0].uvsp[0:3]" -type "float2" 0.7049377 1 0.70336008
		 0 1 0 1 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 4 ".pt[0:3]" -type "float3"  -7.1525574e-07 0 0 -7.1525574e-07 
		0 0 -7.1525574e-07 0 0 -7.1525574e-07 0 0;
	setAttr -s 4 ".vt[0:3]"  7.49999905 0 7.49999952 7.49999905 0 -7.49999952
		 3.07406497 0 -7.49999952 3.050400734 0 7.49999952;
	setAttr -s 4 ".ed[0:3]"  0 1 0 2 1 0 3 0 0 2 3 0;
	setAttr -ch 4 ".fc[0]" -type "polyFaces" 
		f 4 3 2 0 -2
		mu 0 4 0 1 2 3;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface30";
	rename -uid "1C0441D7-43AA-780E-85EB-12A7385AF4F4";
	setAttr ".t" -type "double3" -2.0379405771220052 199.36661962308921 -16.429032135649756 ;
	setAttr ".r" -type "double3" -241.75028592390177 -798.74207910380062 -853.34776118724483 ;
	setAttr ".s" -type "double3" 8.7150472231112062 23.477399569037996 8.7150472231112062 ;
	setAttr ".rp" -type "double3" 0.93026403379546274 -3.4983656387505717 16.130407827326152 ;
	setAttr ".sp" -type "double3" 0.43253588676452615 -0.60381078720092762 7.4999999999999991 ;
	setAttr ".spt" -type "double3" 0.4977281470309366 -2.894554851549644 8.6304078273261506 ;
createNode mesh -n "polySurfaceShape33" -p "polySurface30";
	rename -uid "3BB88102-4BEA-F202-A3E6-90B82081428E";
	setAttr -k off ".v";
	setAttr ".io" yes;
	setAttr ".iog[0].og[0].gcl" -type "componentList" 1 "f[0]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.54863321781158447 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 5 ".uvst[0].uvsp[0:4]" -type "float2" 0.41366199 1 0.39232874
		 0.42413801 0.394411 0 0.70336008 0 0.7049377 1;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 5 ".vt[0:4]"  -1.58383536 0 7.49999952 -1.61506903 0 1.1379298
		 -1.29507041 0 -7.49999952 3.050401449 0 7.49999952 3.074065685 0 -7.49999952;
	setAttr -s 5 ".ed[0:4]"  0 3 0 0 1 0 2 4 0 1 2 0 4 3 0;
	setAttr -ch 5 ".fc[0]" -type "polyFaces" 
		f 5 -4 -2 0 -5 -3
		mu 0 5 0 1 2 3 4;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode transform -n "polySurface31";
	rename -uid "C43C7741-46E3-3D81-0D80-EFA44E8D8B52";
	setAttr ".rp" -type "double3" 33.573694838578987 -142.79604866559143 -0.74772132965093951 ;
	setAttr ".sp" -type "double3" 33.573694838578987 -142.79604866559143 -0.74772132965093951 ;
createNode mesh -n "polySurface31Shape" -p "polySurface31";
	rename -uid "DB9C9B7D-4206-733B-0DD1-E7893504E0BB";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[0].gcl" -type "componentList" 2 "f[0:149]" "f[222:437]";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 1 "f[150:221]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 10 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "bottom";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 1 "f[222:229]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottomRing";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 1 "e[415:422]";
	setAttr ".gtag[2].gtagnm" -type "string" "cylBottomCap";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 2 "vtx[277:284]" "vtx[357]";
	setAttr ".gtag[3].gtagnm" -type "string" "cylBottomRing";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 1 "vtx[277:284]";
	setAttr ".gtag[4].gtagnm" -type "string" "cylSides";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "vtx[277:356]";
	setAttr ".gtag[5].gtagnm" -type "string" "cylTopCap";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 2 "vtx[349:356]" "vtx[358]";
	setAttr ".gtag[6].gtagnm" -type "string" "cylTopRing";
	setAttr ".gtag[6].gtagcmp" -type "componentList" 1 "vtx[349:356]";
	setAttr ".gtag[7].gtagnm" -type "string" "sides";
	setAttr ".gtag[7].gtagcmp" -type "componentList" 1 "f[150:221]";
	setAttr ".gtag[8].gtagnm" -type "string" "top";
	setAttr ".gtag[8].gtagcmp" -type "componentList" 1 "f[230:237]";
	setAttr ".gtag[9].gtagnm" -type "string" "topRing";
	setAttr ".gtag[9].gtagcmp" -type "componentList" 1 "e[487:494]";
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 783 ".uvst[0].uvsp";
	setAttr ".uvst[0].uvsp[0:249]" -type "float2" 0.8426466 0.010229154 0.77333754
		 0.17543584 0.83950526 0.13814099 0.84595054 0.010279817 0.90372407 0.15958482 0.84865707
		 0.149055 0.7020942 0.59915292 0.8342436 0.98007995 0.85642564 0.97718161 0.75175315
		 0.72754657 0.77161986 0.83427376 0.79735321 0.7604847 0.94393772 0.70676315 0.91049397
		 0.7773239 0.89555836 0.70425028 0.87456614 0.75437176 0.95341253 0.31866053 0.84104025
		 0.072511271 0.84695446 0.073785417 0.75189948 0.30355522 0.72907627 0.43867615 0.96884912
		 0.47533959 0.96767038 0.60978192 0.89245141 0.84389395 0.84067047 0.9773531 0.84332305
		 0.83986831 0.84410512 0.75670469 0.84358001 0.71233958 0.84032375 0.6043877 0.84050781
		 0.45606664 0.84242374 0.30997205 0.84391057 0.073129535 0.8442542 0.010249531 0.84347934
		 0.14181806 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253 0.70366222
		 0.16651484 0.52882248 -0.00063932943 0.62691945 -0.00066731119 0.69446677 0.53994608
		 0.55562466 0.53957325 0.660945 0.68566424 0.55513829 0.66909248 0.62837899 0.82110161
		 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932 0.94419467
		 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236 0.55474561 0.40130147 0.37669349
		 0.3949005 0.17479272 0.45292202 -0.0006024203 0.69906765 0.35140923 0.54684901 0.36224052
		 0.53626662 0.17012253 0.70366222 0.16651484 0.52882248 -0.00063932943 0.62691945
		 -0.00066731119 0.69446677 0.53994608 0.55562466 0.53957325 0.660945 0.68566424 0.55513829
		 0.66909248 0.62837899 0.82110161 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367
		 0.94415534 0.51902932 0.94419467 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236
		 0.55474561 0.40130147 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203 0.69906765
		 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253 0.70366222 0.16651484 0.52882248
		 -0.00063932943 0.62691945 -0.00066731119 0.69446677 0.53994608 0.55562466 0.53957325
		 0.660945 0.68566424 0.55513829 0.66909248 0.62837899 0.82110161 0.54953671 0.83114147
		 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932 0.94419467 0.46769577 0.83216101
		 0.40978542 0.6535697 0.40700236 0.55474561 0.40130147 0.37669349 0.3949005 0.17479272
		 0.45292202 -0.0006024203 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253
		 0.70366222 0.16651484 0.52882248 -0.00063932943 0.62691945 -0.00066731119 0.69446677
		 0.53994608 0.55562466 0.53957325 0.660945 0.68566424 0.55513829 0.66909248 0.62837899
		 0.82110161 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932
		 0.94419467 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236 0.55474561 0.40130147
		 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203 0.95341253 0.31866053 0.84242374
		 0.30997205 0.84347934 0.14181806 0.84865707 0.149055 0.90372407 0.15958482 0.84695446
		 0.073785417 0.84391057 0.073129535 0.8442542 0.010249531 0.84595054 0.010279817 0.96767038
		 0.60978192 0.84032375 0.6043877 0.84050781 0.45606664 0.96884912 0.47533959 0.89555836
		 0.70425028 0.84358001 0.71233958 0.94393772 0.70676315 0.84067047 0.9773531 0.84332305
		 0.83986831 0.89245141 0.84389395 0.85642564 0.97718161 0.87456614 0.75437176 0.84410512
		 0.75670469 0.91049397 0.7773239 0.8342436 0.98007995 0.77161986 0.83427376 0.79735321
		 0.7604847 0.75175315 0.72754657 0.7020942 0.59915292 0.72907627 0.43867615 0.75189948
		 0.30355522 0.83950526 0.13814099 0.77333754 0.17543584 0.84104025 0.072511271 0.8426466
		 0.010229154 0.20227966 0.37644562 0.19243655 0.24952021 0.3064242 0.22407605 0.33484608
		 0.40105015 0.12750405 0.3725841 0.060537748 0.2787078 0.34171191 0.21623015 0.35449302
		 0.22577946 0.35388249 0.29280585 0.069773935 0.11590772 0.17790143 0.061419245 0.29282334
		 0.0034967065 0.35542792 0.11485014 0.35441241 0.20392397 0.20832996 0.37297717 0.19470511
		 0.24885796 0.30661964 0.22396408 0.34711847 0.39393285 0.13698989 0.36851472 0.073654853
		 0.27560264 0.3419944 0.2160698 0.35473183 0.22564441 0.35755557 0.29068676 0.078481846
		 0.11879373 0.1909339 0.097577386 0.30826589 0.061919484 0.36045319 0.12305727 0.35476881
		 0.20370607 0.95341253 0.31866053 0.84242374 0.30997205 0.84347934 0.14181806 0.84865707
		 0.149055 0.90372407 0.15958482 0.84695446 0.073785417 0.84391057 0.073129535 0.8442542
		 0.010249531 0.84595054 0.010279817 0.96767038 0.60978192 0.84032375 0.6043877 0.84050781
		 0.45606664 0.96884912 0.47533959 0.89555836 0.70425028 0.84358001 0.71233958 0.94393772
		 0.70676315 0.84067047 0.9773531 0.84332305 0.83986831 0.89245141 0.84389395 0.85642564
		 0.97718161 0.87456614 0.75437176 0.84410512 0.75670469 0.91049397 0.7773239 0.8342436
		 0.98007995 0.77161986 0.83427376 0.79735321 0.7604847 0.75175315 0.72754657 0.7020942
		 0.59915292 0.72907627 0.43867615 0.75189948 0.30355522 0.83950526 0.13814099 0.77333754
		 0.17543584 0.84104025 0.072511271 0.8426466 0.010229154 0.69906765 0.35140923 0.54684901
		 0.36224052 0.53626662 0.17012253 0.70366222 0.16651484 0.52882248 -0.00063932943
		 0.62691945 -0.00066731119 0.69446677 0.53994608 0.55562466 0.53957325 0.660945 0.68566424
		 0.55513829 0.66909248 0.62837899 0.82110161 0.54953671 0.83114147 0.5523169 0.94349295
		 0.59149367 0.94415534 0.51902932 0.94419467 0.46769577 0.83216101 0.40978542 0.6535697
		 0.40700236 0.55474561 0.40130147 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203
		 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253 0.70366222 0.16651484
		 0.52882248 -0.00063932943 0.62691945 -0.00066731119 0.69446677 0.53994608 0.55562466
		 0.53957325 0.660945 0.68566424 0.55513829 0.66909248 0.62837899 0.82110161 0.54953671
		 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932 0.94419467;
	setAttr ".uvst[0].uvsp[250:499]" 0.46769577 0.83216101 0.40978542 0.6535697
		 0.40700236 0.55474561 0.40130147 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203
		 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253 0.70366222 0.16651484
		 0.52882248 -0.00063932943 0.62691945 -0.00066731119 0.69446677 0.53994608 0.55562466
		 0.53957325 0.660945 0.68566424 0.55513829 0.66909248 0.62837899 0.82110161 0.54953671
		 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932 0.94419467 0.46769577
		 0.83216101 0.40978542 0.6535697 0.40700236 0.55474561 0.40130147 0.37669349 0.3949005
		 0.17479272 0.45292202 -0.0006024203 0.48973995 4.20390129 0.071288079 4.18574905
		 0.14525366 2.58411098 0.4675318 2.59503818 -0.34376007 4.12143421 -0.16816688 2.54500747
		 -0.78169668 4.015973568 -0.46970576 2.48205948 -1.18635023 3.90193152 -0.76335657
		 2.39949274 2.11287212 3.86831474 1.7149502 3.9812727 1.4025023 2.47043347 1.6939913
		 2.39074779 1.31406212 4.087363243 1.10235977 2.53360224 0.90584743 4.16820145 0.78961182
		 2.57697439 0.22344194 1.74744165 0.46884322 1.75057232 -0.02200976 1.73499572 -0.26390117
		 1.70677328 -0.49654567 1.6573925 1.1917181 1.70667005 1.42223716 1.65724659 0.95406175
		 1.73474622 0.71268755 1.74718893 0.29551518 0.47694266 0.46798384 0.48785836 0.12091434
		 0.45840573 -0.05659306 0.43841341 -0.23341095 0.42072195 0.98741537 0.45026574 1.16215181
		 0.42190224 0.8129282 0.47374481 0.64003062 0.48705953 0.29589289 -0.62506247 0.46973222
		 -0.61216772 0.12654576 -0.644292 -0.029279023 -0.66208267 -0.18589091 -0.67497998
		 0.9642477 -0.65007019 1.1314404 -0.67700791 0.79581958 -0.62557864 0.63412213 -0.61170757
		 0.33716971 -1.46858811 0.4598015 -1.47469354 0.21789742 -1.46353006 0.10038391 -1.46864748
		 -0.015649199 -1.4905448 0.83492088 -1.47928309 0.95418823 -1.49262953 0.71163315
		 -1.4766314 0.58555353 -1.47696567 0.3841266 -2.049510717 0.46947157 -2.058282375
		 0.29592854 -2.042966843 0.20542091 -2.047552824 0.11696851 -2.067917109 0.72427481
		 -2.055609941 0.81257463 -2.060261488 0.63818252 -2.0593009 0.55375135 -2.061960936
		 0.40753269 -2.40512109 0.47357494 -2.40217543 0.33914876 -2.41119671 0.26855999 -2.42035365
		 0.19796219 -2.43253565 0.67123175 -2.41407371 0.74040508 -2.42546415 0.60401475 -2.40637279
		 0.53856635 -2.40243006 0.41520447 -2.63487959 0.47402057 -2.63279319 0.35869777 -2.650635
		 0.29986036 -2.65920973 0.24131286 -2.66963768 0.64893538 -2.64851618 0.70597726 -2.66509604
		 0.59020954 -2.63922381 0.53262401 -2.62742972 0.39806333 -2.78924847 0.40159088 -2.78952026
		 0.39475271 -2.79049516 0.2997278 -2.78407788 0.303316 -2.78384733 0.29625753 -2.78496337
		 0.65929776 -2.78399467 0.66265321 -2.78528285 0.65575075 -2.78370643 0.54548532 -2.79098105
		 0.54885954 -2.79202342 0.54200828 -2.79174376 0.20832996 0.37297717 0.19470511 0.24885796
		 0.30661964 0.22396408 0.34711847 0.39393285 0.13698989 0.36851472 0.073654853 0.27560264
		 0.3419944 0.2160698 0.35473183 0.22564441 0.35755557 0.29068676 0.078481846 0.11879373
		 0.1909339 0.097577386 0.30826589 0.061919484 0.36045319 0.12305727 0.35476881 0.20370607
		 0.95341253 0.31866053 0.84242374 0.30997205 0.84347934 0.14181806 0.84865707 0.149055
		 0.90372407 0.15958482 0.84695446 0.073785417 0.84391057 0.073129535 0.8442542 0.010249531
		 0.84595054 0.010279817 0.96767038 0.60978192 0.84032375 0.6043877 0.84050781 0.45606664
		 0.96884912 0.47533959 0.89555836 0.70425028 0.84358001 0.71233958 0.94393772 0.70676315
		 0.84067047 0.9773531 0.84332305 0.83986831 0.89245141 0.84389395 0.85642564 0.97718161
		 0.87456614 0.75437176 0.84410512 0.75670469 0.91049397 0.7773239 0.8342436 0.98007995
		 0.77161986 0.83427376 0.79735321 0.7604847 0.75175315 0.72754657 0.7020942 0.59915292
		 0.72907627 0.43867615 0.75189948 0.30355522 0.83950526 0.13814099 0.77333754 0.17543584
		 0.84104025 0.072511271 0.8426466 0.010229154 0.95341253 0.31866053 0.84242374 0.30997205
		 0.84347934 0.14181806 0.84865707 0.149055 0.90372407 0.15958482 0.84695446 0.073785417
		 0.84391057 0.073129535 0.8442542 0.010249531 0.84595054 0.010279817 0.96767038 0.60978192
		 0.84032375 0.6043877 0.84050781 0.45606664 0.96884912 0.47533959 0.89555836 0.70425028
		 0.84358001 0.71233958 0.94393772 0.70676315 0.84067047 0.9773531 0.84332305 0.83986831
		 0.89245141 0.84389395 0.85642564 0.97718161 0.87456614 0.75437176 0.84410512 0.75670469
		 0.91049397 0.7773239 0.8342436 0.98007995 0.77161986 0.83427376 0.79735321 0.7604847
		 0.75175315 0.72754657 0.7020942 0.59915292 0.72907627 0.43867615 0.75189948 0.30355522
		 0.83950526 0.13814099 0.77333754 0.17543584 0.84104025 0.072511271 0.8426466 0.010229154
		 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253 0.70366222 0.16651484
		 0.52882248 -0.00063932943 0.62691945 -0.00066731119 0.69446677 0.53994608 0.55562466
		 0.53957325 0.660945 0.68566424 0.55513829 0.66909248 0.62837899 0.82110161 0.54953671
		 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932 0.94419467 0.46769577
		 0.83216101 0.40978542 0.6535697 0.40700236 0.55474561 0.40130147 0.37669349 0.3949005
		 0.17479272 0.45292202 -0.0006024203 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662
		 0.17012253 0.70366222 0.16651484 0.52882248 -0.00063932943 0.62691945 -0.00066731119
		 0.69446677 0.53994608 0.55562466 0.53957325 0.660945 0.68566424 0.55513829 0.66909248
		 0.62837899 0.82110161 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534
		 0.51902932 0.94419467 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236 0.55474561
		 0.40130147 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203 0.95341253 0.31866053
		 0.84242374 0.30997205 0.84347934 0.14181806 0.84865707 0.149055 0.90372407 0.15958482
		 0.84695446 0.073785417;
	setAttr ".uvst[0].uvsp[500:749]" 0.84391057 0.073129535 0.8442542 0.010249531
		 0.84595054 0.010279817 0.96767038 0.60978192 0.84032375 0.6043877 0.84050781 0.45606664
		 0.96884912 0.47533959 0.89555836 0.70425028 0.84358001 0.71233958 0.94393772 0.70676315
		 0.84067047 0.9773531 0.84332305 0.83986831 0.89245141 0.84389395 0.85642564 0.97718161
		 0.87456614 0.75437176 0.84410512 0.75670469 0.91049397 0.7773239 0.8342436 0.98007995
		 0.77161986 0.83427376 0.79735321 0.7604847 0.75175315 0.72754657 0.7020942 0.59915292
		 0.72907627 0.43867615 0.75189948 0.30355522 0.83950526 0.13814099 0.77333754 0.17543584
		 0.84104025 0.072511271 0.8426466 0.010229154 0.95341253 0.31866053 0.84242374 0.30997205
		 0.84347934 0.14181806 0.84865707 0.149055 0.90372407 0.15958482 0.84695446 0.073785417
		 0.84391057 0.073129535 0.8442542 0.010249531 0.84595054 0.010279817 0.96767038 0.60978192
		 0.84032375 0.6043877 0.84050781 0.45606664 0.96884912 0.47533959 0.89555836 0.70425028
		 0.84358001 0.71233958 0.94393772 0.70676315 0.84067047 0.9773531 0.84332305 0.83986831
		 0.89245141 0.84389395 0.85642564 0.97718161 0.87456614 0.75437176 0.84410512 0.75670469
		 0.91049397 0.7773239 0.8342436 0.98007995 0.77161986 0.83427376 0.79735321 0.7604847
		 0.75175315 0.72754657 0.7020942 0.59915292 0.72907627 0.43867615 0.75189948 0.30355522
		 0.83950526 0.13814099 0.77333754 0.17543584 0.84104025 0.072511271 0.8426466 0.010229154
		 0.95341253 0.31866053 0.84242374 0.30997205 0.84347934 0.14181806 0.84865707 0.149055
		 0.90372407 0.15958482 0.84695446 0.073785417 0.84391057 0.073129535 0.8442542 0.010249531
		 0.84595054 0.010279817 0.96767038 0.60978192 0.84032375 0.6043877 0.84050781 0.45606664
		 0.96884912 0.47533959 0.89555836 0.70425028 0.84358001 0.71233958 0.94393772 0.70676315
		 0.84067047 0.9773531 0.84332305 0.83986831 0.89245141 0.84389395 0.85642564 0.97718161
		 0.87456614 0.75437176 0.84410512 0.75670469 0.91049397 0.7773239 0.8342436 0.98007995
		 0.77161986 0.83427376 0.79735321 0.7604847 0.75175315 0.72754657 0.7020942 0.59915292
		 0.72907627 0.43867615 0.75189948 0.30355522 0.83950526 0.13814099 0.77333754 0.17543584
		 0.84104025 0.072511271 0.8426466 0.010229154 0.69906765 0.35140923 0.54684901 0.36224052
		 0.53626662 0.17012253 0.70366222 0.16651484 0.52882248 -0.00063932943 0.62691945
		 -0.00066731119 0.69446677 0.53994608 0.55562466 0.53957325 0.660945 0.68566424 0.55513829
		 0.66909248 0.62837899 0.82110161 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367
		 0.94415534 0.51902932 0.94419467 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236
		 0.55474561 0.40130147 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203 0.20227966
		 0.37644562 0.19243655 0.24952021 0.3064242 0.22407605 0.33484608 0.40105015 0.12750405
		 0.3725841 0.060537748 0.2787078 0.34171191 0.21623015 0.35449302 0.22577946 0.35388249
		 0.29280585 0.069773935 0.11590772 0.17790143 0.061419245 0.29282334 0.0034967065
		 0.35542792 0.11485014 0.35441241 0.20392397 0.20227966 0.37644562 0.19243655 0.24952021
		 0.3064242 0.22407605 0.33484608 0.40105015 0.12750405 0.3725841 0.060537748 0.2787078
		 0.34171191 0.21623015 0.35449302 0.22577946 0.35388249 0.29280585 0.069773935 0.11590772
		 0.17790143 0.061419245 0.29282334 0.0034967065 0.35542792 0.11485014 0.35441241 0.20392397
		 0.20227966 0.37644562 0.19243655 0.24952021 0.3064242 0.22407605 0.33484608 0.40105015
		 0.12750405 0.3725841 0.060537748 0.2787078 0.34171191 0.21623015 0.35449302 0.22577946
		 0.35388249 0.29280585 0.069773935 0.11590772 0.17790143 0.061419245 0.29282334 0.0034967065
		 0.35542792 0.11485014 0.35441241 0.20392397 0.20227966 0.37644562 0.19243655 0.24952021
		 0.3064242 0.22407605 0.33484608 0.40105015 0.12750405 0.3725841 0.060537748 0.2787078
		 0.34171191 0.21623015 0.35449302 0.22577946 0.35388249 0.29280585 0.069773935 0.11590772
		 0.17790143 0.061419245 0.29282334 0.0034967065 0.35542792 0.11485014 0.35441241 0.20392397
		 0.95341253 0.31866053 0.84242374 0.30997205 0.84347934 0.14181806 0.84865707 0.149055
		 0.90372407 0.15958482 0.84695446 0.073785417 0.84391057 0.073129535 0.8442542 0.010249531
		 0.84595054 0.010279817 0.96767038 0.60978192 0.84032375 0.6043877 0.84050781 0.45606664
		 0.96884912 0.47533959 0.89555836 0.70425028 0.84358001 0.71233958 0.94393772 0.70676315
		 0.84067047 0.9773531 0.84332305 0.83986831 0.89245141 0.84389395 0.85642564 0.97718161
		 0.87456614 0.75437176 0.84410512 0.75670469 0.91049397 0.7773239 0.8342436 0.98007995
		 0.77161986 0.83427376 0.79735321 0.7604847 0.75175315 0.72754657 0.7020942 0.59915292
		 0.72907627 0.43867615 0.75189948 0.30355522 0.83950526 0.13814099 0.77333754 0.17543584
		 0.84104025 0.072511271 0.8426466 0.010229154 0.95341253 0.31866053 0.84242374 0.30997205
		 0.84347934 0.14181806 0.84865707 0.149055 0.90372407 0.15958482 0.84695446 0.073785417
		 0.84391057 0.073129535 0.8442542 0.010249531 0.84595054 0.010279817 0.96767038 0.60978192
		 0.84032375 0.6043877 0.84050781 0.45606664 0.96884912 0.47533959 0.89555836 0.70425028
		 0.84358001 0.71233958 0.94393772 0.70676315 0.84067047 0.9773531 0.84332305 0.83986831
		 0.89245141 0.84389395 0.85642564 0.97718161 0.87456614 0.75437176 0.84410512 0.75670469
		 0.91049397 0.7773239 0.8342436 0.98007995 0.77161986 0.83427376 0.79735321 0.7604847
		 0.75175315 0.72754657 0.7020942 0.59915292 0.72907627 0.43867615 0.75189948 0.30355522
		 0.83950526 0.13814099 0.77333754 0.17543584 0.84104025 0.072511271 0.8426466 0.010229154
		 0.69906765 0.35140923 0.54684901 0.36224052 0.53626662 0.17012253 0.70366222 0.16651484
		 0.52882248 -0.00063932943 0.62691945 -0.00066731119 0.69446677 0.53994608 0.55562466
		 0.53957325 0.660945 0.68566424;
	setAttr ".uvst[0].uvsp[750:782]" 0.55513829 0.66909248 0.62837899 0.82110161
		 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367 0.94415534 0.51902932 0.94419467
		 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236 0.55474561 0.40130147 0.37669349
		 0.3949005 0.17479272 0.45292202 -0.0006024203 0.69906765 0.35140923 0.54684901 0.36224052
		 0.53626662 0.17012253 0.70366222 0.16651484 0.52882248 -0.00063932943 0.62691945
		 -0.00066731119 0.69446677 0.53994608 0.55562466 0.53957325 0.660945 0.68566424 0.55513829
		 0.66909248 0.62837899 0.82110161 0.54953671 0.83114147 0.5523169 0.94349295 0.59149367
		 0.94415534 0.51902932 0.94419467 0.46769577 0.83216101 0.40978542 0.6535697 0.40700236
		 0.55474561 0.40130147 0.37669349 0.3949005 0.17479272 0.45292202 -0.0006024203;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 770 ".pt";
	setAttr ".pt[0:165]" -type "float3"  4.1541042 85.016769 3.3040996 -10.473902 
		73.991478 -10.020955 -2.4369266 81.499741 -12.190231 4.5644832 85.020004 3.1335566 
		4.9550691 77.368019 -15.75841 -1.7890369 80.78479 -13.715107 -35.811985 46.84272 
		-49.802898 -33.170868 12.397865 -88.564636 -30.250271 12.399579 -89.588921 -34.466381 
		36.086048 -63.718922 -35.331196 24.749559 -72.845734 -30.107956 32.68652 -68.4086 
		-11.457344 39.392414 -71.621864 -17.2637 30.951559 -75.020638 -16.941263 39.061684 
		-68.847824 -20.898905 33.725166 -71.76416 4.9680786 65.072731 -33.041145 0.80305636 
		83.932228 -4.5703321 1.4489191 83.857506 -4.9779267 -19.474314 71.272591 -25.1763 
		-26.064823 56.517693 -34.385708 0.18962099 56.408882 -50.488708 -5.7617779 49.602901 
		-65.135529 -22.034439 26.607004 -80.915833 -32.466949 13.919493 -89.754982 -28.052816 
		28.460033 -79.137703 -25.306955 36.544189 -72.294579 -24.006327 41.050179 -68.699585 
		-20.700781 50.512192 -59.016384 -15.040135 61.195362 -44.611347 -8.8649769 70.097771 
		-29.582542 1.1165196 83.895966 -4.7681513 4.3526254 85.018692 3.2222407 -2.0616558 
		81.046928 -12.624782 11.531694 78.915001 -10.535653 5.541398 75.4785 -40.011417 -9.6920099 
		82.399208 4.9487219 -32.564316 79.019661 -12.123937 -27.621746 51.434929 -77.897408 
		-74.53363 15.766693 -105.46809 -83.378799 17.5131 -99.158218 -73.566238 55.262638 
		-69.159904 -10.97311 64.076851 -59.124073 -49.789268 71.734001 -37.197857 -64.236053 
		59.484322 -55.691902 -44.614601 42.658611 -90.730614 -60.028328 25.343348 -97.8908 
		-81.066086 34.321198 -88.204208 -79.571281 19.180016 -103.5023 -70.620461 31.945356 
		-94.392418 -56.829132 49.215485 -82.235886 -45.936424 61.346851 -70.841675 -31.444225 
		73.322968 -51.19268 -15.492023 80.85997 -26.953346 -0.65219271 82.947426 -3.0047803 
		-11.837441 90.395554 -8.7489233 -33.33334 108.7327 2.1225712 7.2951002 84.020004 
		8.4455357 -0.67778844 95.272125 33.661835 -66.60923 120.31317 45.387383 -96.273796 
		117.57392 103.22855 -88.211456 115.22752 110.34153 -45.194962 120.91137 87.136185 
		-49.708973 115.08063 23.559988 -18.425802 108.74999 55.612621 -35.484028 113.88738 
		75.193687 -76.693848 124.26505 65.7136 -88.714211 118.02844 85.845284 -70.19471 119.58659 
		102.32616 -91.272575 119.10035 106.90967 -79.021545 121.26148 93.821388 -63.032738 
		124.15973 74.528969 -50.108013 124.12742 59.409458 -32.41927 117.99354 39.685909 
		-14.748556 105.37861 19.011446 -0.50321132 89.134354 0.80963957 -11.394645 79.160797 
		6.5703306 -0.36461219 62.650818 29.423616 5.5402369 83.605347 -13.324567 29.075201 
		68.272896 -7.2368035 30.112255 18.162142 43.746845 66.657692 -35.569149 40.51125 
		73.85099 -33.516117 32.440144 71.182205 14.35432 21.371614 15.067986 40.899395 36.955608 
		47.959408 47.54129 6.6220531 61.075336 25.780046 14.052746 45.448868 1.1860893 46.40654 
		55.069931 -20.623714 41.885872 75.084259 -13.667871 28.921999 71.971886 -32.934532 
		38.121483 66.189407 -15.851073 37.238529 56.876823 7.586062 36.773788 48.58321 25.501427 
		34.34388 35.064877 47.505344 25.822319 17.616804 67.818443 12.340219 -0.65219712 
		82.947441 -3.0047824 12.255079 87.279503 8.2397947 35.957699 96.308105 -8.2885008 
		-10.833502 86.341385 -4.7366624 -4.6894641 92.107658 -32.214664 62.242496 92.337982 
		-57.34544 77.830025 74.954765 -118.07388 68.234161 74.889427 -123.46056 34.543114 
		96.674362 -94.972969 49.071068 94.950684 -32.665073 11.864999 96.928658 -58.314259 
		25.583549 94.359512 -80.808594 68.965805 90.951668 -79.330605 74.287163 79.375313 
		-99.978615 54.425121 85.727425 -113.47561 72.96505 77.770538 -121.12287 64.784416 
		85.020248 -106.74996 54.556442 94.737938 -85.840782 45.442787 100.32713 -69.067238 
		30.849474 102.18684 -46.195621 14.396241 98.043015 -21.47834 -0.50321132 89.134354 
		0.80963957 4.1580701 85.006508 3.1321568 5.1369815 78.070007 -18.408951 11.156492 
		85.51178 -12.573009 4.561306 85.031288 3.3173368 19.36071 82.00515 -10.373242 12.788522 
		85.145546 -13.250152 19.85844 62.145443 -68.322502 54.115993 37.649803 -98.691559 
		56.853794 37.761162 -97.252434 32.205048 54.896599 -78.627266 39.701214 46.061916 
		-87.477028 39.019505 52.498783 -79.226692 53.193741 58.932911 -66.544731 52.805401 
		51.789574 -74.627762 47.492893 58.206566 -68.747185 47.596989 53.882839 -74.573067 
		33.404999 74.109581 -24.167618 7.6152787 85.945969 -4.7149792 8.3602457 85.940033 
		-4.5310092 10.125208 79.378387 -35.482025 14.222088 67.498177 -49.194466 43.76276 
		69.992828 -40.84343 51.058323 67.077003 -56.158207 54.333385 49.16283 -82.822517 
		55.234722 39.374908 -98.675743 48.668343 50.814289 -85.650314 44.548447 56.941162 
		-77.575089 42.250206 60.417778 -73.385712 36.298832 67.193024 -62.760357 28.432064 
		73.943886 -47.069035 20.724373 78.796349 -30.935362 7.9768419 85.943092 -4.6256857 
		4.3526278 85.018715 3.2222362 11.787587 85.157021 -12.675825 -1.601105 76.408684 
		-9.4846268 16.036774 67.083534 -15.497657 20.351343 67.343788 -4.4066939 17.327265 
		66.61734 3.3803787 0.13182314 75.535553 -3.3855271 0.53600013 75.327873 -1.8819085 
		1.1965872 75.156639 -2.8027327 -0.13926494 74.470886 -18.516594 1.8296604 74.674118 
		2.7106249 4.4360046 71.216454 9.653738 12.506907 68.185066 5.1942897 8.4895306 71.556 
		-16.917496 11.505553 71.424362 -3.6249721 3.6593556 74.356895 -2.9949896;
	setAttr ".pt[166:331]" -10.727335 -146.34232 -15.010646 -7.9994025 -96.057098 
		-23.518156 -20.958151 -92.936195 2.6122808 -13.587863 -99.62133 21.138491 -15.125628 
		-143.69748 -1.4769924 -15.644941 -143.10304 2.2975678 -15.849742 -141.19763 0.25464687 
		-5.1956272 -137.89749 -26.700693 -13.748055 -141.13954 13.84381 -3.4662843 -133.83112 
		32.324932 -11.804063 -111.71457 24.09446 -8.7882366 -116.7757 -24.098562 -20.20507 
		-115.02898 1.4479553 -17.2649 -134.98979 0.51586771 4.5367675 85.002762 3.1128938 
		21.479513 77.252884 15.99604 13.502209 84.921455 17.792805 4.1563649 85.035248 3.3403711 
		6.9230485 81.514786 23.229156 13.12125 84.532433 19.513182 53.675285 59.464291 56.104317 
		58.427353 33.887413 101.03915 55.693165 34.058052 102.47933 54.912075 51.848999 71.967804 
		57.653385 42.696323 82.980362 51.460403 49.441448 77.869957 33.190155 56.377316 82.477661 
		39.829964 48.930824 86.597847 38.214111 55.558167 79.018341 42.808483 51.015965 82.320839 
		10.046447 73.123215 42.456562 9.0610218 85.648567 10.429073 8.4866819 85.650902 10.937983 
		32.737137 77.918671 29.812943 41.309921 65.531914 40.723045 17.754688 68.391899 60.359383 
		26.11985 64.907341 74.993309 45.619957 45.996559 92.4506 57.835125 35.613735 101.98618 
		51.21484 47.529739 89.423553 47.107189 53.952702 81.575356 45.077095 57.582451 77.377342 
		39.931767 64.747337 66.587967 31.704823 72.077538 51.347775 22.962368 77.527817 35.949257 
		8.7822685 85.649704 10.676064 4.352634 85.018692 3.2222385 13.217176 84.564102 18.363554 
		8.063077 90.546677 12.894567 37.432842 90.553459 5.5507946 -8.493557 84.375656 -6.8575802 
		8.1473627 76.928001 -29.075855 78.143127 64.184013 -22.027473 110.53638 20.825207 
		-58.135387 103.71988 18.552649 -66.470367 67.32103 51.659317 -65.935394 57.836502 
		77.997597 -8.3798103 33.575996 69.017982 -45.486134 53.605385 56.22028 -57.141045 
		91.865616 52.835148 -36.634624 101.7306 33.042404 -46.61454 89.801476 33.057682 -68.402496 
		107.78212 22.068213 -63.771149 96.673271 35.230118 -58.347229 81.86451 53.599575 
		-49.430767 68.70253 66.390442 -41.76231 47.595131 78.747185 -29.874384 22.894245 
		86.632423 -14.824017 -0.50321132 89.134354 0.80963957 7.2156019 87.146652 -11.755816 
		-8.901865 95.589043 -35.952251 -6.2372279 86.455055 11.067292 -33.638977 91.811111 
		4.2484879 -57.344284 90.63047 -63.191563 -117.53786 72.312843 -79.753235 -123.12601 
		72.34996 -70.273132 -95.595772 95.016525 -36.368469 -32.978577 93.739456 -49.550449 
		-59.431576 96.061333 -12.931701 -81.600716 93.010941 -27.074486 -79.165604 88.886612 
		-70.351234 -99.570427 76.99334 -75.906685 -113.55348 83.530151 -56.444847 -120.71951 
		75.176453 -75.002464 -106.60224 82.722626 -66.646683 -86.020508 92.843483 -56.149075 
		-69.505234 98.771896 -46.781635 -46.96986 101.132 -31.744314 -22.564318 97.541718 
		-14.70601 -0.50321132 89.134354 0.80963737 14.207364 82.173248 -3.1302238 25.799 
		98.041618 -26.159409 -12.139024 79.334335 -3.5295272 -20.937771 90.761757 -28.389851 
		24.355803 107.39344 -81.147552 8.8254509 103.83716 -144.22887 -2.1446507 102.97042 
		-144.31181 -18.63777 113.07782 -99.067696 25.082584 103.29389 -53.360886 -19.986498 
		102.91492 -57.197437 -19.154572 106.77866 -83.37326 19.311749 111.05254 -103.32052 
		14.459906 104.36052 -126.13161 -9.8855143 109.25318 -126.74887 2.8991718 106.21132 
		-143.86087 2.4672043 109.27887 -126.0714 3.3442249 113.24058 -101.17612 3.422303 
		114.11807 -81.304718 2.0738661 109.34447 -54.566566 0.47236037 98.103516 -26.81949 
		-0.65219408 82.947426 -3.0047934 13.42153 -140.39392 -11.82324 1.4640027 -140.39392 
		-16.776205 -10.493522 -140.39392 -11.82324 -15.446486 -140.39392 0.13428418 -10.493522 
		-140.39392 12.091811 1.4640031 -140.39392 17.044773 13.421528 -140.39392 12.091809 
		18.374493 -140.39392 0.13428418 7.2649641 -92.322815 -5.6671591 -1.6293769 -92.322815 
		-9.3513184 -10.523722 -92.322815 -5.6671591 -14.20788 -92.322815 3.227185 -10.523722 
		-92.322815 12.12153 -1.6293769 -92.322815 15.805688 7.2649655 -92.322815 12.121531 
		10.949124 -92.322815 3.227185 7.4039454 -66.845398 -5.0462222 0.22257686 -66.845413 
		-8.0208359 -6.9587913 -66.845406 -5.0462198 -9.9334116 -66.845413 2.1351414 -6.9587913 
		-66.845398 9.3165073 0.22257686 -66.845406 12.291131 7.4039464 -66.845413 9.3165083 
		10.378566 -66.845406 2.1351414 6.9768982 -24.959383 -5.3786106 1.4640019 -24.959402 
		-7.6621237 -4.0488901 -24.959366 -5.3786106 -6.3324089 -24.959402 0.13428308 -4.0488901 
		-24.959383 5.6471772 1.4640019 -24.959393 7.9306912 6.9768968 -24.959366 5.6471782 
		9.2604122 -24.959393 0.13428198 1.19331 12.197676 -2.124222 -4.3184547 12.197711 
		-4.2087064 -9.830225 12.197693 -2.1242228 -12.113276 12.197711 2.9081681 -9.8302231 
		12.197676 7.940558 -4.3184547 12.197711 10.025043 1.1933123 12.197693 7.9405589 3.4763644 
		12.197711 2.9081681 0.2711274 41.426804 -2.7660408 -3.6832504 41.426838 -4.4039946 
		-7.637651 41.426838 -2.7660408 -9.2756109 41.426838 1.1883683 -7.637651 41.426804 
		5.1427608 -3.6832504 41.426819 6.7807245 0.27112851 41.426819 5.1427622 1.9090891 
		41.426819 1.1883683 4.5333261 62.19886 -2.9350331 1.4640019 62.19886 -4.2063832 -1.6053094 
		62.19886 -2.9350331 -2.8766646 62.19886 0.13428088 -1.6053094 62.19886 3.2035944 
		1.4640019 62.19886 4.4749517 4.5333204 62.19886 3.2035923;
	setAttr ".pt[332:497]" 5.8046722 62.19886 0.13428088 4.8811641 75.873032 -2.7310863 
		2.4527469 75.873032 -3.7369659 0.024318609 75.873032 -2.7310863 -0.98156857 75.873032 
		-0.30265594 0.024318609 75.873032 2.1257703 2.4527469 75.873032 3.131664 4.8811607 
		75.873016 2.1257715 5.8870554 75.873032 -0.30265594 3.2744644 84.702728 -2.0425351 
		1.2272075 84.702728 -2.8905399 -0.82004958 84.702728 -2.0425329 -1.6680514 84.702728 
		0.004722992 -0.82005292 84.702728 2.05198 1.2272075 84.702728 2.8999796 3.2744653 
		84.702728 2.051981 4.1224613 84.702728 0.004722992 -0.21549591 89.134354 0.69045794 
		-0.33467281 89.134354 0.6410951 -0.45384851 89.134354 0.69045794 -0.50321025 89.134354 
		0.80963707 -0.45384851 89.134354 0.92881697 -0.33467281 89.134354 0.97818506 -0.21549536 
		89.134354 0.92881697 -0.16613087 89.134354 0.80963707 0.0018309571 -146.04643 21.948713 
		-15.649529 -97.471458 19.966354 12.782911 -90.451927 18.295498 26.319704 -96.450974 
		3.3623369 13.488166 -141.70097 18.993122 16.933855 -140.72395 17.56378 14.991077 
		-138.98909 18.594263 -13.954341 -139.43303 22.193865 25.800888 -138.05266 10.146968 
		35.980476 -130.62086 -8.3415232 29.717695 -108.37795 1.2725916 -12.911948 -117.87751 
		22.479887 14.471736 -112.46861 19.85359 15.030027 -132.64915 19.236107 4.1997466 
		85.01255 3.0715547 11.431409 93.194138 -16.774288 12.581957 96.810234 -6.2256947 
		4.5170565 85.025833 3.3824301 21.045153 95.036201 -3.1157568 14.290955 97.383247 
		-6.3102007 39.138515 115.58051 -57.918449 84.896614 124.87291 -80.628433 87.048126 
		124.80995 -78.404465 54.835987 119.72069 -64.819229 66.717598 120.49783 -73.232658 
		62.011871 120.10838 -63.869415 69.767189 120.97846 -45.369766 73.811775 120.45293 
		-55.363689 65.382805 120.25671 -49.628216 68.274406 120.59684 -56.274216 39.065544 
		101.26837 -12.405145 8.0504074 91.410339 -1.2473863 8.6837149 91.492439 -0.82189554 
		17.892078 105.88892 -27.506794 28.855391 106.44232 -42.521935 52.603848 111.09639 
		-23.470303 62.695393 120.17827 -34.050957 77.579758 123.88227 -62.465126 85.124107 
		126.45094 -79.33004 72.2761 125.32807 -66.014397 64.692467 123.89743 -58.257885 60.4846 
		123.33517 -54.147255 50.603409 120.34972 -44.784039 38.259937 113.75346 -32.221951 
		26.825153 105.5113 -20.198524 8.3577738 91.450172 -1.0408809 4.3526254 85.018692 
		3.2222362 13.312218 96.775734 -6.2405324 4.3764014 85.005325 3.4352555 -11.999928 
		72.698669 13.102456 -12.174778 80.678734 5.2309456 4.3260183 85.032188 2.9945202 
		-13.383142 76.971542 -3.0901875 -13.429654 79.972725 4.1432881 -56.063084 42.949081 
		24.724693 -91.103462 7.8384862 9.3847551 -91.279266 8.0130014 6.2996893 -68.600655 
		31.97613 18.930241 -77.127136 20.39068 16.555544 -71.755356 28.767147 13.247277 -69.96376 
		36.639366 -5.1363411 -74.478767 27.745897 -1.0090894 -68.803131 36.005516 0.87441927 
		-72.473824 30.344965 3.5447304 -29.457069 64.292793 -8.635006 -4.0649862 83.507454 
		4.39013 -4.27457 83.466774 3.6530573 -28.925402 69.01342 17.348787 -38.971294 53.629284 
		20.240705 -47.166519 54.908188 -9.4209995 -62.58926 47.364773 -8.1938992 -81.275871 
		22.948076 1.6683581 -92.115417 9.3751278 8.4669056 -81.310722 24.432219 8.0411501 
		-74.320251 32.845905 7.7867961 -70.697945 37.514759 7.804275 -60.883747 47.408985 
		7.8850851 -45.936073 58.794102 7.0951915 -30.172592 68.452866 5.8821697 -4.1667066 
		83.487701 4.0323997 4.3526297 85.018715 3.2222495 -12.469226 80.241997 4.7237306 
		-2.6772947 86.273888 15.249605 22.901981 89.745155 31.066216 0.12761459 87.285156 
		-11.08404 28.406279 88.897865 -15.958053 76.919647 76.34478 35.035763 135.26003 50.016266 
		23.361021 136.47296 50.756084 12.448521 101.23478 80.400551 -4.8918729 49.864231 
		83.683197 33.142296 59.262981 88.19899 -10.873111 84.54744 81.072403 -7.6016731 99.256287 
		71.473595 32.239635 118.17403 56.952591 27.775499 123.87974 64.588387 4.8373623 136.62999 
		53.153603 17.959803 121.61538 63.129807 16.911901 100.2776 76.580948 16.837702 82.45153 
		85.338547 15.749305 56.373112 91.940849 11.766844 26.922718 93.131859 6.2823052 -0.50321573 
		89.134354 0.80963629 -15.364328 89.434738 0.11795546 -27.429792 96.488869 26.972719 
		10.722616 84.769417 0.35664541 18.636702 85.572311 27.974794 -28.7386 84.795044 81.514236 
		-17.174257 57.14621 139.26282 -6.2903771 55.526634 139.40205 13.363937 80.382751 
		101.75773 -28.04122 91.28437 54.18594 16.637493 86.291946 59.183228 14.468896 80.289177 
		84.874832 -24.82443 79.656509 103.62185 -21.693762 64.702187 122.46958 2.7996607 
		67.266243 125.71249 -11.11799 59.057972 140.01093 -9.4723492 68.424278 124.66083 
		-8.6639185 81.331093 103.00441 -7.5209761 89.471016 84.891312 -4.8530068 94.800629 
		58.358097 -2.2194426 94.489243 28.495213 -0.50321025 89.134354 0.80963075 4.3523517 
		85.079865 3.0163801 21.469961 75.908257 -8.643877 20.918434 80.714607 1.4688698 4.3541045 
		84.952492 3.4421489 21.129749 74.338776 8.0831604 22.03199 79.612755 2.3644629 65.99604 
		49.496826 -25.423069 98.472435 9.3848705 -19.747627 98.308716 8.4902573 -16.789276 
		77.611504 36.533169 -22.560093 85.608681 24.378468 -23.493458 80.058128 31.414436 
		-18.048059 76.386574 32.654583 1.6527251 81.166962 25.458944 -4.8190579 75.88723 
		34.166901 -4.29216 79.726608 29.557734 -8.3739786 36.255585 59.663296 10.47195;
	setAttr ".pt[498:663]" 12.818659 83.532181 2.4344137 12.944553 83.231857 3.1292553 
		38.691101 72.957527 -12.222911 48.711601 58.942978 -19.232708 53.593979 49.607864 
		9.7091665 68.916801 42.091602 7.4760928 88.129593 21.489546 -8.3053217 99.404541 
		10.459624 -18.263086 88.897133 25.047363 -13.743074 82.076965 33.245808 -11.295115 
		78.565109 37.83498 -10.059766 69.003342 47.693222 -7.6915994 54.271458 58.93858 -4.4992089 
		38.650406 68.464378 -1.5850896 12.879761 83.386414 2.7716444 4.3526297 85.018715 
		3.2222362 21.146843 80.115913 1.8211329 4.1980267 85.017525 3.3712807 -14.777969 
		95.005638 -3.925431 -3.9595697 97.846886 -4.6752486 4.5170808 85.020638 3.0619264 
		-0.77613044 96.207542 -13.13828 -3.9563813 98.498222 -6.358079 -53.380356 121.66711 
		-31.506187 -74.135139 134.65131 -77.294243 -71.867668 134.51093 -79.396126 -59.54108 
		127.00166 -47.151009 -67.562698 128.93718 -59.170563 -58.380169 127.62582 -54.279003 
		-39.674236 127.40699 -61.57143 -49.571781 127.82674 -65.858131 -44.086609 126.8253 
		-57.320465 -50.611065 127.80011 -60.34166 -9.0994625 103.91015 -31.061972 0.4769012 
		91.889114 -0.28206214 0.92354506 91.965652 -0.9013378 -24.347717 108.75562 -10.044436 
		-38.990471 110.93578 -21.304609 -19.035791 115.13683 -44.386559 -28.634457 125.43366 
		-54.291634 -56.293556 131.95172 -69.625214 -72.715469 136.13327 -77.421112 -59.858444 
		133.43478 -64.342369 -52.430489 131.08505 -56.659534 -48.484001 130.02673 -52.390484 
		-39.63147 125.90522 -42.447319 -27.927351 117.83447 -30.13658 -16.861492 108.20499 
		-18.819767 0.6936785 91.926262 -0.58262157 4.3526254 85.018692 3.2222395 -3.9581742 
		97.845314 -5.4064746 4.5411949 85.001137 3.3234973 2.3392215 75.952293 23.97204 -3.4693854 
		83.825836 18.500286 4.1503062 85.036903 3.115093 -11.426153 80.407799 15.425952 -5.1324182 
		83.365326 19.027939 -15.190015 54.90976 70.999847 -50.734653 26.922791 96.479332 
		-53.375454 27.126938 94.878242 -27.997519 46.45797 79.700836 -35.833378 36.65892 
		87.126518 -34.776047 43.891178 79.60704 -48.252159 51.293293 66.694176 -48.213966 
		43.393837 74.05014 -42.689835 50.454784 69.191277 -43.065475 45.575016 74.547874 
		-26.137398 70.937126 27.415649 0.56143188 85.098129 10.976241 -0.16969901 85.097107 
		10.743213 -3.7740805 75.476715 40.719742 -8.4593763 62.227528 52.904236 -37.449509 
		65.007156 42.881256 -45.647915 60.461353 57.317036 -50.204758 39.942764 81.829315 
		-51.891697 28.620728 96.557053 -44.776558 41.407547 85.176781 -40.293053 48.375546 
		78.03067 -37.813812 52.289883 74.363121 -31.353951 60.18784 64.870331 -22.654757 
		68.596718 50.472668 -14.039377 75.157692 35.440056 0.20658541 85.097633 10.86314 
		4.352634 85.018715 3.2222407 -4.096981 83.451439 18.525635 -12.097329 83.846855 8.4934063 
		-10.382594 91.701942 37.680248 9.5094872 89.168602 -5.9001927 29.203993 98.801117 
		12.684228 21.471199 92.535507 83.482834 71.351112 84.306358 124.43849 80.247581 86.831322 
		118.47371 65.172493 108.2794 76.83316 5.2748384 92.703514 60.524544 43.355629 105.53358 
		39.756104 57.409077 104.91364 62.181774 37.875347 94.130035 99.571136 56.186348 85.839928 
		113.15977 75.073944 97.783432 102.314 75.452408 88.404854 121.74132 64.868591 94.136307 
		108.28046 48.935226 101.3932 90.122696 37.082855 105.22842 74.615868 23.257885 105.23694 
		51.19783 10.095412 99.39856 24.901695 -0.50320691 89.134354 0.80963516 9.7318592 
		78.426491 -2.3402894 20.693012 69.101341 12.729698 11.374578 69.361588 20.131845 
		3.04146 68.635139 19.546467 4.4182773 77.55336 1.1191758 3.1014969 77.345673 1.9500288 
		4.1765137 77.174438 2.3086808 18.792068 76.488686 -3.6154747 -0.90287125 76.691917 
		4.5442486 -6.7643466 73.234253 9.0876999 -0.11711877 70.202873 15.478362 19.816875 
		73.573799 5.1002021 8.0112982 73.442169 11.913122 5.0886402 76.374702 4.6043763 -4.3953433 
		86.101486 0.47213843 -2.4310708 72.630791 -15.304153 9.2855139 74.618401 -15.985096 
		15.561881 76.23568 -10.665052 1.9838009 86.337303 0.93617284 3.5473325 86.40683 1.0699364 
		2.9494796 85.914841 0.22487575 -11.952208 81.933662 -3.132232 8.3462963 86.589943 
		1.4287684 16.207407 84.386169 1.9779043 15.334394 79.017189 -6.0612102 -7.042172 
		77.950363 -9.8801775 6.3244867 80.296738 -8.6027536 3.7454309 84.661575 -1.9052862 
		6.5759125 83.813805 2.2269721 3.4699714 70.343109 17.818731 -8.2651148 72.330727 
		17.64613 -14.138132 73.948006 11.883892 0.2473813 84.049629 1.3004311 -1.3022904 
		84.119156 1.0533595 -0.76745278 83.627167 1.9396454 13.85076 79.645988 6.3711572 
		-6.0624709 84.302261 0.34661314 -13.862863 82.098488 -0.77253687 -13.576571 76.729507 
		7.3087726 8.463171 75.662682 12.744311 -4.7752576 78.009064 10.498568 -1.7161504 
		82.373894 4.0063086 -3.4160621 84.024277 4.4823766 -16.756454 70.553581 -4.165381 
		-12.259573 72.541191 -15.006049 -4.7349291 74.158478 -18.334026 -0.2165041 84.260101 
		-1.0558194 0.58573365 84.329628 -2.4045014 -0.43545851 83.837639 -2.2350316 -9.955204 
		79.856453 9.710885 3.0014956 84.512733 -6.5665798 6.9239287 82.30896 -13.401279 -0.69116145 
		76.93998 -16.121559 -13.886365 75.873154 2.3495529 -6.9075503 78.219536 -9.1219568 
		-2.0052655 82.584366 -3.8802788 4.4658713 85.027718 3.04 26.742655 86.455376 6.8870325 
		17.922817 91.638229 11.471931 4.2327461 85.009117 3.4179029;
	setAttr ".pt[664:769]" 16.046614 88.099625 19.742523 18.465616 91.646744 13.192822 
		76.677582 90.689964 28.106064 108.96716 81.102798 67.620178 107.23589 80.857635 70.173935 
		87.164566 88.470894 42.115757 97.497894 83.942383 51.350334 87.673004 86.890625 49.171951 
		71.797234 89.169502 61.251099 81.856377 85.435982 62.429207 74.840706 88.932167 55.907036 
		81.749718 87.032417 57.048477 29.772623 86.65274 35.847496 10.952603 88.966896 7.1409292 
		10.68667 88.941826 7.8603091 41.447117 94.181488 13.38088 57.805111 88.370277 20.059273 
		45.318775 89.530937 48.190369 59.58144 92.83799 57.240776 90.1754 86.063492 65.034714 
		108.19766 82.771767 68.542236 92.955109 88.265976 59.535748 83.852081 90.771805 54.006084 
		79.045456 92.338707 50.946529 67.590851 94.406197 43.282459 51.701786 94.49189 33.222229 
		36.051445 92.662216 23.476999 10.823538 88.954727 7.4900727 4.3526254 85.018715 3.2222369 
		18.06052 91.385681 12.144203 4.1618543 84.990288 3.3166635 -12.914664 85.676216 -11.549907 
		-3.816453 92.079338 -10.173238 4.5559998 85.049202 3.1199772 2.5162053 90.089729 
		-16.528028 -3.3925564 92.341377 -11.907541 -44.863323 90.330727 -55.359661 -50.545353 
		85.509079 -106.74412 -47.733273 85.799072 -108.00392 -46.228966 89.841209 -72.939987 
		-49.596584 86.292564 -86.674202 -42.812065 89.43087 -79.319801 -23.484774 94.65583 
		-80.834625 -30.872091 90.563721 -87.557388 -28.774302 93.345879 -77.974037 -33.770161 
		91.244644 -82.79821 -0.62171286 90.511536 -37.500454 0.22971913 89.154282 -3.1340702 
		0.82803816 89.265709 -3.6014521 -23.100649 93.46402 -23.946671 -32.702236 87.859215 
		-38.858093 -7.8373208 94.451736 -55.795902 -15.718721 98.343643 -70.594772 -36.661522 
		91.107536 -94.082359 -49.653065 87.352196 -106.92984 -42.147896 92.18895 -90.684334 
		-37.635082 94.289314 -80.940376 -35.358059 95.614952 -75.651009 -29.890783 97.071846 
		-62.914951 -21.625305 96.449829 -46.033813 -13.1327 93.980774 -29.754084 0.52010828 
		89.208351 -3.3609095 4.3526254 85.018692 3.222245 -3.5522246 91.934425 -10.839482 
		-10.286832 91.067017 -10.234237 -36.786083 101.25489 0.27817139 7.0489426 83.506233 
		8.3306952 -6.9272032 85.288361 33.38126 -77.839111 93.528366 37.267166 -114.27336 
		68.748177 85.137596 -107.02689 65.92041 92.921783 -63.533287 85.768883 81.278816 
		-57.159813 98.019623 18.783968 -30.336994 88.354591 53.901039 -50.815144 84.40062 
		70.20459 -91.44619 89.498329 55.407681 -104.54285 75.605103 70.378494 -89.51667 75.595421 
		90.158096 -110.35641 70.00869 90.032639 -97.138878 78.060638 80.730797 -79.580566 
		89.287064 66.521194 -64.910881 95.992004 54.881035 -43.575966 99.164864 38.319366 
		-20.627241 96.52317 19.209118 -0.50321132 89.134354 0.80963516 0.30287173 86.66288 
		-13.841766 -26.666468 90.416046 -27.073645 -0.0016003487 86.97213 12.656587 -27.696629 
		88.313599 20.221336 -80.782669 76.850052 -26.275505 -137.68927 49.930153 -9.8423414 
		-137.86664 50.378704 1.1516831 -101.22309 79.738777 15.863966 -53.688473 84.273682 
		-26.752949 -58.894028 87.591194 18.057552 -84.356056 80.424278 17.001972 -102.7421 
		71.794289 -21.511583 -121.1153 57.065926 -15.666102 -124.6458 64.071304 7.902504 
		-138.55037 52.918434 -4.2547193 -123.52976 62.939915 -4.3663068 -102.31541 76.492592 
		-5.9522953 -84.488953 85.309113 -6.3214421 -58.167923 91.937393 -4.6471553 -28.334007 
		93.134186 -1.9398196 -0.50320691 89.134354 0.80963701;
	setAttr -s 770 ".vt";
	setAttr ".vt[0:165]"  2.91539001 192.31141663 1.85613441 -9.72052765 182.7875824 -9.65427208
		 -2.77805328 189.27334595 -11.52812958 3.2698822 192.31420898 1.70881653 3.60727692 185.70429993 -14.61038303
		 -2.21839523 188.65576172 -12.84534264 -31.60799026 159.33602905 -44.018585205 -29.32654762 129.58198547 -77.50162506
		 -26.80368805 129.58346558 -78.3864212 -30.44563675 150.044235229 -56.039478302 -31.19267845 140.25158691 -63.92337036
		 -26.68075371 147.10766602 -60.090499878 -10.57004166 152.90032959 -62.86617279 -15.58567047 145.60897827 -65.80209351
		 -15.30714417 152.61463928 -60.46990967 -18.72582054 148.0048675537 -62.98908997 3.61851501 175.0834198 -29.53950119
		 0.020698547 191.37457275 -4.94593239 0.57860565 191.31002808 -5.29801941 -17.49523544 180.43896484 -22.74571419
		 -23.18822861 167.69343567 -30.70095444 -0.50919724 167.59944153 -44.61100006 -5.65011597 161.72032166 -57.26316833
		 -19.70671463 141.8560791 -70.89446259 -28.71849251 130.89639282 -78.52986908 -24.90549088 143.45675659 -69.35848236
		 -22.53356934 150.43998718 -63.44727325 -21.4100647 154.33233643 -60.34185791 -18.55467796 162.50578308 -51.97734833
		 -13.66491699 171.73408508 -39.53403473 -8.33071136 179.4241333 -26.55190086 0.29147339 191.34324646 -5.11681175
		 3.086875916 192.31307983 1.78542328 -2.45388794 188.88220215 -11.90350151 9.28827667 187.040603638 -10.098876953
		 4.11375809 184.072097778 -35.56053925 -9.045116425 190.050323486 3.2767868 -28.80260086 187.13101196 -11.47086334
		 -24.53312492 163.30285645 -68.28709412 -65.056396484 132.49203491 -92.1031189 -72.69700623 134.00061035156 -86.65254211
		 -64.2207489 166.60929871 -60.73949051 -10.15175247 174.22315979 -52.070373535 -43.68180466 180.83753967 -33.1301384
		 -56.16117859 170.25605774 -49.10560608 -39.21183777 155.72172546 -79.37263489 -52.526474 140.76451111 -85.557724
		 -70.69924164 148.51972961 -77.19028473 -69.40800476 135.44052124 -90.40503693 -61.67613983 146.46743774 -82.53575897
		 -49.76295471 161.38566589 -72.034744263 -40.35365295 171.86494446 -62.19223404 -27.83504677 182.21011353 -45.21910095
		 -14.055265427 188.72070313 -24.280756 -1.23637009 190.52388 -3.59358215 -10.89837646 196.95770264 -8.55546951
		 -29.46689606 212.79763794 0.83551025 5.62863541 191.45039368 6.2973938 -1.25848007 201.17016602 28.079658508
		 -58.21116638 222.80104065 38.20838165 -83.83592224 220.43482971 88.17255402 -76.87153625 218.40797424 94.31687164
		 -39.71316528 223.31777954 74.271698 -43.61244202 218.28108215 19.35351181 -16.58951378 212.81257629 47.041114807
		 -31.32469559 217.25033569 63.95557022 -66.92243195 226.21473694 55.76651382 -77.30582428 220.82745361 73.15660095
		 -61.30836487 222.17341614 87.39305115 -79.51578522 221.75338745 91.35237122 -68.93313599 223.62020874 80.04649353
		 -55.12173462 226.12376404 63.38137817 -43.95714188 226.095855713 50.32088852 -28.67730713 220.79730225 33.28335571
		 -13.41304588 209.90031433 15.42440414 -1.10767746 195.86825562 -0.29862213 -10.51588058 187.25292969 4.67755985
		 -0.98795319 172.99133301 24.41861343 4.11275482 191.092208862 -12.50798798 24.44265366 177.84777832 -7.24927521
		 25.33847809 134.56126404 36.79125977 56.90703964 88.1472702 33.99629593 63.12073135 89.92071533 27.024339676
		 60.81539154 131.27200317 17.46315765 12.34298515 154.2020874 30.92487526 40.75514984 159.93946838 4.72223854
		 52.084907532 141.14173889 11.14099598 38.58650208 119.89706421 39.088748932 46.89733887 101.057388306 35.18371964
		 64.18605042 107.065963745 23.98530769 61.49753189 90.4230957 31.93197632 56.50252914 105.1800766 31.16926575
		 48.45816422 125.42546844 30.76781654 41.29399872 140.90106201 28.66881943 29.61663628 159.90841675 21.3077507
		 14.54469681 177.45521545 9.66168594 -1.2363739 190.52389526 -3.59358406 9.91314888 194.26600647 6.11967087
		 30.38787079 202.065063477 -8.15774918 -10.03115654 193.4556427 -5.089611053 -4.72383308 198.43664551 -28.82557297
		 53.093120575 198.63560486 -50.53395844 66.55789185 183.61968994 -102.99221039 58.26882172 183.56324768 -107.64530945
		 29.16592789 202.38143921 -83.037254333 41.71541977 200.89250183 -29.21464157 9.57619095 202.60110474 -51.37084198
		 21.42650604 200.38183594 -70.80182648 58.9008255 197.43807983 -69.52511597 63.49750519 187.43823242 -87.36121368
		 46.34033966 192.92529297 -99.020141602 62.35544586 186.052001953 -105.62597656 55.28887177 192.31442261 -93.2104187
		 46.45377731 200.70872498 -75.14871216 38.58124924 205.53675842 -60.65944672 25.97529984 207.14321899 -40.90255737
		 11.76272011 203.56370544 -19.55135345 -1.10767746 195.86825562 -0.29862213 2.91881609 192.30255127 1.70760727
		 3.76441622 186.3106842 -16.89996338 8.96417046 192.73901367 -11.85877991 3.267138 192.32395935 1.86756897
		 16.051113129 189.70993042 -9.95858383 10.37394524 192.4226532 -12.44370651 16.48106003 172.55477905 -60.016132355
		 46.073310852 151.39503479 -86.24943542 48.43827057 151.4912262 -85.0062942505 27.14626884 166.29310608 -68.91755676
		 33.62158203 158.66156006 -76.56213379 33.032711029 164.22183228 -69.43535614 45.27665329 169.77973938 -58.48046112
		 44.94120026 163.60920715 -65.46272278 40.35216522 169.15231323 -60.38298035 40.44208527 165.41740417 -65.41547394
		 28.18280602 182.88960266 -21.87439728 5.90521097 193.11407471 -5.07088089 6.54872561 193.10894775 -4.91196442
		 8.073329926 187.44088745 -31.64797211 11.61228371 177.17855835 -43.49301147 37.13001251 179.33348083 -36.27924347
		 43.43204498 176.81474304 -49.50840759 46.26109695 161.34017944 -72.54148865 47.03968811 152.88520813 -86.23577118
		 41.36753845 162.76673889 -74.98418427 37.80870438 168.059234619 -68.0086669922 35.82344437 171.062393188 -64.38981628
		 30.68254662 176.91496277 -55.2114563 23.88710022 182.74647522 -41.6570282 17.22906685 186.93811035 -27.7204895
		 6.2175355 193.11158752 -4.99374771 3.0868783 192.31309509 1.78541946 9.50932121 192.43257141 -11.94759369
		 -2.056056499 184.87561035 -9.19098282 13.17984009 176.82038879 -14.38513947 16.90683746 177.045196533 -4.80457878
		 14.29458809 176.41767883 1.92202568 -0.55912399 184.12138367 -3.92247772 -0.20998907 183.94198608 -2.62362671
		 0.36063719 183.79406738 -3.41905022 -0.79329443 183.20170593 -16.99294853 0.90749645 183.3772583 1.34348106
		 3.15890026 180.39047241 7.34105873 10.13068199 177.77191162 3.48891258 6.66040468 180.68377686 -15.61161995
		 9.26569557 180.57006836 -4.12931442 2.48801804 183.10324097 -3.58512497;
	setAttr ".vt[166:331]" -9.9394474 -7.54045677 -13.96445084 -7.58301353 35.89675903 -21.3133812
		 -18.77699852 38.59265137 1.25852966 -12.41041946 32.81791687 17.26178169 -13.73876762 -5.25580692 -2.2738533
		 -14.18735886 -4.74231911 0.98667526 -14.36426926 -3.0963974 -0.77803421 -5.1610651 -0.24567986 -24.062511444
		 -12.54879665 -3.04621315 10.96051407 -3.66722965 3.26692772 26.92481804 -10.86954308 22.37157249 19.81519699
		 -8.26442146 17.9996891 -21.81474686 -18.12647438 19.50852776 0.25276566 -15.58670616 2.26604652 -0.55238724
		 3.24594116 192.29931641 1.69096756 17.88137054 185.60484314 12.81964684 10.99044037 192.2290802 14.37172127
		 2.91734314 192.32737732 1.88746643 5.30725098 189.28634644 19.067733765 10.66136169 191.89303589 15.85781288
		 45.69261932 170.23875427 47.46585083 49.79753494 148.14501953 86.28131104 47.43569946 148.29241943 87.52536774
		 46.7609787 163.66053772 61.16899872 49.1289711 155.75430298 70.68183136 43.77936935 161.58085632 66.26737976
		 27.99721909 167.57217407 70.24758911 33.73279953 161.13977051 73.80667877 32.33699799 166.86457825 67.2593689
		 36.30569458 162.94094849 70.11212158 8.0052947998 182.037567139 35.67668915 7.15406799 192.85717773 8.010807037
		 6.65794373 192.85919189 8.45041084 27.605896 186.17996216 24.75491905 35.011211395 175.48007202 34.17924881
		 14.6638031 177.95057678 51.14144897 21.88977051 174.94055176 63.78247833 38.73429108 158.60510254 78.86238098
		 49.28596115 149.63624573 87.099372864 43.56724548 159.92948914 76.24756622 40.018989563 165.47775269 69.46816254
		 38.26535797 168.6131897 65.84185028 33.82073593 174.80233765 56.52180481 26.71416473 181.1342926 43.35707092
		 19.16228485 185.84233093 30.05557251 6.91327667 192.8581543 8.22416115 3.086883545 192.31307983 1.78542137
		 10.74422455 191.9203949 14.86474419 6.29202652 197.088241577 10.14054108 31.66212273 197.094100952 3.79686737
		 -8.0098724365 191.75761414 -6.92169571 6.36483383 185.32420349 -26.11421585 66.82835388 174.31573486 -20.025705338
		 94.81019592 136.86166382 -51.21632767 88.92198181 134.89859009 -58.41622162 57.4800415 163.49668884 -57.95410919
		 49.28714752 186.24813843 -8.23662376 28.33051491 178.49139404 -40.28969193 45.6322403 167.43652344 -50.35739899
		 78.68206787 164.51239014 -32.64360809 87.20360565 147.41508484 -41.26442719 76.89903259 147.42828369 -60.085227966
		 92.43101501 137.93539429 -56.084594727 82.83500671 149.30487061 -51.39932251 70.042945862 165.17271423 -43.69713211
		 58.67340469 176.22167969 -37.072990417 40.44047928 186.89564514 -26.80399895 19.10343933 193.70704651 -13.80323792
		 -1.10767746 195.86825562 -0.29862213 5.55996323 194.15124512 -11.15287399 -8.36257553 201.44392395 -32.054161072
		 -6.060817719 193.55383301 8.5621109 -29.73091125 198.18048096 2.67191315 -50.20795441 197.16062927 -55.5839386
		 -102.20417786 181.33755493 -69.89019012 -107.031318665 181.36961365 -61.70111465
		 -83.25022888 200.94937134 -32.4137001 -29.16044617 199.84622192 -43.80051422 -52.010990143 201.85189819 -12.16862297
		 -71.16106415 199.21691895 -24.38539886 -69.057579041 195.6542511 -61.76858521 -86.68360901 185.38064575 -66.56747437
		 -98.7624054 191.027252197 -49.75601196 -104.95254517 183.81118774 -65.78639221 -92.75780487 190.32969666 -58.56852722
		 -74.97895813 199.072265625 -49.5005188 -60.71278763 204.19332886 -41.4087677 -41.24634933 206.23202515 -28.41927528
		 -20.16443253 203.13067627 -13.70130157 -1.10767746 195.86825562 -0.29862404 11.59956551 189.85513306 -3.70194244
		 21.61261559 203.5625 -23.59494019 -11.15888786 187.40283203 -4.046867371 -18.75939369 197.27403259 -25.52163315
		 20.36595726 211.64076233 -71.09462738 6.95057821 208.56878662 -125.58532715 -2.52558041 207.82008362 -125.65698242
		 -16.77261353 216.55102539 -86.57434845 20.99376297 208.099502563 -47.092033386 -17.93766785 207.7721405 -50.40611267
		 -17.2190361 211.10971069 -73.017227173 16.0088176727 214.80155945 -90.24800873 11.81771469 209.020874023 -109.9526062
		 -9.21226883 213.24723816 -110.48580933 1.83135843 210.61962891 -125.2674408 1.45821762 213.26942444 -109.90060425
		 2.21580267 216.69161987 -88.39564514 2.28324795 217.44961548 -71.23038483 1.1184454 213.32609558 -48.13352203
		 -0.2649622 203.6159668 -24.16513062 -1.23637128 190.52388 -3.5935936 10.92074871 -2.40213013 -11.21111679
		 0.59163517 -2.40213013 -15.48957062 -9.7374754 -2.40213013 -11.21111679 -14.015929222 -2.40213013 -0.88200551
		 -9.7374754 -2.40213013 9.44710732 0.59163553 -2.40213013 13.72555923 10.9207468 -2.40213013 9.44710636
		 15.19920158 -2.40213013 -0.88200551 5.60260344 39.12249756 -5.8933897 -2.080478191 39.12249756 -9.075828552
		 -9.76356316 39.12249756 -5.8933897 -12.94600105 39.12249756 1.78969431 -9.76356316 39.12249756 9.47277927
		 -2.080478191 39.12249756 12.65521717 5.60260439 39.12249756 9.47278023 8.78504276 39.12249756 1.78969431
		 5.72265768 61.13031769 -5.35701418 -0.4807294 61.13031006 -7.92653513 -6.68411589 61.13031387 -5.35701227
		 -9.25364304 61.13031006 0.84636861 -6.68411589 61.13031769 7.049753189 -0.4807294 61.13031387 9.61928368
		 5.72265863 61.13031006 7.049754143 8.29218483 61.13031387 0.84636861 5.35376692 97.31216431 -5.64413691
		 0.59163445 97.31214905 -7.61667395 -4.17049456 97.31217957 -5.64413691 -6.14303637 97.31214905 -0.88200647
		 -4.17049456 97.31216431 3.88012433 0.59163445 97.31215668 5.85266209 5.35376596 97.31217957 3.88012528
		 7.32630491 97.31215668 -0.88200742 0.35780627 129.40905762 -2.83294129 -4.40334892 129.40908813 -4.63355398
		 -9.16450882 129.40907288 -2.83294177 -11.13664722 129.40908813 1.51412201 -9.16450691 129.40905762 5.86118507
		 -4.40334892 129.40908813 7.66179848 0.35780817 129.40907288 5.86118603 2.32994699 129.40908813 1.51412201
		 -0.43879062 154.65766907 -3.38735509 -3.85464883 154.65769958 -4.80224705 -7.27052641 154.65769958 -3.38735509
		 -8.68542385 154.65769958 0.028530061 -7.27052641 154.65766907 3.44440103 -3.85464883 154.65768433 4.85930157
		 -0.43878967 154.65768433 3.44440198 0.97610825 154.65768433 0.028530061 3.24296832 172.60092163 -3.53333354
		 0.59163445 172.60092163 -4.63154697 -2.05968833 172.60092163 -3.53333354 -3.15790629 172.60092163 -0.88200837
		 -2.05968833 172.60092163 1.76931643 0.59163445 172.60092163 2.86753631 3.24296355 172.60092163 1.76931453;
	setAttr ".vt[332:497]" 4.34117842 172.60092163 -0.88200837 3.54343677 184.41290283 -3.35716081
		 1.44572902 184.41290283 -4.22605658 -0.65198821 184.41290283 -3.35716081 -1.52089047 184.41290283 -1.25944173
		 -0.65198821 184.41290283 0.83827382 1.44572902 184.41290283 1.70718169 3.5434339 184.41288757 0.83827478
		 4.41234255 184.41290283 -1.25944173 2.15554237 192.040145874 -2.76237869 0.38708752 192.040145874 -3.49489951
		 -1.38136768 192.040145874 -2.76237679 -2.11388588 192.040145874 -0.99392265 -1.38137054 192.040145874 0.77453238
		 0.38708752 192.040145874 1.50704885 2.15554333 192.040145874 0.77453333 2.88805652 192.040145874 -0.99392265
		 -0.85914403 195.86825562 -0.40157324 -0.96209103 195.86825562 -0.44421369 -1.065037012 195.86825562 -0.40157324
		 -1.10767651 195.86825562 -0.29862434 -1.065037012 195.86825562 -0.19567472 -0.96209103 195.86825562 -0.15302974
		 -0.85914356 195.86825562 -0.19567472 -0.81650168 195.86825562 -0.29862434 -0.67141342 -7.28486538 17.96166611
		 -14.19132233 34.67501068 16.24927139 10.36909866 40.73860168 14.80595684 22.062408447 35.55652618 1.90644073
		 10.97830963 -3.53118992 15.40857601 13.95475388 -2.68721676 14.1738863 12.27655029 -1.18861485 15.064034462
		 -12.72698975 -1.57209587 18.1734314 21.61424637 -0.37970924 7.76711941 30.40754509 6.039995193 -8.20355034
		 24.99765015 25.25379753 0.10128355 -11.82655334 17.047920227 18.42050171 11.82793427 21.72021675 16.1518631
		 12.31019592 4.28793144 15.61847019 2.95481682 192.30776978 1.65525818 9.20164871 199.37516785 -15.48791504
		 10.19551086 202.49880981 -6.37586212 3.22891426 192.31924438 1.92379761 17.50616264 200.96636963 -3.6894455
		 11.671772 202.99378967 -6.44886017 33.13551331 218.71289063 -51.028934479 72.66213226 226.73982239 -70.64620209
		 74.52064514 226.68544006 -68.72509766 46.69525528 222.28924561 -56.98994446 56.95878983 222.96055603 -64.25760651
		 52.89390182 222.62414551 -56.16947937 59.5930748 223.37573242 -40.18917084 63.086860657 222.92176819 -48.82209015
		 55.80577469 222.75227356 -43.86769104 58.30358505 223.046081543 -49.60861588 33.072479248 206.349823 -11.71377563
		 6.28108215 197.83428955 -2.075515747 6.82814407 197.9052124 -1.70796967 14.78248405 210.34112549 -24.75883484
		 24.2527771 210.81916809 -37.72916412 44.76709366 214.83943176 -21.27204514 53.48434067 222.68450928 -30.41179085
		 66.34170532 225.88409424 -54.95642853 72.85864258 228.10295105 -69.52462769 61.76031494 227.13299561 -58.022346497
		 55.20944595 225.89718628 -51.32214355 51.57461929 225.41149902 -47.77131271 43.039081573 222.83261108 -39.68320847
		 32.3765831 217.13465881 -28.83186722 22.49902344 210.014938354 -18.44582748 6.54659081 197.86869812 -1.89713287
		 3.086875916 192.31307983 1.78541946 10.82632256 202.4690094 -6.3886795 3.10741425 192.30152893 1.96942902
		 -11.038734436 181.6708374 10.32011986 -11.18977356 188.56414795 3.52057648 3.063892365 192.32473755 1.5887146
		 -12.23357773 185.36181641 -3.6673584 -12.27375603 187.95428467 2.58103943 -49.10123062 155.97264099 20.35960388
		 -79.36969757 125.64351654 7.10870743 -79.52156067 125.79426575 4.44377518 -59.93139648 146.49401855 15.35425758
		 -67.29671478 136.48631287 13.30295563 -62.65647888 143.7220459 10.44521904 -61.10887146 150.52220154 -5.43486023
		 -65.0090103149 142.83987427 -1.86967087 -60.10629654 149.97467041 -0.24266434 -63.27710724 145.084991455 2.063995361
		 -26.11850739 174.40969849 -8.45706558 -4.18439865 191.0076446533 2.79426575 -4.36544037 190.97250366 2.15756989
		 -25.65924454 178.48745728 13.98817253 -34.33705521 165.19837952 16.48625946 -41.41622925 166.30311584 -9.13602066
		 -54.73865128 159.7869873 -8.076030731 -70.88046265 138.69543457 0.44315338 -80.24384308 126.97089386 6.31585312
		 -70.91056824 139.97746277 5.94807816 -64.87207794 147.24534607 5.72836304 -61.74307251 151.27838135 5.74346161
		 -53.26539993 159.82518005 5.81326675 -40.35334778 169.65983582 5.1309433 -26.73658752 178.0032348633 4.083114624
		 -4.27226639 190.99058533 2.48525238 3.08687973 192.31309509 1.78543091 -11.44412231 188.18688965 3.082435608
		 -2.98568726 193.39733887 12.17486286 19.11012268 196.39587402 25.83751678 -0.5627594 194.27088928 -10.57258224
		 23.8648262 195.66397095 -14.78283691 65.771492 184.82040405 29.26647949 116.16689301 162.077392578 19.18164063
		 117.21464539 162.71646118 9.75523949 86.77531433 188.32385254 -5.22368479 42.4005661 191.15945435 27.63087082
		 50.51936722 195.060272217 -10.39037895 72.36050415 188.90420532 -7.56445551 85.066253662 180.6125946 26.85113716
		 101.40772247 168.069107056 22.99494171 106.33641052 174.66503906 3.18059254 117.35029602 164.78747559 14.51597786
		 104.38041687 173.40509033 13.61078262 85.94848633 185.024414063 13.54668808 70.55002594 192.58937073 12.60651207
		 48.023048401 198.29255676 9.16639519 22.58330154 199.32136536 4.42875862 -1.10768127 195.86825562 -0.29862499
		 -13.94496059 196.12773132 -0.89611053 -24.36731148 202.22120667 22.30148697 8.58938122 192.097747803 -0.68992615
		 15.42570114 192.79130554 23.16709518 -25.49788094 192.11988831 69.41536713 -15.50840759 168.23635864 119.29956055
		 -6.10672855 166.83734131 119.41983795 10.87099934 188.30847168 86.90203857 -24.89547348 197.72547913 45.80872345
		 13.6987524 193.41293335 50.12546539 11.82548046 188.22764587 72.31830597 -22.11675644 187.68113708 88.51229858
		 -19.41243172 174.76333618 104.79328156 1.745399 176.97821045 107.59456635 -10.2769022 169.88777161 119.94578552
		 -8.85536957 177.97854614 106.68611908 -8.15703392 189.12767029 87.97894287 -7.16974068 196.15907288 72.33254242
		 -4.8651042 200.76287842 49.41270447 -2.59018683 200.49389648 23.616642 -1.10767651 195.86825562 -0.29862976
		 3.086639404 192.36592102 1.60759735 17.87311935 184.44332886 -8.46472931 17.39669991 188.59513855 0.27083206
		 3.088153839 192.25588989 1.97538376 17.57923889 183.087585449 5.98436737 18.35860825 187.64334106 1.044460297
		 56.335495 161.62869263 -22.95887756 84.38915253 126.97930908 -18.056335449 84.24772644 126.20652771 -15.50086212
		 66.36912537 150.4304657 -20.48579025 73.27722168 139.93103027 -21.2920475 68.48256683 146.0088195801 -16.5882206
		 65.31101227 147.080078125 0.42964935 69.44039154 140.86436462 -5.16078568 64.87966919 148.38644409 -4.7056427
		 68.19618988 144.40496826 -8.23158646 30.64518929 170.41065979 8.047843933;
	setAttr ".vt[498:663]" 10.39997864 191.029006958 1.1048851 10.50872803 190.76957703 1.70510101
		 32.74903107 181.8944397 -11.55635834 41.40490723 169.78843689 -17.61153984 45.62238693 161.72460938 7.3889389
		 58.85849762 155.23193359 5.45997238 75.45483398 137.43553162 -8.17227936 85.19432068 127.90769958 -16.77396393
		 76.11784363 140.50883484 -12.86950111 70.22647095 147.59078979 -10.75491333 67.19287109 151.55499268 -9.68779755
		 58.93325043 160.070709229 -7.64213562 46.20760345 169.78463745 -4.88449478 32.71387482 178.013183594 -2.36722946
		 10.45275879 190.90309143 1.39619064 3.08687973 192.31309509 1.78541946 17.59400368 188.077972412 0.57512283
		 2.95333099 192.31207275 1.91416645 -13.43845367 200.93997192 -4.38885593 -4.093338013 203.39428711 -5.036561012
		 3.22893524 192.3147583 1.64694118 -1.34342957 201.97819519 -12.34706974 -4.090583801 203.95692444 -6.49021816
		 -46.78384399 223.97059631 -28.21357727 -64.71217346 235.18656921 -67.7660675 -62.75349426 235.065307617 -69.58171082
		 -52.10558319 228.57867432 -41.72783661 -59.034790039 230.25061035 -52.11053085 -51.10276794 229.11782837 -47.88512039
		 -34.94426727 228.92880249 -54.18444061 -43.49393463 229.29139709 -57.88736343 -38.75574875 228.42633057 -50.51238632
		 -44.39168549 229.26838684 -53.12214279 -8.53326416 208.63183594 -27.82985687 -0.26103973 198.24786377 -1.24165249
		 0.12477875 198.3139801 -1.77659321 -21.70496368 212.81742859 -9.67455578 -34.35361862 214.70069885 -19.40128326
		 -17.11643219 218.32963562 -39.33985901 -25.40792084 227.22421265 -47.89603043 -49.30031586 232.85461426 -61.14143372
		 -63.48583984 236.46670532 -67.87566376 -52.37972641 234.13571167 -56.578022 -45.96333313 232.10597229 -49.94146347
		 -42.55429077 231.19178772 -46.25378418 -34.90732574 227.63154602 -37.664711 -24.79711151 220.65989685 -27.030487061
		 -15.23823547 212.34179688 -17.25483322 -0.073783875 198.279953 -1.50128078 3.086875916 192.31307983 1.78542233
		 -4.092132568 203.39292908 -5.66820621 3.2497654 192.2979126 1.87289047 1.34766388 184.48136902 19.70944977
		 -3.66990852 191.28266907 14.98285675 2.91210938 192.32881165 1.69286728 -10.54309845 188.33010864 12.32719421
		 -5.10646439 190.88487244 15.43865204 -13.79438591 166.30447388 60.33285904 -44.4984436 142.12886047 82.34246826
		 -46.77960968 142.3052063 80.95941925 -24.85772324 159.0036773682 67.84892273 -31.62646866 150.53909302 74.26335144
		 -30.71313095 156.78643799 67.76789856 -42.35402298 163.18051147 56.61354828 -42.32102966 156.35682678 62.96775818
		 -37.54919434 162.45619202 58.77058411 -37.8736763 158.2409668 63.39770508 -23.25091934 180.14918518 22.68409729
		 -0.18802071 192.38169861 8.48345947 -0.81958389 192.3808136 8.28216553 -3.93310928 184.070556641 34.17639542
		 -7.98034668 172.62568665 44.7015686 -33.022510529 175.026779175 36.043548584 -40.10443115 171.10003662 48.51341629
		 -44.040710449 153.37573242 69.68753815 -45.49791718 143.5955658 82.40960693 -39.35173798 154.64103699 72.57913208
		 -35.47881317 160.66011047 66.40620422 -33.33720398 164.041381836 63.2381134 -27.75706482 170.86376953 55.038078308
		 -20.24255562 178.12750244 42.60113907 -12.80044556 183.79498291 29.61571503 -0.49454308 192.38127136 8.38576126
		 3.086883545 192.31309509 1.78542328 -4.21203613 190.95925903 15.0047531128 -11.1228714 191.30082703 6.33874512
		 -9.64165497 198.086181641 31.55083084 7.54146004 195.89784241 -6.094688416 24.55390549 204.21856689 9.95884705
		 17.87418747 198.80622864 71.11587524 60.96129608 191.69775391 106.49406433 68.64621735 193.87886047 101.34158325
		 55.62409973 212.40606689 65.37177277 3.88349915 198.95135498 51.28411865 36.77832794 210.034179688 33.34399033
		 48.9179306 209.49867249 52.7156601 32.044368744 200.18360901 85.013221741 47.86171722 193.022476196 96.75131226
		 64.17713928 203.33947754 87.3825531 64.50406647 195.23809814 104.16419983 55.36158752 200.18902588 92.53648376
		 41.59807587 206.45765686 76.85150146 31.35979843 209.77058411 63.45643997 19.41755676 209.77793884 43.22754669
		 8.047592163 204.73464966 20.51250076 -1.10767365 195.86825562 -0.29862595 7.73354912 186.61862183 -3.019583702
		 17.20197678 178.56340027 9.99812508 9.15255737 178.78820801 16.39222527 1.95426941 178.16069031 15.88656425
		 3.14358711 185.86439514 -0.03123951 2.0061302185 185.68499756 0.68646526 2.9347477 185.53707886 0.99627495
		 15.55990982 184.94471741 -4.12111044 -1.45291042 185.12026978 2.92739582 -6.51615143 182.13348389 6.85210562
		 -0.7741642 179.5149231 12.37246704 16.4451561 182.42678833 3.40763807 6.24729919 182.31307983 9.29275322
		 3.72265816 184.84625244 2.97933531 -4.46976662 193.24841309 -0.59016132 -2.772995 181.61219788 -14.21798801
		 7.34798813 183.32913208 -14.80619717 12.76961994 184.72616577 -10.21065426 1.040645599 193.45211792 -0.18932056
		 2.39125061 193.51217651 -0.073773384 1.87481499 193.087188721 -0.80375099 -10.99751282 189.6481781 -3.70367718
		 6.53667641 193.67034912 0.23619175 13.32723522 191.76669312 0.71054459 12.57311344 187.12887573 -6.233778
		 -6.75614166 186.20733643 -9.53266621 4.79020309 188.23417664 -8.42920589 2.56237125 192.0045928955 -2.64382076
		 5.0073890686 191.27227783 0.92569351 2.32442474 179.63606262 14.39411736 -7.81254005 181.35299683 14.24502182
		 -12.88575172 182.75003052 9.26750374 -0.4593029 191.47598267 0.12533188 -1.79793549 191.53604126 -0.088092804
		 -1.33593369 191.11105347 0.67749596 11.29152489 187.67204285 4.50551033 -5.90985966 191.69421387 -0.69859219
		 -12.64796925 189.79055786 -1.66533279 -12.40066528 185.15274048 5.31543827 6.63763428 184.23120117 10.01074791
		 -4.79794312 186.25804138 8.070837021 -2.15543461 190.028457642 2.4627142 -3.62384701 191.4540863 2.87395
		 -15.14750195 179.81787109 -4.59612846 -11.26302052 181.5348053 -13.96048069 -4.76310635 182.93183899 -16.83524323
		 -0.86001492 191.65779114 -1.91003704 -0.16702843 191.71784973 -3.075051308 -1.049151421 191.29286194 -2.92866039
		 -9.27246761 187.85385132 7.39042377 1.91974735 191.87602234 -6.6703248 5.30801105 189.97236633 -12.57425308
		 -1.27003193 185.33454895 -14.92407608 -12.66827106 184.41300964 1.031580925 -6.63985348 186.43984985 -8.87770271
		 -2.40517712 190.21026611 -4.34985256 3.18470001 192.32087708 1.62800074 22.42776108 193.55410767 4.9511323
		 14.80903625 198.031143188 8.91164398 2.98332214 192.30480957 1.95443964;
	setAttr ".vt[664:769]" 13.18833923 194.97444153 16.055921555 15.27791595 198.038497925 10.39818001
		 65.56239319 197.21202087 23.28048897 93.45467377 188.9304657 57.41344833 91.95917511 188.71868896 59.61942673
		 74.62122345 195.29515076 35.38229752 83.54732513 191.38334656 43.35927963 75.060424805 193.93008423 41.47755814
		 61.34666443 195.89862061 51.91172791 70.035919189 192.67353821 52.92939758 63.97566605 195.69360352 47.29543686
		 69.94378662 194.052566528 48.28143311 25.045097351 193.72459412 29.96766663 8.78804779 195.72360229 5.17045259
		 8.55833054 195.70195007 5.79186487 35.1297226 200.22805786 10.56062698 49.26003265 195.20823669 16.32953453
		 38.47412491 196.21083069 40.62965012 50.79445648 199.067520142 48.4475441 77.22203064 193.21559143 55.1800766
		 92.7899704 190.37214661 58.20993423 79.62319183 195.11813354 50.42997742 71.75984192 197.28271484 45.65336227
		 67.60780334 198.63623047 43.010467529 57.71311951 200.42216492 36.39011383 43.98787689 200.4961853 27.69991684
		 30.46884918 198.91567993 19.28182411 8.67655945 195.71308899 5.47204828 3.086875916 192.31309509 1.78541994
		 14.92798615 197.81298828 9.49236488 2.92208481 192.2885437 1.86698723 -11.82889938 192.88105774 -10.9750061
		 -3.9697113 198.41218567 -9.78581619 3.26255417 192.33943176 1.69708633 1.5005455 196.69352722 -15.27519226
		 -3.60354233 198.63853455 -11.28393745 -39.42668915 196.90170288 -48.81861115 -44.33492279 192.73667908 -93.20536804
		 -41.90579987 192.98718262 -94.29360962 -40.60635376 196.47885132 -64.0047912598 -43.51535797 193.41346741 -75.86863708
		 -37.65477753 196.12438965 -69.51578522 -20.95953751 200.63780212 -70.8243103 -27.34082794 197.10296631 -76.63154602
		 -25.52872086 199.50624084 -68.35328674 -29.84422684 197.69116211 -72.52049255 -1.21004105 197.057891846 -33.39152527
		 -0.47455978 195.88546753 -3.70526505 0.04227829 195.98171997 -4.10899734 -20.62772369 199.60829163 -21.68354034
		 -28.92173767 194.76676941 -34.56427765 -7.44300461 200.46150208 -49.1954422 -14.251091 203.82339478 -61.97895432
		 -32.34183502 197.57272339 -82.26792908 -43.56414795 194.32879639 -93.36579895 -37.081058502 198.50686646 -79.33265686
		 -33.18281174 200.32119751 -70.91566467 -31.21588135 201.46630859 -66.34661865 -26.49315643 202.72479248 -55.34499741
		 -19.35329819 202.18748474 -40.76278687 -12.017242432 200.054672241 -26.70008087 -0.22371674 195.93217468 -3.90121269
		 3.086875916 192.31307983 1.78542709 -3.74146652 198.28700256 -10.36133003 -9.55893326 197.53771973 -9.83850861
		 -32.44943237 206.33818054 -0.75771332 5.41600037 191.0065917969 6.1981926 -6.65682983 192.54602051 27.83729172
		 -67.91172791 199.66387939 31.19400215 -99.38424683 178.2583313 72.54528809 -93.12461853 175.81565857 79.26940155
		 -55.55411911 192.96110535 69.21200562 -50.048603058 203.54350281 15.22790527 -26.87860107 195.19468689 45.56262207
		 -44.56797028 191.7791748 59.64590454 -79.66575623 196.18266296 46.86408615 -90.97886658 184.18145752 59.7961235
		 -77.99900055 184.1730957 76.88208008 -96.00071716309 179.34718323 76.77370453 -84.58319092 186.30259705 68.73861694
		 -69.41603088 196.00016784668 56.46412659 -56.74410629 201.79200745 46.40916061 -38.31464767 204.53277588 32.1029129
		 -18.49115372 202.25083923 15.59515762 -1.10767746 195.86825562 -0.29862595 -0.41136932 193.73335266 -12.95475292
		 -23.70793915 196.97540283 -24.38467216 -0.67437744 194.00048828125 9.9349699 -24.59780884 195.15927124 16.4695282
		 -70.454422 185.25686646 -23.69522667 -119.61130524 162.0030059814 -9.49998283 -119.76451874 162.39047241 -0.0031591654
		 -88.11120605 187.75219727 12.70555878 -47.050003052 191.66952515 -24.10765076 -51.54664612 194.5352478 14.60041523
		 -73.54117584 188.34434509 13.68858719 -89.42334747 180.88961792 -19.5800705 -105.29443359 168.16700745 -14.53064537
		 -108.34413147 174.21836853 5.82831335 -120.35514069 164.58433533 -4.67330074 -107.38008118 173.24105835 -4.76969194
		 -89.054763794 184.9480896 -6.13969517 -73.65597534 192.56394958 -6.45857048 -50.91942596 198.28956604 -5.012293339
		 -25.14838791 199.32337952 -2.67365122 -1.10767365 195.86825562 -0.2986244;
	setAttr -s 1179 ".ed";
	setAttr ".ed[0:165]"  0 32 0 0 17 0 2 1 0 4 16 0 3 18 0 5 4 0 6 20 0 7 24 0
		 6 9 0 10 7 0 10 11 0 11 9 0 13 23 0 12 14 0 14 15 0 15 13 0 21 22 0 16 21 0 17 2 0
		 18 5 0 17 31 1 19 1 0 16 30 1 20 19 0 20 29 1 22 12 0 22 28 1 14 27 1 23 8 0 10 25 1
		 15 26 1 24 8 0 25 23 1 26 11 1 27 9 1 28 6 1 29 21 1 30 19 1 31 18 1 32 3 0 24 25 1
		 25 26 1 26 27 1 27 28 1 28 29 1 29 30 1 30 33 1 31 32 1 33 31 1 2 33 1 33 5 1 34 35 0
		 36 54 0 37 43 0 36 37 0 38 42 0 38 45 0 40 48 0 40 47 0 37 53 1 42 35 0 43 44 0 42 52 1
		 44 41 0 38 51 1 45 46 0 45 50 1 46 39 0 47 41 0 46 49 1 48 39 0 49 47 1 50 41 1 51 44 1
		 52 43 1 53 35 1 54 34 0 48 49 1 49 50 1 50 51 1 51 52 1 52 53 1 53 54 1 55 56 0 57 75 0
		 58 64 0 57 58 0 59 63 0 59 66 0 61 69 0 61 68 0 58 74 1 63 56 0 64 65 0 63 73 1 65 62 0
		 59 72 1 66 67 0 66 71 1 67 60 0 68 62 0 67 70 1 69 60 0 70 68 1 71 62 1 72 65 1 73 64 1
		 74 56 1 75 55 0 69 70 1 70 71 1 71 72 1 72 73 1 73 74 1 74 75 1 76 77 0 78 96 0 79 85 0
		 78 79 0 80 84 0 80 87 0 82 90 0 82 89 0 79 95 1 84 77 0 85 86 0 84 94 1 86 83 0 80 93 1
		 87 88 0 87 92 1 88 81 0 89 83 0 88 91 1 90 81 0 91 89 1 92 83 1 93 86 1 94 85 1 95 77 1
		 96 76 0 90 91 1 91 92 1 92 93 1 93 94 1 94 95 1 95 96 1 97 98 0 99 117 0 100 106 0
		 99 100 0 101 105 0 101 108 0 103 111 0 103 110 0 100 116 1 105 98 0 106 107 0 105 115 1
		 107 104 0 101 114 1 108 109 0 108 113 1 109 102 0 110 104 0 109 112 1;
	setAttr ".ed[166:331]" 111 102 0 112 110 1 113 104 1 114 107 1 115 106 1 116 98 1
		 117 97 0 111 112 1 112 113 1 113 114 1 114 115 1 115 116 1 116 117 1 118 150 0 118 135 0
		 120 119 0 122 134 0 121 136 0 123 122 0 124 138 0 125 142 0 124 127 0 128 125 0 128 129 0
		 129 127 0 131 141 0 130 132 0 132 133 0 133 131 0 139 140 0 134 139 0 135 120 0 136 123 0
		 135 149 1 137 119 0 134 148 1 138 137 0 138 147 1 140 130 0 140 146 1 132 145 1 141 126 0
		 128 143 1 133 144 1 142 126 0 143 141 1 144 129 1 145 127 1 146 124 1 147 139 1 148 137 1
		 149 136 1 150 121 0 142 143 1 143 144 1 144 145 1 145 146 1 146 147 1 147 148 1 148 151 1
		 149 150 1 151 149 1 120 151 1 151 123 1 152 156 0 152 159 0 153 154 0 154 155 0 155 162 0
		 157 160 0 156 158 0 158 157 0 159 163 0 160 161 0 162 161 0 163 153 0 162 164 1 159 165 1
		 164 163 1 165 161 1 154 164 1 164 165 1 165 158 1 166 170 0 166 173 0 167 168 0 168 169 0
		 169 176 0 171 174 0 170 172 0 172 171 0 173 177 0 174 175 0 176 175 0 177 167 0 176 178 1
		 173 179 1 178 177 1 179 175 1 168 178 1 178 179 1 179 172 1 180 212 0 180 197 0 182 181 0
		 184 196 0 183 198 0 185 184 0 186 200 0 187 204 0 186 189 0 190 187 0 190 191 0 191 189 0
		 193 203 0 192 194 0 194 195 0 195 193 0 201 202 0 196 201 0 197 182 0 198 185 0 197 211 1
		 199 181 0 196 210 1 200 199 0 200 209 1 202 192 0 202 208 1 194 207 1 203 188 0 190 205 1
		 195 206 1 204 188 0 205 203 1 206 191 1 207 189 1 208 186 1 209 201 1 210 199 1 211 198 1
		 212 183 0 204 205 1 205 206 1 206 207 1 207 208 1 208 209 1 209 210 1 210 213 1 211 212 1
		 213 211 1 182 213 1 213 185 1 214 215 0 216 234 0 217 223 0 216 217 0 218 222 0 218 225 0
		 220 228 0 220 227 0 217 233 1 222 215 0 223 224 0 222 232 1 224 221 0;
	setAttr ".ed[332:497]" 218 231 1 225 226 0 225 230 1 226 219 0 227 221 0 226 229 1
		 228 219 0 229 227 1 230 221 1 231 224 1 232 223 1 233 215 1 234 214 0 228 229 1 229 230 1
		 230 231 1 231 232 1 232 233 1 233 234 1 235 236 0 237 255 0 238 244 0 237 238 0 239 243 0
		 239 246 0 241 249 0 241 248 0 238 254 1 243 236 0 244 245 0 243 253 1 245 242 0 239 252 1
		 246 247 0 246 251 1 247 240 0 248 242 0 247 250 1 249 240 0 250 248 1 251 242 1 252 245 1
		 253 244 1 254 236 1 255 235 0 249 250 1 250 251 1 251 252 1 252 253 1 253 254 1 254 255 1
		 256 257 0 258 276 0 259 265 0 258 259 0 260 264 0 260 267 0 262 270 0 262 269 0 259 275 1
		 264 257 0 265 266 0 264 274 1 266 263 0 260 273 1 267 268 0 267 272 1 268 261 0 269 263 0
		 268 271 1 270 261 0 271 269 1 272 263 1 273 266 1 274 265 1 275 257 1 276 256 0 270 271 1
		 271 272 1 272 273 1 273 274 1 274 275 1 275 276 1 277 278 0 278 279 0 279 280 0 280 281 0
		 281 282 0 282 283 0 283 284 0 284 277 0 285 286 1 286 287 1 287 288 1 288 289 1 289 290 1
		 290 291 1 291 292 1 292 285 1 293 294 1 294 295 1 295 296 1 296 297 1 297 298 1 298 299 1
		 299 300 1 300 293 1 301 302 1 302 303 1 303 304 1 304 305 1 305 306 1 306 307 1 307 308 1
		 308 301 1 309 310 1 310 311 1 311 312 1 312 313 1 313 314 1 314 315 1 315 316 1 316 309 1
		 317 318 1 318 319 1 319 320 1 320 321 1 321 322 1 322 323 1 323 324 1 324 317 1 325 326 1
		 326 327 1 327 328 1 328 329 1 329 330 1 330 331 1 331 332 1 332 325 1 333 334 1 334 335 1
		 335 336 1 336 337 1 337 338 1 338 339 1 339 340 1 340 333 1 341 342 1 342 343 1 343 344 1
		 344 345 1 345 346 1 346 347 1 347 348 1 348 341 1 349 350 0 350 351 0 351 352 0 352 353 0
		 353 354 0 354 355 0 355 356 0 356 349 0 277 285 1 278 286 1 279 287 1;
	setAttr ".ed[498:663]" 280 288 1 281 289 1 282 290 1 283 291 1 284 292 1 285 293 1
		 286 294 1 287 295 1 288 296 1 289 297 1 290 298 1 291 299 1 292 300 1 293 301 1 294 302 1
		 295 303 1 296 304 1 297 305 1 298 306 1 299 307 1 300 308 1 301 309 1 302 310 1 303 311 1
		 304 312 1 305 313 1 306 314 1 307 315 1 308 316 1 309 317 1 310 318 1 311 319 1 312 320 1
		 313 321 1 314 322 1 315 323 1 316 324 1 317 325 1 318 326 1 319 327 1 320 328 1 321 329 1
		 322 330 1 323 331 1 324 332 1 325 333 1 326 334 1 327 335 1 328 336 1 329 337 1 330 338 1
		 331 339 1 332 340 1 333 341 1 334 342 1 335 343 1 336 344 1 337 345 1 338 346 1 339 347 1
		 340 348 1 341 349 1 342 350 1 343 351 1 344 352 1 345 353 1 346 354 1 347 355 1 348 356 1
		 357 361 0 357 364 0 358 359 0 359 360 0 360 367 0 362 365 0 361 363 0 363 362 0 364 368 0
		 365 366 0 367 366 0 368 358 0 367 369 1 364 370 1 369 368 1 370 366 1 359 369 1 369 370 1
		 370 363 1 371 403 0 371 388 0 373 372 0 375 387 0 374 389 0 376 375 0 377 391 0 378 395 0
		 377 380 0 381 378 0 381 382 0 382 380 0 384 394 0 383 385 0 385 386 0 386 384 0 392 393 0
		 387 392 0 388 373 0 389 376 0 388 402 1 390 372 0 387 401 1 391 390 0 391 400 1 393 383 0
		 393 399 1 385 398 1 394 379 0 381 396 1 386 397 1 395 379 0 396 394 1 397 382 1 398 380 1
		 399 377 1 400 392 1 401 390 1 402 389 1 403 374 0 395 396 1 396 397 1 397 398 1 398 399 1
		 399 400 1 400 401 1 401 404 1 402 403 1 404 402 1 373 404 1 404 376 1 405 437 0 405 422 0
		 407 406 0 409 421 0 408 423 0 410 409 0 411 425 0 412 429 0 411 414 0 415 412 0 415 416 0
		 416 414 0 418 428 0 417 419 0 419 420 0 420 418 0 426 427 0 421 426 0 422 407 0 423 410 0
		 422 436 1 424 406 0 421 435 1 425 424 0 425 434 1 427 417 0 427 433 1;
	setAttr ".ed[664:829]" 419 432 1 428 413 0 415 430 1 420 431 1 429 413 0 430 428 1
		 431 416 1 432 414 1 433 411 1 434 426 1 435 424 1 436 423 1 437 408 0 429 430 1 430 431 1
		 431 432 1 432 433 1 433 434 1 434 435 1 435 438 1 436 437 1 438 436 1 407 438 1 438 410 1
		 439 440 0 441 459 0 442 448 0 441 442 0 443 447 0 443 450 0 445 453 0 445 452 0 442 458 1
		 447 440 0 448 449 0 447 457 1 449 446 0 443 456 1 450 451 0 450 455 1 451 444 0 452 446 0
		 451 454 1 453 444 0 454 452 1 455 446 1 456 449 1 457 448 1 458 440 1 459 439 0 453 454 1
		 454 455 1 455 456 1 456 457 1 457 458 1 458 459 1 460 461 0 462 480 0 463 469 0 462 463 0
		 464 468 0 464 471 0 466 474 0 466 473 0 463 479 1 468 461 0 469 470 0 468 478 1 470 467 0
		 464 477 1 471 472 0 471 476 1 472 465 0 473 467 0 472 475 1 474 465 0 475 473 1 476 467 1
		 477 470 1 478 469 1 479 461 1 480 460 0 474 475 1 475 476 1 476 477 1 477 478 1 478 479 1
		 479 480 1 481 513 0 481 498 0 483 482 0 485 497 0 484 499 0 486 485 0 487 501 0 488 505 0
		 487 490 0 491 488 0 491 492 0 492 490 0 494 504 0 493 495 0 495 496 0 496 494 0 502 503 0
		 497 502 0 498 483 0 499 486 0 498 512 1 500 482 0 497 511 1 501 500 0 501 510 1 503 493 0
		 503 509 1 495 508 1 504 489 0 491 506 1 496 507 1 505 489 0 506 504 1 507 492 1 508 490 1
		 509 487 1 510 502 1 511 500 1 512 499 1 513 484 0 505 506 1 506 507 1 507 508 1 508 509 1
		 509 510 1 510 511 1 511 514 1 512 513 1 514 512 1 483 514 1 514 486 1 515 547 0 515 532 0
		 517 516 0 519 531 0 518 533 0 520 519 0 521 535 0 522 539 0 521 524 0 525 522 0 525 526 0
		 526 524 0 528 538 0 527 529 0 529 530 0 530 528 0 536 537 0 531 536 0 532 517 0 533 520 0
		 532 546 1 534 516 0 531 545 1 535 534 0 535 544 1 537 527 0 537 543 1;
	setAttr ".ed[830:995]" 529 542 1 538 523 0 525 540 1 530 541 1 539 523 0 540 538 1
		 541 526 1 542 524 1 543 521 1 544 536 1 545 534 1 546 533 1 547 518 0 539 540 1 540 541 1
		 541 542 1 542 543 1 543 544 1 544 545 1 545 548 1 546 547 1 548 546 1 517 548 1 548 520 1
		 549 581 0 549 566 0 551 550 0 553 565 0 552 567 0 554 553 0 555 569 0 556 573 0 555 558 0
		 559 556 0 559 560 0 560 558 0 562 572 0 561 563 0 563 564 0 564 562 0 570 571 0 565 570 0
		 566 551 0 567 554 0 566 580 1 568 550 0 565 579 1 569 568 0 569 578 1 571 561 0 571 577 1
		 563 576 1 572 557 0 559 574 1 564 575 1 573 557 0 574 572 1 575 560 1 576 558 1 577 555 1
		 578 570 1 579 568 1 580 567 1 581 552 0 573 574 1 574 575 1 575 576 1 576 577 1 577 578 1
		 578 579 1 579 582 1 580 581 1 582 580 1 551 582 1 582 554 1 583 584 0 585 603 0 586 592 0
		 585 586 0 587 591 0 587 594 0 589 597 0 589 596 0 586 602 1 591 584 0 592 593 0 591 601 1
		 593 590 0 587 600 1 594 595 0 594 599 1 595 588 0 596 590 0 595 598 1 597 588 0 598 596 1
		 599 590 1 600 593 1 601 592 1 602 584 1 603 583 0 597 598 1 598 599 1 599 600 1 600 601 1
		 601 602 1 602 603 1 604 608 0 604 611 0 605 606 0 606 607 0 607 614 0 609 612 0 608 610 0
		 610 609 0 611 615 0 612 613 0 614 613 0 615 605 0 614 616 1 611 617 1 616 615 1 617 613 1
		 606 616 1 616 617 1 617 610 1 618 622 0 618 625 0 619 620 0 620 621 0 621 628 0 623 626 0
		 622 624 0 624 623 0 625 629 0 626 627 0 628 627 0 629 619 0 628 630 1 625 631 1 630 629 1
		 631 627 1 620 630 1 630 631 1 631 624 1 632 636 0 632 639 0 633 634 0 634 635 0 635 642 0
		 637 640 0 636 638 0 638 637 0 639 643 0 640 641 0 642 641 0 643 633 0 642 644 1 639 645 1
		 644 643 1 645 641 1 634 644 1 644 645 1 645 638 1 646 650 0 646 653 0;
	setAttr ".ed[996:1161]" 647 648 0 648 649 0 649 656 0 651 654 0 650 652 0 652 651 0
		 653 657 0 654 655 0 656 655 0 657 647 0 656 658 1 653 659 1 658 657 1 659 655 1 648 658 1
		 658 659 1 659 652 1 660 692 0 660 677 0 662 661 0 664 676 0 663 678 0 665 664 0 666 680 0
		 667 684 0 666 669 0 670 667 0 670 671 0 671 669 0 673 683 0 672 674 0 674 675 0 675 673 0
		 681 682 0 676 681 0 677 662 0 678 665 0 677 691 1 679 661 0 676 690 1 680 679 0 680 689 1
		 682 672 0 682 688 1 674 687 1 683 668 0 670 685 1 675 686 1 684 668 0 685 683 1 686 671 1
		 687 669 1 688 666 1 689 681 1 690 679 1 691 678 1 692 663 0 684 685 1 685 686 1 686 687 1
		 687 688 1 688 689 1 689 690 1 690 693 1 691 692 1 693 691 1 662 693 1 693 665 1 694 726 0
		 694 711 0 696 695 0 698 710 0 697 712 0 699 698 0 700 714 0 701 718 0 700 703 0 704 701 0
		 704 705 0 705 703 0 707 717 0 706 708 0 708 709 0 709 707 0 715 716 0 710 715 0 711 696 0
		 712 699 0 711 725 1 713 695 0 710 724 1 714 713 0 714 723 1 716 706 0 716 722 1 708 721 1
		 717 702 0 704 719 1 709 720 1 718 702 0 719 717 1 720 705 1 721 703 1 722 700 1 723 715 1
		 724 713 1 725 712 1 726 697 0 718 719 1 719 720 1 720 721 1 721 722 1 722 723 1 723 724 1
		 724 727 1 725 726 1 727 725 1 696 727 1 727 699 1 728 729 0 730 748 0 731 737 0 730 731 0
		 732 736 0 732 739 0 734 742 0 734 741 0 731 747 1 736 729 0 737 738 0 736 746 1 738 735 0
		 732 745 1 739 740 0 739 744 1 740 733 0 741 735 0 740 743 1 742 733 0 743 741 1 744 735 1
		 745 738 1 746 737 1 747 729 1 748 728 0 742 743 1 743 744 1 744 745 1 745 746 1 746 747 1
		 747 748 1 749 750 0 751 769 0 752 758 0 751 752 0 753 757 0 753 760 0 755 763 0 755 762 0
		 752 768 1 757 750 0 758 759 0 757 767 1 759 756 0 753 766 1 760 761 0;
	setAttr ".ed[1162:1178]" 760 765 1 761 754 0 762 756 0 761 764 1 763 754 0 764 762 1
		 765 756 1 766 759 1 767 758 1 768 750 1 769 749 0 763 764 1 764 765 1 765 766 1 766 767 1
		 767 768 1 768 769 1;
	setAttr -s 438 -ch 1806 ".fc[0:437]" -type "polyFaces" 
		f 5 22 46 50 5 3
		mu 0 5 16 30 33 5 4
		f 4 -39 47 39 4
		mu 0 4 18 31 32 3
		f 4 26 44 36 16
		mu 0 4 22 28 29 21
		f 4 -37 45 -23 17
		mu 0 4 21 29 30 16
		f 5 27 43 -27 25 13
		mu 0 5 14 27 28 22 12
		f 4 40 32 28 -32
		mu 0 4 24 25 23 8
		f 4 30 42 -28 14
		mu 0 4 15 26 27 14
		f 5 -33 41 -31 15 12
		mu 0 5 23 25 26 15 13
		f 4 -10 29 -41 -8
		mu 0 4 7 10 25 24
		f 4 -42 -30 10 -34
		mu 0 4 26 25 10 11
		f 4 -43 33 11 -35
		mu 0 4 27 26 11 9
		f 4 -44 34 -9 -36
		mu 0 4 28 27 9 6
		f 4 -45 35 6 24
		mu 0 4 29 28 6 20
		f 4 -46 -25 23 -38
		mu 0 4 30 29 20 19
		f 5 49 -47 37 21 -3
		mu 0 5 2 33 30 19 1
		f 4 -48 -21 -2 0
		mu 0 4 32 31 17 0
		f 4 -49 -50 -19 20
		mu 0 4 31 33 2 17
		f 4 -51 48 38 19
		mu 0 4 5 33 31 18
		f 4 62 81 75 -61
		mu 0 4 34 35 36 37
		f 4 -76 82 76 51
		mu 0 4 37 36 38 39
		f 4 64 80 -63 -56
		mu 0 4 40 41 35 34
		f 4 66 79 -65 56
		mu 0 4 42 43 41 40
		f 4 69 78 -67 65
		mu 0 4 44 45 43 42
		f 4 77 -70 67 -71
		mu 0 4 46 45 44 47
		f 4 58 -72 -78 -58
		mu 0 4 48 49 45 46
		f 4 -79 71 68 -73
		mu 0 4 43 45 49 50
		f 4 -80 72 -64 -74
		mu 0 4 41 43 50 51
		f 4 -81 73 -62 -75
		mu 0 4 35 41 51 52
		f 4 -82 74 -54 59
		mu 0 4 36 35 52 53
		f 4 -83 -60 -55 52
		mu 0 4 38 36 53 54
		f 4 94 113 107 -93
		mu 0 4 55 56 57 58
		f 4 -108 114 108 83
		mu 0 4 58 57 59 60
		f 4 96 112 -95 -88
		mu 0 4 61 62 56 55
		f 4 98 111 -97 88
		mu 0 4 63 64 62 61
		f 4 101 110 -99 97
		mu 0 4 65 66 64 63
		f 4 109 -102 99 -103
		mu 0 4 67 66 65 68
		f 4 90 -104 -110 -90
		mu 0 4 69 70 66 67
		f 4 -111 103 100 -105
		mu 0 4 64 66 70 71
		f 4 -112 104 -96 -106
		mu 0 4 62 64 71 72
		f 4 -113 105 -94 -107
		mu 0 4 56 62 72 73
		f 4 -114 106 -86 91
		mu 0 4 57 56 73 74
		f 4 -115 -92 -87 84
		mu 0 4 59 57 74 75
		f 4 126 145 139 -125
		mu 0 4 76 77 78 79
		f 4 -140 146 140 115
		mu 0 4 79 78 80 81
		f 4 128 144 -127 -120
		mu 0 4 82 83 77 76
		f 4 130 143 -129 120
		mu 0 4 84 85 83 82
		f 4 133 142 -131 129
		mu 0 4 86 87 85 84
		f 4 141 -134 131 -135
		mu 0 4 88 87 86 89
		f 4 122 -136 -142 -122
		mu 0 4 90 91 87 88
		f 4 -143 135 132 -137
		mu 0 4 85 87 91 92
		f 4 -144 136 -128 -138
		mu 0 4 83 85 92 93
		f 4 -145 137 -126 -139
		mu 0 4 77 83 93 94
		f 4 -146 138 -118 123
		mu 0 4 78 77 94 95
		f 4 -147 -124 -119 116
		mu 0 4 80 78 95 96
		f 4 158 177 171 -157
		mu 0 4 97 98 99 100
		f 4 -172 178 172 147
		mu 0 4 100 99 101 102
		f 4 160 176 -159 -152
		mu 0 4 103 104 98 97
		f 4 162 175 -161 152
		mu 0 4 105 106 104 103
		f 4 165 174 -163 161
		mu 0 4 107 108 106 105
		f 4 173 -166 163 -167
		mu 0 4 109 108 107 110
		f 4 154 -168 -174 -154
		mu 0 4 111 112 108 109
		f 4 -175 167 164 -169
		mu 0 4 106 108 112 113
		f 4 -176 168 -160 -170
		mu 0 4 104 106 113 114
		f 4 -177 169 -158 -171
		mu 0 4 98 104 114 115
		f 4 -178 170 -150 155
		mu 0 4 99 98 115 116
		f 4 -179 -156 -151 148
		mu 0 4 101 99 116 117
		f 5 201 225 229 184 182
		mu 0 5 118 119 120 121 122
		f 4 -218 226 218 183
		mu 0 4 123 124 125 126
		f 4 205 223 215 195
		mu 0 4 127 128 129 130
		f 4 -216 224 -202 196
		mu 0 4 130 129 119 118
		f 5 206 222 -206 204 192
		mu 0 5 131 132 128 127 133
		f 4 219 211 207 -211
		mu 0 4 134 135 136 137
		f 4 209 221 -207 193
		mu 0 4 138 139 132 131
		f 5 -212 220 -210 194 191
		mu 0 5 136 135 139 138 140
		f 4 -189 208 -220 -187
		mu 0 4 141 142 135 134
		f 4 -221 -209 189 -213
		mu 0 4 139 135 142 143
		f 4 -222 212 190 -214
		mu 0 4 132 139 143 144
		f 4 -223 213 -188 -215
		mu 0 4 128 132 144 145
		f 4 -224 214 185 203
		mu 0 4 129 128 145 146
		f 4 -225 -204 202 -217
		mu 0 4 119 129 146 147
		f 5 228 -226 216 200 -182
		mu 0 5 148 120 119 147 149
		f 4 -227 -200 -181 179
		mu 0 4 125 124 150 151
		f 4 -228 -229 -198 199
		mu 0 4 124 120 148 150
		f 4 -230 227 217 198
		mu 0 4 121 120 124 123
		f 4 242 247 245 -241
		mu 0 4 152 153 154 155
		f 4 -234 246 -243 -235
		mu 0 4 156 157 153 152
		f 5 -246 248 237 235 239
		mu 0 5 155 154 158 159 160
		f 4 -247 -233 -242 -245
		mu 0 4 153 157 161 162
		f 4 -248 244 -239 243
		mu 0 4 154 153 162 163
		f 5 -249 -244 -232 230 236
		mu 0 5 158 154 163 164 165
		f 4 261 266 264 -260
		mu 0 4 166 167 168 169
		f 4 -253 265 -262 -254
		mu 0 4 170 171 167 166
		f 5 -265 267 256 254 258
		mu 0 5 169 168 172 173 174
		f 4 -266 -252 -261 -264
		mu 0 4 167 171 175 176
		f 4 -267 263 -258 262
		mu 0 4 168 167 176 177
		f 5 -268 -263 -251 249 255
		mu 0 5 172 168 177 178 179
		f 5 290 314 318 273 271
		mu 0 5 180 181 182 183 184
		f 4 -307 315 307 272
		mu 0 4 185 186 187 188
		f 4 294 312 304 284
		mu 0 4 189 190 191 192
		f 4 -305 313 -291 285
		mu 0 4 192 191 181 180
		f 5 295 311 -295 293 281
		mu 0 5 193 194 190 189 195
		f 4 308 300 296 -300
		mu 0 4 196 197 198 199
		f 4 298 310 -296 282
		mu 0 4 200 201 194 193
		f 5 -301 309 -299 283 280
		mu 0 5 198 197 201 200 202
		f 4 -278 297 -309 -276
		mu 0 4 203 204 197 196
		f 4 -310 -298 278 -302
		mu 0 4 201 197 204 205
		f 4 -311 301 279 -303
		mu 0 4 194 201 205 206
		f 4 -312 302 -277 -304
		mu 0 4 190 194 206 207
		f 4 -313 303 274 292
		mu 0 4 191 190 207 208
		f 4 -314 -293 291 -306
		mu 0 4 181 191 208 209
		f 5 317 -315 305 289 -271
		mu 0 5 210 182 181 209 211
		f 4 -316 -289 -270 268
		mu 0 4 187 186 212 213
		f 4 -317 -318 -287 288
		mu 0 4 186 182 210 212
		f 4 -319 316 306 287
		mu 0 4 183 182 186 185
		f 4 330 349 343 -329
		mu 0 4 214 215 216 217
		f 4 -344 350 344 319
		mu 0 4 217 216 218 219
		f 4 332 348 -331 -324
		mu 0 4 220 221 215 214
		f 4 334 347 -333 324
		mu 0 4 222 223 221 220
		f 4 337 346 -335 333
		mu 0 4 224 225 223 222
		f 4 345 -338 335 -339
		mu 0 4 226 225 224 227
		f 4 326 -340 -346 -326
		mu 0 4 228 229 225 226
		f 4 -347 339 336 -341
		mu 0 4 223 225 229 230
		f 4 -348 340 -332 -342
		mu 0 4 221 223 230 231
		f 4 -349 341 -330 -343
		mu 0 4 215 221 231 232
		f 4 -350 342 -322 327
		mu 0 4 216 215 232 233
		f 4 -351 -328 -323 320
		mu 0 4 218 216 233 234
		f 4 362 381 375 -361
		mu 0 4 235 236 237 238
		f 4 -376 382 376 351
		mu 0 4 238 237 239 240
		f 4 364 380 -363 -356
		mu 0 4 241 242 236 235
		f 4 366 379 -365 356
		mu 0 4 243 244 242 241
		f 4 369 378 -367 365
		mu 0 4 245 246 244 243
		f 4 377 -370 367 -371
		mu 0 4 247 246 245 248
		f 4 358 -372 -378 -358
		mu 0 4 249 250 246 247
		f 4 -379 371 368 -373
		mu 0 4 244 246 250 251
		f 4 -380 372 -364 -374
		mu 0 4 242 244 251 252
		f 4 -381 373 -362 -375
		mu 0 4 236 242 252 253
		f 4 -382 374 -354 359
		mu 0 4 237 236 253 254
		f 4 -383 -360 -355 352
		mu 0 4 239 237 254 255
		f 4 394 413 407 -393
		mu 0 4 256 257 258 259
		f 4 -408 414 408 383
		mu 0 4 259 258 260 261
		f 4 396 412 -395 -388
		mu 0 4 262 263 257 256
		f 4 398 411 -397 388
		mu 0 4 264 265 263 262
		f 4 401 410 -399 397
		mu 0 4 266 267 265 264
		f 4 409 -402 399 -403
		mu 0 4 268 267 266 269
		f 4 390 -404 -410 -390
		mu 0 4 270 271 267 268
		f 4 -411 403 400 -405
		mu 0 4 265 267 271 272
		f 4 -412 404 -396 -406
		mu 0 4 263 265 272 273
		f 4 -413 405 -394 -407
		mu 0 4 257 263 273 274
		f 4 -414 406 -386 391
		mu 0 4 258 257 274 275
		f 4 -415 -392 -387 384
		mu 0 4 260 258 275 276
		f 4 415 496 -424 -496
		mu 0 4 277 278 279 280
		f 4 416 497 -425 -497
		mu 0 4 278 281 282 279
		f 4 417 498 -426 -498
		mu 0 4 281 283 284 282
		f 4 418 499 -427 -499
		mu 0 4 283 285 286 284
		f 4 419 500 -428 -500
		mu 0 4 287 288 289 290
		f 4 420 501 -429 -501
		mu 0 4 288 291 292 289
		f 4 421 502 -430 -502
		mu 0 4 291 293 294 292
		f 4 422 495 -431 -503
		mu 0 4 293 277 280 294
		f 4 423 504 -432 -504
		mu 0 4 280 279 295 296
		f 4 424 505 -433 -505
		mu 0 4 279 282 297 295
		f 4 425 506 -434 -506
		mu 0 4 282 284 298 297
		f 4 426 507 -435 -507
		mu 0 4 284 286 299 298
		f 4 427 508 -436 -508
		mu 0 4 290 289 300 301
		f 4 428 509 -437 -509
		mu 0 4 289 292 302 300
		f 4 429 510 -438 -510
		mu 0 4 292 294 303 302
		f 4 430 503 -439 -511
		mu 0 4 294 280 296 303
		f 4 431 512 -440 -512
		mu 0 4 296 295 304 305
		f 4 432 513 -441 -513
		mu 0 4 295 297 306 304
		f 4 433 514 -442 -514
		mu 0 4 297 298 307 306
		f 4 434 515 -443 -515
		mu 0 4 298 299 308 307
		f 4 435 516 -444 -516
		mu 0 4 301 300 309 310
		f 4 436 517 -445 -517
		mu 0 4 300 302 311 309
		f 4 437 518 -446 -518
		mu 0 4 302 303 312 311
		f 4 438 511 -447 -519
		mu 0 4 303 296 305 312
		f 4 439 520 -448 -520
		mu 0 4 305 304 313 314
		f 4 440 521 -449 -521
		mu 0 4 304 306 315 313
		f 4 441 522 -450 -522
		mu 0 4 306 307 316 315
		f 4 442 523 -451 -523
		mu 0 4 307 308 317 316
		f 4 443 524 -452 -524
		mu 0 4 310 309 318 319
		f 4 444 525 -453 -525
		mu 0 4 309 311 320 318
		f 4 445 526 -454 -526
		mu 0 4 311 312 321 320
		f 4 446 519 -455 -527
		mu 0 4 312 305 314 321
		f 4 447 528 -456 -528
		mu 0 4 314 313 322 323
		f 4 448 529 -457 -529
		mu 0 4 313 315 324 322
		f 4 449 530 -458 -530
		mu 0 4 315 316 325 324
		f 4 450 531 -459 -531
		mu 0 4 316 317 326 325
		f 4 451 532 -460 -532
		mu 0 4 319 318 327 328
		f 4 452 533 -461 -533
		mu 0 4 318 320 329 327
		f 4 453 534 -462 -534
		mu 0 4 320 321 330 329
		f 4 454 527 -463 -535
		mu 0 4 321 314 323 330
		f 4 455 536 -464 -536
		mu 0 4 323 322 331 332
		f 4 456 537 -465 -537
		mu 0 4 322 324 333 331
		f 4 457 538 -466 -538
		mu 0 4 324 325 334 333
		f 4 458 539 -467 -539
		mu 0 4 325 326 335 334
		f 4 459 540 -468 -540
		mu 0 4 328 327 336 337
		f 4 460 541 -469 -541
		mu 0 4 327 329 338 336
		f 4 461 542 -470 -542
		mu 0 4 329 330 339 338
		f 4 462 535 -471 -543
		mu 0 4 330 323 332 339
		f 4 463 544 -472 -544
		mu 0 4 332 331 340 341
		f 4 464 545 -473 -545
		mu 0 4 331 333 342 340
		f 4 465 546 -474 -546
		mu 0 4 333 334 343 342
		f 4 466 547 -475 -547
		mu 0 4 334 335 344 343
		f 4 467 548 -476 -548
		mu 0 4 337 336 345 346
		f 4 468 549 -477 -549
		mu 0 4 336 338 347 345
		f 4 469 550 -478 -550
		mu 0 4 338 339 348 347
		f 4 470 543 -479 -551
		mu 0 4 339 332 341 348
		f 4 471 552 -480 -552
		mu 0 4 341 340 349 350
		f 4 472 553 -481 -553
		mu 0 4 340 342 351 349
		f 4 473 554 -482 -554
		mu 0 4 342 343 352 351
		f 4 474 555 -483 -555
		mu 0 4 343 344 353 352
		f 4 475 556 -484 -556
		mu 0 4 346 345 354 355
		f 4 476 557 -485 -557
		mu 0 4 345 347 356 354
		f 4 477 558 -486 -558
		mu 0 4 347 348 357 356
		f 4 478 551 -487 -559
		mu 0 4 348 341 350 357
		f 4 479 560 -488 -560
		mu 0 4 350 349 358 359
		f 4 480 561 -489 -561
		mu 0 4 349 351 360 358
		f 4 481 562 -490 -562
		mu 0 4 351 352 361 362
		f 4 482 563 -491 -563
		mu 0 4 352 353 363 361
		f 4 483 564 -492 -564
		mu 0 4 355 354 364 365
		f 4 484 565 -493 -565
		mu 0 4 354 356 366 364
		f 4 485 566 -494 -566
		mu 0 4 356 357 367 368
		f 4 486 559 -495 -567
		mu 0 4 357 350 369 367
		f 4 579 584 582 -578
		mu 0 4 370 371 372 373
		f 4 -571 583 -580 -572
		mu 0 4 374 375 371 370
		f 5 -583 585 574 572 576
		mu 0 5 373 372 376 377 378
		f 4 -584 -570 -579 -582
		mu 0 4 371 375 379 380
		f 4 -585 581 -576 580
		mu 0 4 372 371 380 381
		f 5 -586 -581 -569 567 573
		mu 0 5 376 372 381 382 383
		f 5 608 632 636 591 589
		mu 0 5 384 385 386 387 388
		f 4 -625 633 625 590
		mu 0 4 389 390 391 392
		f 4 612 630 622 602
		mu 0 4 393 394 395 396
		f 4 -623 631 -609 603
		mu 0 4 396 395 385 384
		f 5 613 629 -613 611 599
		mu 0 5 397 398 394 393 399
		f 4 626 618 614 -618
		mu 0 4 400 401 402 403
		f 4 616 628 -614 600
		mu 0 4 404 405 398 397
		f 5 -619 627 -617 601 598
		mu 0 5 402 401 405 404 406
		f 4 -596 615 -627 -594
		mu 0 4 407 408 401 400
		f 4 -628 -616 596 -620
		mu 0 4 405 401 408 409
		f 4 -629 619 597 -621
		mu 0 4 398 405 409 410
		f 4 -630 620 -595 -622
		mu 0 4 394 398 410 411
		f 4 -631 621 592 610
		mu 0 4 395 394 411 412
		f 4 -632 -611 609 -624
		mu 0 4 385 395 412 413
		f 5 635 -633 623 607 -589
		mu 0 5 414 386 385 413 415
		f 4 -634 -607 -588 586
		mu 0 4 391 390 416 417
		f 4 -635 -636 -605 606
		mu 0 4 390 386 414 416
		f 4 -637 634 624 605
		mu 0 4 387 386 390 389
		f 5 659 683 687 642 640
		mu 0 5 418 419 420 421 422
		f 4 -676 684 676 641
		mu 0 4 423 424 425 426
		f 4 663 681 673 653
		mu 0 4 427 428 429 430
		f 4 -674 682 -660 654
		mu 0 4 430 429 419 418
		f 5 664 680 -664 662 650
		mu 0 5 431 432 428 427 433
		f 4 677 669 665 -669
		mu 0 4 434 435 436 437
		f 4 667 679 -665 651
		mu 0 4 438 439 432 431
		f 5 -670 678 -668 652 649
		mu 0 5 436 435 439 438 440
		f 4 -647 666 -678 -645
		mu 0 4 441 442 435 434
		f 4 -679 -667 647 -671
		mu 0 4 439 435 442 443
		f 4 -680 670 648 -672
		mu 0 4 432 439 443 444
		f 4 -681 671 -646 -673
		mu 0 4 428 432 444 445
		f 4 -682 672 643 661
		mu 0 4 429 428 445 446
		f 4 -683 -662 660 -675
		mu 0 4 419 429 446 447
		f 5 686 -684 674 658 -640
		mu 0 5 448 420 419 447 449
		f 4 -685 -658 -639 637
		mu 0 4 425 424 450 451
		f 4 -686 -687 -656 657
		mu 0 4 424 420 448 450
		f 4 -688 685 675 656
		mu 0 4 421 420 424 423
		f 4 699 718 712 -698
		mu 0 4 452 453 454 455
		f 4 -713 719 713 688
		mu 0 4 455 454 456 457
		f 4 701 717 -700 -693
		mu 0 4 458 459 453 452
		f 4 703 716 -702 693
		mu 0 4 460 461 459 458
		f 4 706 715 -704 702
		mu 0 4 462 463 461 460
		f 4 714 -707 704 -708
		mu 0 4 464 463 462 465
		f 4 695 -709 -715 -695
		mu 0 4 466 467 463 464
		f 4 -716 708 705 -710
		mu 0 4 461 463 467 468
		f 4 -717 709 -701 -711
		mu 0 4 459 461 468 469
		f 4 -718 710 -699 -712
		mu 0 4 453 459 469 470
		f 4 -719 711 -691 696
		mu 0 4 454 453 470 471
		f 4 -720 -697 -692 689
		mu 0 4 456 454 471 472
		f 4 731 750 744 -730
		mu 0 4 473 474 475 476
		f 4 -745 751 745 720
		mu 0 4 476 475 477 478
		f 4 733 749 -732 -725
		mu 0 4 479 480 474 473
		f 4 735 748 -734 725
		mu 0 4 481 482 480 479
		f 4 738 747 -736 734
		mu 0 4 483 484 482 481
		f 4 746 -739 736 -740
		mu 0 4 485 484 483 486
		f 4 727 -741 -747 -727
		mu 0 4 487 488 484 485
		f 4 -748 740 737 -742
		mu 0 4 482 484 488 489
		f 4 -749 741 -733 -743
		mu 0 4 480 482 489 490
		f 4 -750 742 -731 -744
		mu 0 4 474 480 490 491
		f 4 -751 743 -723 728
		mu 0 4 475 474 491 492
		f 4 -752 -729 -724 721
		mu 0 4 477 475 492 493
		f 5 774 798 802 757 755
		mu 0 5 494 495 496 497 498
		f 4 -791 799 791 756
		mu 0 4 499 500 501 502
		f 4 778 796 788 768
		mu 0 4 503 504 505 506
		f 4 -789 797 -775 769
		mu 0 4 506 505 495 494
		f 5 779 795 -779 777 765
		mu 0 5 507 508 504 503 509
		f 4 792 784 780 -784
		mu 0 4 510 511 512 513
		f 4 782 794 -780 766
		mu 0 4 514 515 508 507
		f 5 -785 793 -783 767 764
		mu 0 5 512 511 515 514 516
		f 4 -762 781 -793 -760
		mu 0 4 517 518 511 510
		f 4 -794 -782 762 -786
		mu 0 4 515 511 518 519
		f 4 -795 785 763 -787
		mu 0 4 508 515 519 520
		f 4 -796 786 -761 -788
		mu 0 4 504 508 520 521
		f 4 -797 787 758 776
		mu 0 4 505 504 521 522
		f 4 -798 -777 775 -790
		mu 0 4 495 505 522 523
		f 5 801 -799 789 773 -755
		mu 0 5 524 496 495 523 525
		f 4 -800 -773 -754 752
		mu 0 4 501 500 526 527
		f 4 -801 -802 -771 772
		mu 0 4 500 496 524 526
		f 4 -803 800 790 771
		mu 0 4 497 496 500 499
		f 5 825 849 853 808 806
		mu 0 5 528 529 530 531 532
		f 4 -842 850 842 807
		mu 0 4 533 534 535 536
		f 4 829 847 839 819
		mu 0 4 537 538 539 540
		f 4 -840 848 -826 820
		mu 0 4 540 539 529 528
		f 5 830 846 -830 828 816
		mu 0 5 541 542 538 537 543
		f 4 843 835 831 -835
		mu 0 4 544 545 546 547
		f 4 833 845 -831 817
		mu 0 4 548 549 542 541
		f 5 -836 844 -834 818 815
		mu 0 5 546 545 549 548 550
		f 4 -813 832 -844 -811
		mu 0 4 551 552 545 544
		f 4 -845 -833 813 -837
		mu 0 4 549 545 552 553
		f 4 -846 836 814 -838
		mu 0 4 542 549 553 554
		f 4 -847 837 -812 -839
		mu 0 4 538 542 554 555
		f 4 -848 838 809 827
		mu 0 4 539 538 555 556
		f 4 -849 -828 826 -841
		mu 0 4 529 539 556 557
		f 5 852 -850 840 824 -806
		mu 0 5 558 530 529 557 559
		f 4 -851 -824 -805 803
		mu 0 4 535 534 560 561
		f 4 -852 -853 -822 823
		mu 0 4 534 530 558 560
		f 4 -854 851 841 822
		mu 0 4 531 530 534 533
		f 5 876 900 904 859 857
		mu 0 5 562 563 564 565 566
		f 4 -893 901 893 858
		mu 0 4 567 568 569 570
		f 4 880 898 890 870
		mu 0 4 571 572 573 574
		f 4 -891 899 -877 871
		mu 0 4 574 573 563 562
		f 5 881 897 -881 879 867
		mu 0 5 575 576 572 571 577
		f 4 894 886 882 -886
		mu 0 4 578 579 580 581
		f 4 884 896 -882 868
		mu 0 4 582 583 576 575
		f 5 -887 895 -885 869 866
		mu 0 5 580 579 583 582 584
		f 4 -864 883 -895 -862
		mu 0 4 585 586 579 578
		f 4 -896 -884 864 -888
		mu 0 4 583 579 586 587
		f 4 -897 887 865 -889
		mu 0 4 576 583 587 588
		f 4 -898 888 -863 -890
		mu 0 4 572 576 588 589
		f 4 -899 889 860 878
		mu 0 4 573 572 589 590
		f 4 -900 -879 877 -892
		mu 0 4 563 573 590 591
		f 5 903 -901 891 875 -857
		mu 0 5 592 564 563 591 593
		f 4 -902 -875 -856 854
		mu 0 4 569 568 594 595
		f 4 -903 -904 -873 874
		mu 0 4 568 564 592 594
		f 4 -905 902 892 873
		mu 0 4 565 564 568 567
		f 4 916 935 929 -915
		mu 0 4 596 597 598 599
		f 4 -930 936 930 905
		mu 0 4 599 598 600 601
		f 4 918 934 -917 -910
		mu 0 4 602 603 597 596
		f 4 920 933 -919 910
		mu 0 4 604 605 603 602
		f 4 923 932 -921 919
		mu 0 4 606 607 605 604
		f 4 931 -924 921 -925
		mu 0 4 608 607 606 609
		f 4 912 -926 -932 -912
		mu 0 4 610 611 607 608
		f 4 -933 925 922 -927
		mu 0 4 605 607 611 612
		f 4 -934 926 -918 -928
		mu 0 4 603 605 612 613
		f 4 -935 927 -916 -929
		mu 0 4 597 603 613 614
		f 4 -936 928 -908 913
		mu 0 4 598 597 614 615
		f 4 -937 -914 -909 906
		mu 0 4 600 598 615 616
		f 4 949 954 952 -948
		mu 0 4 617 618 619 620
		f 4 -941 953 -950 -942
		mu 0 4 621 622 618 617
		f 5 -953 955 944 942 946
		mu 0 5 620 619 623 624 625
		f 4 -954 -940 -949 -952
		mu 0 4 618 622 626 627
		f 4 -955 951 -946 950
		mu 0 4 619 618 627 628
		f 5 -956 -951 -939 937 943
		mu 0 5 623 619 628 629 630
		f 4 968 973 971 -967
		mu 0 4 631 632 633 634
		f 4 -960 972 -969 -961
		mu 0 4 635 636 632 631
		f 5 -972 974 963 961 965
		mu 0 5 634 633 637 638 639
		f 4 -973 -959 -968 -971
		mu 0 4 632 636 640 641
		f 4 -974 970 -965 969
		mu 0 4 633 632 641 642
		f 5 -975 -970 -958 956 962
		mu 0 5 637 633 642 643 644
		f 4 987 992 990 -986
		mu 0 4 645 646 647 648
		f 4 -979 991 -988 -980
		mu 0 4 649 650 646 645
		f 5 -991 993 982 980 984
		mu 0 5 648 647 651 652 653
		f 4 -992 -978 -987 -990
		mu 0 4 646 650 654 655
		f 4 -993 989 -984 988
		mu 0 4 647 646 655 656
		f 5 -994 -989 -977 975 981
		mu 0 5 651 647 656 657 658
		f 4 1006 1011 1009 -1005
		mu 0 4 659 660 661 662
		f 4 -998 1010 -1007 -999
		mu 0 4 663 664 660 659
		f 5 -1010 1012 1001 999 1003
		mu 0 5 662 661 665 666 667
		f 4 -1011 -997 -1006 -1009
		mu 0 4 660 664 668 669
		f 4 -1012 1008 -1003 1007
		mu 0 4 661 660 669 670
		f 5 -1013 -1008 -996 994 1000
		mu 0 5 665 661 670 671 672
		f 5 1035 1059 1063 1018 1016
		mu 0 5 673 674 675 676 677
		f 4 -1052 1060 1052 1017
		mu 0 4 678 679 680 681
		f 4 1039 1057 1049 1029
		mu 0 4 682 683 684 685
		f 4 -1050 1058 -1036 1030
		mu 0 4 685 684 674 673
		f 5 1040 1056 -1040 1038 1026
		mu 0 5 686 687 683 682 688
		f 4 1053 1045 1041 -1045
		mu 0 4 689 690 691 692
		f 4 1043 1055 -1041 1027
		mu 0 4 693 694 687 686
		f 5 -1046 1054 -1044 1028 1025
		mu 0 5 691 690 694 693 695
		f 4 -1023 1042 -1054 -1021
		mu 0 4 696 697 690 689
		f 4 -1055 -1043 1023 -1047
		mu 0 4 694 690 697 698
		f 4 -1056 1046 1024 -1048
		mu 0 4 687 694 698 699
		f 4 -1057 1047 -1022 -1049
		mu 0 4 683 687 699 700
		f 4 -1058 1048 1019 1037
		mu 0 4 684 683 700 701
		f 4 -1059 -1038 1036 -1051
		mu 0 4 674 684 701 702
		f 5 1062 -1060 1050 1034 -1016
		mu 0 5 703 675 674 702 704
		f 4 -1061 -1034 -1015 1013
		mu 0 4 680 679 705 706
		f 4 -1062 -1063 -1032 1033
		mu 0 4 679 675 703 705
		f 4 -1064 1061 1051 1032
		mu 0 4 676 675 679 678
		f 5 1086 1110 1114 1069 1067
		mu 0 5 707 708 709 710 711
		f 4 -1103 1111 1103 1068
		mu 0 4 712 713 714 715
		f 4 1090 1108 1100 1080
		mu 0 4 716 717 718 719
		f 4 -1101 1109 -1087 1081
		mu 0 4 719 718 708 707
		f 5 1091 1107 -1091 1089 1077
		mu 0 5 720 721 717 716 722
		f 4 1104 1096 1092 -1096
		mu 0 4 723 724 725 726
		f 4 1094 1106 -1092 1078
		mu 0 4 727 728 721 720
		f 5 -1097 1105 -1095 1079 1076
		mu 0 5 725 724 728 727 729
		f 4 -1074 1093 -1105 -1072
		mu 0 4 730 731 724 723
		f 4 -1106 -1094 1074 -1098
		mu 0 4 728 724 731 732
		f 4 -1107 1097 1075 -1099
		mu 0 4 721 728 732 733
		f 4 -1108 1098 -1073 -1100
		mu 0 4 717 721 733 734
		f 4 -1109 1099 1070 1088
		mu 0 4 718 717 734 735
		f 4 -1110 -1089 1087 -1102
		mu 0 4 708 718 735 736
		f 5 1113 -1111 1101 1085 -1067
		mu 0 5 737 709 708 736 738
		f 4 -1112 -1085 -1066 1064
		mu 0 4 714 713 739 740
		f 4 -1113 -1114 -1083 1084
		mu 0 4 713 709 737 739
		f 4 -1115 1112 1102 1083
		mu 0 4 710 709 713 712
		f 4 1126 1145 1139 -1125
		mu 0 4 741 742 743 744
		f 4 -1140 1146 1140 1115
		mu 0 4 744 743 745 746
		f 4 1128 1144 -1127 -1120
		mu 0 4 747 748 742 741
		f 4 1130 1143 -1129 1120
		mu 0 4 749 750 748 747
		f 4 1133 1142 -1131 1129
		mu 0 4 751 752 750 749
		f 4 1141 -1134 1131 -1135
		mu 0 4 753 752 751 754
		f 4 1122 -1136 -1142 -1122
		mu 0 4 755 756 752 753
		f 4 -1143 1135 1132 -1137
		mu 0 4 750 752 756 757
		f 4 -1144 1136 -1128 -1138
		mu 0 4 748 750 757 758
		f 4 -1145 1137 -1126 -1139
		mu 0 4 742 748 758 759
		f 4 -1146 1138 -1118 1123
		mu 0 4 743 742 759 760
		f 4 -1147 -1124 -1119 1116
		mu 0 4 745 743 760 761
		f 4 1158 1177 1171 -1157
		mu 0 4 762 763 764 765
		f 4 -1172 1178 1172 1147
		mu 0 4 765 764 766 767
		f 4 1160 1176 -1159 -1152
		mu 0 4 768 769 763 762
		f 4 1162 1175 -1161 1152
		mu 0 4 770 771 769 768
		f 4 1165 1174 -1163 1161
		mu 0 4 772 773 771 770
		f 4 1173 -1166 1163 -1167
		mu 0 4 774 773 772 775
		f 4 1154 -1168 -1174 -1154
		mu 0 4 776 777 773 774
		f 4 -1175 1167 1164 -1169
		mu 0 4 771 773 777 778
		f 4 -1176 1168 -1160 -1170
		mu 0 4 769 771 778 779
		f 4 -1177 1169 -1158 -1171
		mu 0 4 763 769 779 780
		f 4 -1178 1170 -1150 1155
		mu 0 4 764 763 780 781
		f 4 -1179 -1156 -1151 1148
		mu 0 4 766 764 781 782;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode lightLinker -s -n "lightLinker1";
	rename -uid "1896775C-402C-382E-76C2-B985DB9E0527";
	setAttr -s 4 ".lnk";
	setAttr -s 4 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "6A972A31-4FA4-A1BC-7813-26A1B2C121AC";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "09BDD795-435F-862F-AFD5-E6B1AF2AB280";
createNode displayLayerManager -n "layerManager";
	rename -uid "348B9B9C-4221-AEFB-C7CC-BABCC8156ADA";
createNode displayLayer -n "defaultLayer";
	rename -uid "45D86949-4101-3F2D-C3A0-C8B00BB0C9F2";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "50164726-4A3B-2E41-54E4-E5BCAC995264";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "2BAB7981-4BD2-8476-69FE-50B8CB25C14A";
	setAttr ".g" yes;
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
createNode script -n "uiConfigurationScriptNode";
	rename -uid "52EA78D6-4078-5B7F-C2A9-19B5A2DD8754";
	setAttr ".b" -type "string" (
		"// Maya Mel UI Configuration File.\n//\n//  This script is machine generated.  Edit at your own risk.\n//\n//\n\nglobal string $gMainPane;\nif (`paneLayout -exists $gMainPane`) {\n\n\tglobal int $gUseScenePanelConfig;\n\tint    $useSceneConfig = $gUseScenePanelConfig;\n\tint    $nodeEditorPanelVisible = stringArrayContains(\"nodeEditorPanel1\", `getPanel -vis`);\n\tint    $nodeEditorWorkspaceControlOpen = (`workspaceControl -exists nodeEditorPanel1Window` && `workspaceControl -q -visible nodeEditorPanel1Window`);\n\tint    $menusOkayInPanels = `optionVar -q allowMenusInPanels`;\n\tint    $nVisPanes = `paneLayout -q -nvp $gMainPane`;\n\tint    $nPanes = 0;\n\tstring $editorName;\n\tstring $panelName;\n\tstring $itemFilterName;\n\tstring $panelConfig;\n\n\t//\n\t//  get current state of the UI\n\t//\n\tsceneUIReplacement -update $gMainPane;\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Top View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Top View\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|top\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n"
		+ "            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n"
		+ "            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Side View\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Side View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|side\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n"
		+ "            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n"
		+ "            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Front View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Front View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|front\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n"
		+ "            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n"
		+ "            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n"
		+ "            -width 1\n            -height 1\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"modelPanel\" (localizedPanelLabel(\"Persp View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tmodelPanel -edit -l (localizedPanelLabel(\"Persp View\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        modelEditor -e \n            -camera \"|persp\" \n            -useInteractiveMode 0\n            -displayLights \"default\" \n            -displayAppearance \"smoothShaded\" \n            -activeOnly 0\n            -ignorePanZoom 0\n            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n"
		+ "            -activeComponentsXray 0\n            -displayTextures 1\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 16384\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n            -textureCompression 0\n            -transparencyAlgorithm \"frontAndBackCull\" \n            -transpInShadows 0\n            -cullingOverride \"none\" \n            -lowQualityLighting 0\n            -maximumNumHardwareLights 1\n            -occlusionCulling 0\n            -shadingModel 0\n"
		+ "            -useBaseRenderer 0\n            -useReducedRenderer 0\n            -smallObjectCulling 0\n            -smallObjectThreshold -1 \n            -interactiveDisableShadows 0\n            -interactiveBackFaceCull 0\n            -sortTransparent 1\n            -controllers 1\n            -nurbsCurves 1\n            -nurbsSurfaces 1\n            -polymeshes 1\n            -subdivSurfaces 1\n            -planes 1\n            -lights 1\n            -cameras 1\n            -controlVertices 1\n            -hulls 1\n            -grid 1\n            -imagePlane 1\n            -joints 1\n            -ikHandles 1\n            -deformers 1\n            -dynamics 1\n            -particleInstancers 1\n            -fluids 1\n            -hairSystems 1\n            -follicles 1\n            -nCloths 1\n            -nParticles 1\n            -nRigids 1\n            -dynamicConstraints 1\n            -locators 1\n            -manipulators 1\n            -pluginShapes 1\n            -dimensions 1\n            -handles 1\n            -pivots 1\n            -textures 1\n"
		+ "            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1040\n            -height 811\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n"
		+ "            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -isSet 0\n            -isSetMember 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n"
		+ "            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -selectCommand \"print(\\\"\\\")\" \n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            -renderFilterIndex 0\n            -selectionOrder \"chronological\" \n            -expandAttribute 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"Outliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"Outliner\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 0\n            -showReferenceMembers 0\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n            -organizeByLayer 1\n            -organizeByClip 1\n            -showAnimLayerWeight 1\n            -autoExpandLayers 1\n            -autoExpand 0\n            -showDagOnly 1\n            -showAssets 1\n            -showContainedOnly 1\n            -showPublishedAsConnected 0\n            -showParentContainers 0\n            -showContainerContents 1\n            -ignoreDagHierarchy 0\n            -expandConnections 0\n            -showUpstreamCurves 1\n            -showUnitlessCurves 1\n            -showCompounds 1\n            -showLeafs 1\n            -showNumericAttrsOnly 0\n            -highlightActive 1\n            -autoSelectNewObjects 0\n            -doNotSelectNewObjects 0\n            -dropIsParent 1\n"
		+ "            -transmitFilters 0\n            -setFilter \"defaultSetFilter\" \n            -showSetMembers 1\n            -allowMultiSelection 1\n            -alwaysToggleSelect 0\n            -directSelect 0\n            -displayMode \"DAG\" \n            -expandObjects 0\n            -setsIgnoreFilters 1\n            -containersIgnoreFilters 0\n            -editAttrName 0\n            -showAttrValues 0\n            -highlightSecondary 0\n            -showUVAttrsOnly 0\n            -showTextureNodesOnly 0\n            -attrAlphaOrder \"default\" \n            -animLayerFilterOptions \"allAffecting\" \n            -sortOrder \"none\" \n            -longNames 0\n            -niceNames 1\n            -showNamespace 1\n            -showPinIcons 0\n            -mapMotionTrails 0\n            -ignoreHiddenAttribute 0\n            -ignoreOutlinerColor 0\n            -renderFilterVisible 0\n            $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"graphEditor\" (localizedPanelLabel(\"Graph Editor\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Graph Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 1\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n"
		+ "                -showUpstreamCurves 1\n                -showUnitlessCurves 1\n                -showCompounds 0\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 1\n                -doNotSelectNewObjects 0\n                -dropIsParent 1\n                -transmitFilters 1\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n"
		+ "                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 1\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"GraphEd\");\n            animCurveEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -showPlayRangeShades \"on\" \n                -lockPlayRangeShades \"off\" \n                -smoothness \"fine\" \n                -resultSamples 1\n                -resultScreenSamples 0\n                -resultUpdate \"delayed\" \n                -showUpstreamCurves 1\n                -keyMinScale 1\n                -stackedCurvesMin -1\n                -stackedCurvesMax 1\n                -stackedCurvesSpace 0.2\n                -preSelectionHighlight 0\n                -constrainDrag 0\n                -valueLinesToggle 1\n                -highlightAffectedCurves 0\n"
		+ "                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dopeSheetPanel\" (localizedPanelLabel(\"Dope Sheet\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dope Sheet\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"OutlineEd\");\n            outlinerEditor -e \n                -showShapes 1\n                -showAssignedMaterials 0\n                -showTimeEditor 1\n                -showReferenceNodes 0\n                -showReferenceMembers 0\n                -showAttributes 1\n                -showConnected 1\n                -showAnimCurvesOnly 1\n                -showMuteInfo 0\n                -organizeByLayer 1\n                -organizeByClip 1\n                -showAnimLayerWeight 1\n                -autoExpandLayers 1\n                -autoExpand 0\n                -showDagOnly 0\n                -showAssets 1\n                -showContainedOnly 0\n"
		+ "                -showPublishedAsConnected 0\n                -showParentContainers 0\n                -showContainerContents 0\n                -ignoreDagHierarchy 0\n                -expandConnections 1\n                -showUpstreamCurves 1\n                -showUnitlessCurves 0\n                -showCompounds 1\n                -showLeafs 1\n                -showNumericAttrsOnly 1\n                -highlightActive 0\n                -autoSelectNewObjects 0\n                -doNotSelectNewObjects 1\n                -dropIsParent 1\n                -transmitFilters 0\n                -setFilter \"0\" \n                -showSetMembers 0\n                -allowMultiSelection 1\n                -alwaysToggleSelect 0\n                -directSelect 0\n                -displayMode \"DAG\" \n                -expandObjects 0\n                -setsIgnoreFilters 1\n                -containersIgnoreFilters 0\n                -editAttrName 0\n                -showAttrValues 0\n                -highlightSecondary 0\n                -showUVAttrsOnly 0\n                -showTextureNodesOnly 0\n"
		+ "                -attrAlphaOrder \"default\" \n                -animLayerFilterOptions \"allAffecting\" \n                -sortOrder \"none\" \n                -longNames 0\n                -niceNames 1\n                -showNamespace 1\n                -showPinIcons 0\n                -mapMotionTrails 1\n                -ignoreHiddenAttribute 0\n                -ignoreOutlinerColor 0\n                -renderFilterVisible 0\n                $editorName;\n\n\t\t\t$editorName = ($panelName+\"DopeSheetEd\");\n            dopeSheetEditor -e \n                -displayValues 0\n                -snapTime \"integer\" \n                -snapValue \"none\" \n                -outliner \"dopeSheetPanel1OutlineEd\" \n                -showSummary 1\n                -showScene 0\n                -hierarchyBelow 0\n                -showTicks 1\n                -selectionWindow 0 0 0 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"timeEditorPanel\" (localizedPanelLabel(\"Time Editor\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Time Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"clipEditorPanel\" (localizedPanelLabel(\"Trax Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Trax Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = clipEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 0 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"sequenceEditorPanel\" (localizedPanelLabel(\"Camera Sequencer\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n"
		+ "\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Camera Sequencer\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = sequenceEditorNameFromPanel($panelName);\n            clipEditor -e \n                -displayValues 0\n                -snapTime \"none\" \n                -snapValue \"none\" \n                -initialized 0\n                -manageSequencer 1 \n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperGraphPanel\" (localizedPanelLabel(\"Hypergraph Hierarchy\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypergraph Hierarchy\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"HyperGraphEd\");\n            hyperGraph -e \n                -graphLayoutStyle \"hierarchicalLayout\" \n                -orientation \"horiz\" \n                -mergeConnections 0\n                -zoom 1\n                -animateTransition 0\n                -showRelationships 1\n"
		+ "                -showShapes 0\n                -showDeformers 0\n                -showExpressions 0\n                -showConstraints 0\n                -showConnectionFromSelected 0\n                -showConnectionToSelected 0\n                -showConstraintLabels 0\n                -showUnderworld 0\n                -showInvisible 0\n                -transitionFrames 1\n                -opaqueContainers 0\n                -freeform 0\n                -imagePosition 0 0 \n                -imageScale 1\n                -imageEnabled 0\n                -graphType \"DAG\" \n                -heatMapDisplay 0\n                -updateSelection 1\n                -updateNodeAdded 1\n                -useDrawOverrideColor 0\n                -limitGraphTraversal -1\n                -range 0 0 \n                -iconSize \"smallIcons\" \n                -showCachedConnections 0\n                $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"hyperShadePanel\" (localizedPanelLabel(\"Hypershade\")) `;\n"
		+ "\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Hypershade\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"visorPanel\" (localizedPanelLabel(\"Visor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Visor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"nodeEditorPanel\" (localizedPanelLabel(\"Node Editor\")) `;\n\tif ($nodeEditorPanelVisible || $nodeEditorWorkspaceControlOpen) {\n\t\tif (\"\" == $panelName) {\n\t\t\tif ($useSceneConfig) {\n\t\t\t\t$panelName = `scriptedPanel -unParent  -type \"nodeEditorPanel\" -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels `;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n"
		+ "                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n"
		+ "                -hasWatchpoint 0\n                $editorName;\n\t\t\t}\n\t\t} else {\n\t\t\t$label = `panel -q -label $panelName`;\n\t\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Node Editor\")) -mbv $menusOkayInPanels  $panelName;\n\n\t\t\t$editorName = ($panelName+\"NodeEditorEd\");\n            nodeEditor -e \n                -allAttributes 0\n                -allNodes 0\n                -autoSizeNodes 1\n                -consistentNameSize 1\n                -createNodeCommand \"nodeEdCreateNodeCommand\" \n                -connectNodeOnCreation 0\n                -connectOnDrop 0\n                -copyConnectionsOnPaste 0\n                -connectionStyle \"bezier\" \n                -defaultPinnedState 0\n                -additiveGraphingMode 0\n                -settingsChangedCallback \"nodeEdSyncControls\" \n                -traversalDepthLimit -1\n                -keyPressCommand \"nodeEdKeyPressCommand\" \n                -nodeTitleMode \"name\" \n                -gridSnap 0\n                -gridVisibility 1\n                -crosshairOnEdgeDragging 0\n"
		+ "                -popupMenuScript \"nodeEdBuildPanelMenus\" \n                -showNamespace 1\n                -showShapes 1\n                -showSGShapes 0\n                -showTransforms 1\n                -useAssets 1\n                -syncedSelection 1\n                -extendToShapes 1\n                -editorMode \"default\" \n                -hasWatchpoint 0\n                $editorName;\n\t\t\tif (!$useSceneConfig) {\n\t\t\t\tpanel -e -l $label $panelName;\n\t\t\t}\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"createNodePanel\" (localizedPanelLabel(\"Create Node\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Create Node\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"polyTexturePlacementPanel\" (localizedPanelLabel(\"UV Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"UV Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"renderWindowPanel\" (localizedPanelLabel(\"Render View\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Render View\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"shapePanel\" (localizedPanelLabel(\"Shape Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tshapePanel -edit -l (localizedPanelLabel(\"Shape Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"posePanel\" (localizedPanelLabel(\"Pose Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tposePanel -edit -l (localizedPanelLabel(\"Pose Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n"
		+ "\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynRelEdPanel\" (localizedPanelLabel(\"Dynamic Relationships\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Dynamic Relationships\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"relationshipPanel\" (localizedPanelLabel(\"Relationship Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Relationship Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"referenceEditorPanel\" (localizedPanelLabel(\"Reference Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Reference Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"componentEditorPanel\" (localizedPanelLabel(\"Component Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Component Editor\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"dynPaintScriptedPanelType\" (localizedPanelLabel(\"Paint Effects\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Paint Effects\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"scriptEditorPanel\" (localizedPanelLabel(\"Script Editor\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Script Editor\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"profilerPanel\" (localizedPanelLabel(\"Profiler Tool\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Profiler Tool\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"contentBrowserPanel\" (localizedPanelLabel(\"Content Browser\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Content Browser\")) -mbv $menusOkayInPanels  $panelName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\n"
		+ "{ string $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"|persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"wireframe\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 1\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 16384\n                -fogging 0\n                -fogSource \"fragment\" \n"
		+ "                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -controllers 1\n                -nurbsCurves 1\n"
		+ "                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n"
		+ "                -width 0\n                -height 0\n                -sceneRenderFilter 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName; };\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Persp View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1040\\n    -height 811\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1040\\n    -height 811\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 12 -divisions 5 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "B974DBF3-4293-F109-E37E-96A1B02E6C8A";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode aiStandardSurface -n "Leaves";
	rename -uid "B06B103E-4107-FBB3-8EB4-6B916998B0B3";
createNode shadingEngine -n "aiStandardSurface2SG";
	rename -uid "5272DB57-4950-05C0-B6C2-9D9FE36BBD87";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo3";
	rename -uid "B5C76726-4276-DD0A-23D9-188362187230";
createNode file -n "LeavesTexture_1";
	rename -uid "4719E1CF-43EF-400E-2929-6EB7598305ED";
	setAttr ".ftn" -type "string" "C:/Users/jarne/Documents/DAE/sem_2/3D/tree/sourceimages/LeavesTexture.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture1";
	rename -uid "CA78D383-4F2A-4C94-7AA8-F3B4608271C8";
createNode file -n "LeavesOM_1";
	rename -uid "EB31249E-4EAF-8FA3-51DE-ADA9F7882633";
	setAttr ".ftn" -type "string" "C:/Users/jarne/Documents/DAE/sem_2/3D/tree/sourceimages/LeavesOM.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture2";
	rename -uid "D9035D9C-4A66-5E09-C27F-50B314157B76";
createNode aiStandardSurface -n "aiStandardSurface3";
	rename -uid "A294E540-4F3B-F79B-E9CE-EA83FA2F96BE";
createNode shadingEngine -n "aiStandardSurface3SG";
	rename -uid "B9A504F9-42F6-08F3-33FD-B899F2E43660";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo4";
	rename -uid "9B7CCCC2-4334-EDA7-17F0-E6BD04593675";
createNode file -n "file1";
	rename -uid "C7C8380D-418C-E0E3-AE4F-2A80EBE334E8";
	setAttr ".ftn" -type "string" "C:/Users/jarne/Documents/DAE/sem_2/3D/tree/sourceimages/Bark.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture3";
	rename -uid "4830379D-478E-94FC-19B5-1BBE392DB6C1";
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "BB8D73B0-4C49-C2D9-8D30-4DA8AFA7331D";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -927.38091553014567 254.72691492819942 ;
	setAttr ".tgi[0].vh" -type "double2" 108.33332902855351 933.36827595637749 ;
	setAttr -s 6 ".tgi[0].ni";
	setAttr ".tgi[0].ni[0].x" 125.03790283203125;
	setAttr ".tgi[0].ni[0].y" 1007.7423095703125;
	setAttr ".tgi[0].ni[0].nvs" 1923;
	setAttr ".tgi[0].ni[1].x" -183.946044921875;
	setAttr ".tgi[0].ni[1].y" 1011.3411865234375;
	setAttr ".tgi[0].ni[1].nvs" 2387;
	setAttr ".tgi[0].ni[2].x" -621.54754638671875;
	setAttr ".tgi[0].ni[2].y" 987.832275390625;
	setAttr ".tgi[0].ni[2].nvs" 1923;
	setAttr ".tgi[0].ni[3].x" -418.13027954101562;
	setAttr ".tgi[0].ni[3].y" 614.9295654296875;
	setAttr ".tgi[0].ni[3].nvs" 1923;
	setAttr ".tgi[0].ni[4].x" -400.11895751953125;
	setAttr ".tgi[0].ni[4].y" 987.832275390625;
	setAttr ".tgi[0].ni[4].nvs" 1923;
	setAttr ".tgi[0].ni[5].x" -639.558837890625;
	setAttr ".tgi[0].ni[5].y" 614.9295654296875;
	setAttr ".tgi[0].ni[5].nvs" 1923;
createNode groupId -n "groupId1";
	rename -uid "408A2D75-401D-9627-20F2-609FC9774650";
	setAttr ".ihi" 0;
createNode groupId -n "groupId2";
	rename -uid "E60CCCD6-45F3-91A0-8CF5-3F8FA778B4C7";
	setAttr ".ihi" 0;
select -ne :time1;
	setAttr ".o" 1;
	setAttr ".unw" 1;
select -ne :hardwareRenderingGlobals;
	setAttr ".otfna" -type "stringArray" 22 "NURBS Curves" "NURBS Surfaces" "Polygons" "Subdiv Surface" "Particles" "Particle Instance" "Fluids" "Strokes" "Image Planes" "UI" "Lights" "Cameras" "Locators" "Joints" "IK Handles" "Deformers" "Motion Trails" "Components" "Hair Systems" "Follicles" "Misc. UI" "Ornaments"  ;
	setAttr ".otfva" -type "Int32Array" 22 0 1 1 1 1 1
		 1 1 1 0 0 0 0 0 0 0 0 0
		 0 0 0 0 ;
	setAttr ".ta" 5;
	setAttr ".fprt" yes;
select -ne :renderPartition;
	setAttr -s 4 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 7 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 3 ".u";
select -ne :defaultRenderingList1;
select -ne :defaultTextureList1;
	setAttr -s 3 ".tx";
select -ne :standardSurface1;
	setAttr ".s" 0;
select -ne :initialShadingGroup;
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
connectAttr "groupId1.id" "polySurface31Shape.iog.og[0].gid";
connectAttr "aiStandardSurface2SG.mwc" "polySurface31Shape.iog.og[0].gco";
connectAttr "groupId2.id" "polySurface31Shape.iog.og[1].gid";
connectAttr "aiStandardSurface3SG.mwc" "polySurface31Shape.iog.og[1].gco";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface2SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface3SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface2SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface3SG.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr ":defaultArnoldDisplayDriver.msg" ":defaultArnoldRenderOptions.drivers"
		 -na;
connectAttr ":defaultArnoldFilter.msg" ":defaultArnoldRenderOptions.filt";
connectAttr ":defaultArnoldDriver.msg" ":defaultArnoldRenderOptions.drvr";
connectAttr "LeavesTexture_1.oc" "Leaves.base_color";
connectAttr "LeavesOM_1.oc" "Leaves.opacity";
connectAttr "Leaves.out" "aiStandardSurface2SG.ss";
connectAttr "polySurface31Shape.iog.og[0]" "aiStandardSurface2SG.dsm" -na;
connectAttr "groupId1.msg" "aiStandardSurface2SG.gn" -na;
connectAttr "aiStandardSurface2SG.msg" "materialInfo3.sg";
connectAttr "Leaves.msg" "materialInfo3.m";
connectAttr "Leaves.msg" "materialInfo3.t" -na;
connectAttr ":defaultColorMgtGlobals.cme" "LeavesTexture_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "LeavesTexture_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "LeavesTexture_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "LeavesTexture_1.ws";
connectAttr "place2dTexture1.c" "LeavesTexture_1.c";
connectAttr "place2dTexture1.tf" "LeavesTexture_1.tf";
connectAttr "place2dTexture1.rf" "LeavesTexture_1.rf";
connectAttr "place2dTexture1.mu" "LeavesTexture_1.mu";
connectAttr "place2dTexture1.mv" "LeavesTexture_1.mv";
connectAttr "place2dTexture1.s" "LeavesTexture_1.s";
connectAttr "place2dTexture1.wu" "LeavesTexture_1.wu";
connectAttr "place2dTexture1.wv" "LeavesTexture_1.wv";
connectAttr "place2dTexture1.re" "LeavesTexture_1.re";
connectAttr "place2dTexture1.of" "LeavesTexture_1.of";
connectAttr "place2dTexture1.r" "LeavesTexture_1.ro";
connectAttr "place2dTexture1.n" "LeavesTexture_1.n";
connectAttr "place2dTexture1.vt1" "LeavesTexture_1.vt1";
connectAttr "place2dTexture1.vt2" "LeavesTexture_1.vt2";
connectAttr "place2dTexture1.vt3" "LeavesTexture_1.vt3";
connectAttr "place2dTexture1.vc1" "LeavesTexture_1.vc1";
connectAttr "place2dTexture1.o" "LeavesTexture_1.uv";
connectAttr "place2dTexture1.ofs" "LeavesTexture_1.fs";
connectAttr ":defaultColorMgtGlobals.cme" "LeavesOM_1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "LeavesOM_1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "LeavesOM_1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "LeavesOM_1.ws";
connectAttr "place2dTexture2.c" "LeavesOM_1.c";
connectAttr "place2dTexture2.tf" "LeavesOM_1.tf";
connectAttr "place2dTexture2.rf" "LeavesOM_1.rf";
connectAttr "place2dTexture2.mu" "LeavesOM_1.mu";
connectAttr "place2dTexture2.mv" "LeavesOM_1.mv";
connectAttr "place2dTexture2.s" "LeavesOM_1.s";
connectAttr "place2dTexture2.wu" "LeavesOM_1.wu";
connectAttr "place2dTexture2.wv" "LeavesOM_1.wv";
connectAttr "place2dTexture2.re" "LeavesOM_1.re";
connectAttr "place2dTexture2.of" "LeavesOM_1.of";
connectAttr "place2dTexture2.r" "LeavesOM_1.ro";
connectAttr "place2dTexture2.n" "LeavesOM_1.n";
connectAttr "place2dTexture2.vt1" "LeavesOM_1.vt1";
connectAttr "place2dTexture2.vt2" "LeavesOM_1.vt2";
connectAttr "place2dTexture2.vt3" "LeavesOM_1.vt3";
connectAttr "place2dTexture2.vc1" "LeavesOM_1.vc1";
connectAttr "place2dTexture2.o" "LeavesOM_1.uv";
connectAttr "place2dTexture2.ofs" "LeavesOM_1.fs";
connectAttr "file1.oc" "aiStandardSurface3.base_color";
connectAttr "aiStandardSurface3.out" "aiStandardSurface3SG.ss";
connectAttr "polySurface31Shape.iog.og[1]" "aiStandardSurface3SG.dsm" -na;
connectAttr "groupId2.msg" "aiStandardSurface3SG.gn" -na;
connectAttr "aiStandardSurface3SG.msg" "materialInfo4.sg";
connectAttr "aiStandardSurface3.msg" "materialInfo4.m";
connectAttr "file1.msg" "materialInfo4.t" -na;
connectAttr ":defaultColorMgtGlobals.cme" "file1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "file1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "file1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "file1.ws";
connectAttr "place2dTexture3.c" "file1.c";
connectAttr "place2dTexture3.tf" "file1.tf";
connectAttr "place2dTexture3.rf" "file1.rf";
connectAttr "place2dTexture3.mu" "file1.mu";
connectAttr "place2dTexture3.mv" "file1.mv";
connectAttr "place2dTexture3.s" "file1.s";
connectAttr "place2dTexture3.wu" "file1.wu";
connectAttr "place2dTexture3.wv" "file1.wv";
connectAttr "place2dTexture3.re" "file1.re";
connectAttr "place2dTexture3.of" "file1.of";
connectAttr "place2dTexture3.r" "file1.ro";
connectAttr "place2dTexture3.n" "file1.n";
connectAttr "place2dTexture3.vt1" "file1.vt1";
connectAttr "place2dTexture3.vt2" "file1.vt2";
connectAttr "place2dTexture3.vt3" "file1.vt3";
connectAttr "place2dTexture3.vc1" "file1.vc1";
connectAttr "place2dTexture3.o" "file1.uv";
connectAttr "place2dTexture3.ofs" "file1.fs";
connectAttr "aiStandardSurface2SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[0].dn"
		;
connectAttr "Leaves.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[1].dn"
		;
connectAttr "place2dTexture1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[2].dn"
		;
connectAttr "LeavesOM_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[3].dn"
		;
connectAttr "LeavesTexture_1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[4].dn"
		;
connectAttr "place2dTexture2.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[5].dn"
		;
connectAttr "aiStandardSurface2SG.pa" ":renderPartition.st" -na;
connectAttr "aiStandardSurface3SG.pa" ":renderPartition.st" -na;
connectAttr "Leaves.msg" ":defaultShaderList1.s" -na;
connectAttr "aiStandardSurface3.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture2.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "LeavesTexture_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "LeavesOM_1.msg" ":defaultTextureList1.tx" -na;
connectAttr "file1.msg" ":defaultTextureList1.tx" -na;
// End of tree.ma
