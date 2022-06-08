//Maya ASCII 2022 scene
//Name: 1GD22_WiemeJarne_Parasol.ma
//Last modified: Wed, Jun 08, 2022 06:09:47 PM
//Codeset: 1252
requires maya "2022";
requires "stereoCamera" "10.0";
requires -nodeType "aiOptions" -nodeType "aiAOVDriver" -nodeType "aiAOVFilter" -nodeType "aiSkyDomeLight"
		 -nodeType "aiStandardSurface" "mtoa" "5.0.0.1";
requires "stereoCamera" "10.0";
currentUnit -l centimeter -a degree -t film;
fileInfo "application" "maya";
fileInfo "product" "Maya 2022";
fileInfo "version" "2022";
fileInfo "cutIdentifier" "202110272215-ad32f8f1e6";
fileInfo "osv" "Windows 10 Home v2009 (Build: 19043)";
fileInfo "UUID" "DBFBD788-4009-FA8A-C84B-14BA5C4A232E";
fileInfo "license" "education";
createNode transform -s -n "persp";
	rename -uid "CBB20537-40F8-A23F-4B21-26837A14FFF1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 442.22384048078175 288.33481175771573 43.47627349659939 ;
	setAttr ".r" -type "double3" 341.06164701293238 -3152.1999999983427 -4.1426624226031225e-14 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "6CB0EF23-4C47-136F-7BC7-2C89212700F0";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 505.65029106896014;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".tp" -type "double3" 0 118.16011810302734 0 ;
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".dgm" no;
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "45E02EF2-4F56-EF12-FDF5-2895A3A150BC";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -86.505034580867772 1000.1 31.895641961253745 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "30CC5B27-4562-DCB1-B432-9BB785A531E9";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 256.10760454479333;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "E954741A-49E3-D1E2-3A3A-34907A2CA684";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -105.93387791458406 234.58808259988376 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "1F5AE986-4B50-6B46-DB4F-279C57D4A5C7";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 654.72249756701478;
	setAttr ".imn" -type "string" "front";
	setAttr ".den" -type "string" "front_depth";
	setAttr ".man" -type "string" "front_mask";
	setAttr ".hc" -type "string" "viewSet -f %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "side";
	rename -uid "83D0C7A7-414C-8094-4EDC-AA901C3893A1";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 188.89962213557718 0.62393084241186614 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "8F23D138-46DB-4DF0-85BB-A98A807A7331";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 25.887188874862694;
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
createNode transform -n "bottom";
	rename -uid "1BC6BFAC-4DEA-7C7B-21FE-A180DE5365F4";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 47.907682370113449 -1000.1 51.067489419283447 ;
	setAttr ".r" -type "double3" 90 0 0 ;
createNode camera -n "bottomShape" -p "bottom";
	rename -uid "ABBD451D-41E6-322C-D057-05B159D43FF0";
	setAttr -k off ".v";
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 223.25467646470565;
	setAttr ".imn" -type "string" "bottom1";
	setAttr ".den" -type "string" "bottom1_depth";
	setAttr ".man" -type "string" "bottom1_mask";
	setAttr ".hc" -type "string" "viewSet -bo %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "left";
	rename -uid "B6791DA9-45E5-A37E-F01C-1CB58933653C";
	setAttr ".v" no;
	setAttr ".t" -type "double3" -1000.1 258.59723540245744 -52.226644947152039 ;
	setAttr ".r" -type "double3" 0 -90 0 ;
createNode camera -n "leftShape" -p "left";
	rename -uid "BE4D05F2-4DF8-F6DB-142C-5185F2037DA2";
	setAttr -k off ".v";
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 172.87734782387284;
	setAttr ".imn" -type "string" "left1";
	setAttr ".den" -type "string" "left1_depth";
	setAttr ".man" -type "string" "left1_mask";
	setAttr ".hc" -type "string" "viewSet -ls %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "Parasol";
	rename -uid "335E3358-45CC-903B-6D83-5E8E7024AAFB";
createNode mesh -n "ParasolShape" -p "Parasol";
	rename -uid "C7E31208-450B-3568-79C5-F0A0B1D140AA";
	setAttr -k off ".v";
	setAttr -s 2 ".iog[0].og";
	setAttr ".iog[0].og[1].gcl" -type "componentList" 31 "map[8:9]" "map[16:19]" "map[22:23]" "map[25]" "map[27:30]" "map[33:35]" "map[37:39]" "map[42:45]" "map[48:49]" "map[54:55]" "map[58:59]" "map[61:63]" "map[72:75]" "map[82:83]" "map[86:87]" "map[90:91]" "map[94:95]" "map[97:101]" "map[103:118]" "map[120:121]" "map[126]" "map[129]" "map[131]" "map[137:154]" "map[159:160]" "map[162]" "map[173]" "map[176]" "map[179:180]" "map[232]" "map[258]";
	setAttr ".iog[0].og[3].gcl" -type "componentList" 4 "f[65]" "f[71:73]" "f[102]" "f[104:105]";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr -s 14 ".gtag";
	setAttr ".gtag[0].gtagnm" -type "string" "back";
	setAttr ".gtag[0].gtagcmp" -type "componentList" 3 "f[38]" "f[44]" "f[72]";
	setAttr ".gtag[1].gtagnm" -type "string" "bottom";
	setAttr ".gtag[1].gtagcmp" -type "componentList" 4 "f[39]" "f[45]" "f[73]" "f[94:105]";
	setAttr ".gtag[2].gtagnm" -type "string" "bottomRing";
	setAttr ".gtag[2].gtagcmp" -type "componentList" 1 "e[205:216]";
	setAttr ".gtag[3].gtagnm" -type "string" "cylBottomCap";
	setAttr ".gtag[3].gtagcmp" -type "componentList" 2 "vtx[134:145]" "vtx[158]";
	setAttr ".gtag[4].gtagnm" -type "string" "cylBottomRing";
	setAttr ".gtag[4].gtagcmp" -type "componentList" 1 "vtx[134:145]";
	setAttr ".gtag[5].gtagnm" -type "string" "cylSides";
	setAttr ".gtag[5].gtagcmp" -type "componentList" 1 "vtx[134:157]";
	setAttr ".gtag[6].gtagnm" -type "string" "cylTopCap";
	setAttr ".gtag[6].gtagcmp" -type "componentList" 2 "vtx[146:157]" "vtx[159]";
	setAttr ".gtag[7].gtagnm" -type "string" "cylTopRing";
	setAttr ".gtag[7].gtagcmp" -type "componentList" 1 "vtx[146:157]";
	setAttr ".gtag[8].gtagnm" -type "string" "front";
	setAttr ".gtag[8].gtagcmp" -type "componentList" 3 "f[36]" "f[42]" "f[70]";
	setAttr ".gtag[9].gtagnm" -type "string" "left";
	setAttr ".gtag[9].gtagcmp" -type "componentList" 3 "f[41]" "f[47]" "f[75]";
	setAttr ".gtag[10].gtagnm" -type "string" "right";
	setAttr ".gtag[10].gtagcmp" -type "componentList" 3 "f[40]" "f[46]" "f[74]";
	setAttr ".gtag[11].gtagnm" -type "string" "sides";
	setAttr ".gtag[11].gtagcmp" -type "componentList" 1 "f[82:93]";
	setAttr ".gtag[12].gtagnm" -type "string" "top";
	setAttr ".gtag[12].gtagcmp" -type "componentList" 4 "f[37]" "f[43]" "f[71]" "f[106:117]";
	setAttr ".gtag[13].gtagnm" -type "string" "topRing";
	setAttr ".gtag[13].gtagcmp" -type "componentList" 1 "e[217:228]";
	setAttr ".pv" -type "double2" 0.97620984084282147 0.23106948796480825 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr -s 268 ".uvst[0].uvsp";
	setAttr ".uvst[0].uvsp[0:249]" -type "float2" 0.66751039 0.035480767 0.6738413
		 0.035478354 0.67405897 0.6311847 0.66772789 0.63118708 0.68017238 0.035476029 0.68039
		 0.63118225 0.66117918 0.035483032 0.6613968 0.63118923 0.68650341 0.035473615 0.68672097
		 0.63117987 0.70549709 0.03546682 0.71182793 0.035464555 0.71204549 0.63117069 0.70571464
		 0.63117313 0.7181589 0.035462171 0.71837664 0.63116854 0.69916564 0.035469145 0.69938332
		 0.63117552 0.72449023 0.035459995 0.72470748 0.6311661 0.82813269 0.786641 0.84066516
		 0.78658539 0.84131175 0.93184972 0.8287794 0.93190533 0.85319722 0.78652954 0.85384434
		 0.93179369 0.81560016 0.78669643 0.81624645 0.93196166 0.86572981 0.78647363 0.8663764
		 0.93173796 0.90397346 0.93157071 0.90332657 0.78630626 0.91585952 0.78625023 0.91650581
		 0.9315148 0.89079452 0.78636229 0.8914414 0.93162644 0.92839158 0.78619462 0.92903811
		 0.93145907 0.94092417 0.78613871 0.94157106 0.93140316 0.35333753 0.9853301 0.23400827
		 0.98634607 0.23393017 0.97716683 0.35325944 0.97615105 0.97048056 0.036856148 0.97297025
		 0.41643229 0.96400183 0.41649106 0.96151185 0.036914889 0.98193914 0.41637346 0.97944939
		 0.036796842 0.98841763 0.036738101 0.99090779 0.41631457 0.45941412 0.92370319 0.45940214
		 0.91632515 0.46677983 0.91631377 0.46679151 0.92369121 0.052479852 0.97272992 0.040439744
		 0.81908637 0.041582961 0.82190508 0.053651694 0.9724803 0.049061891 0.66820419 0.050239261
		 0.66842723 0.61786884 0.61877888 0.63002491 0.060317207 0.63225889 0.060365904 0.62010276
		 0.61882758 0.8841781 0.59397268 0.87327278 0.59391886 0.87331706 0.58488995 0.88422251
		 0.58494371 0.86236745 0.59386504 0.8624118 0.58483636 0.89508331 0.59402633 0.89512759
		 0.58499748 0.85146201 0.59381133 0.85150623 0.58478242 0.81874561 0.59365016 0.80784023
		 0.59359658 0.80788499 0.58456737 0.81879038 0.58462137 0.7969349 0.59354275 0.79697955
		 0.58451378 0.829651 0.59370399 0.82969552 0.58467507 0.78602952 0.59348923 0.78607422
		 0.58446014 0.77805662 0.86814761 0.45683509 0.87164515 0.45675269 0.86405569 0.77797383
		 0.86055797 0.45691761 0.87923515 0.77813911 0.87573731 0.77822161 0.88332731 0.4570004
		 0.88682508 0.87346268 0.72812521 0.90429765 0.77008003 0.3521654 0.84764236 0.3522436
		 0.85682178 0.89284748 0.74369025 0.91043293 0.75106138 0.90734124 0.7568965 0.9275983
		 0.69601172 0.92958933 0.69456011 0.92777187 0.69912702 0.23717611 0.87651557 0.92962694
		 0.69447589 0.92965609 0.69457883 0.93084323 0.70238841 0.93825984 0.68149358 0.93924177
		 0.68719739 0.92937374 0.70480222 0.92542768 0.68244731 0.94561225 0.68355024 0.24371317
		 0.87554997 0.22398654 0.88745934 0.24534327 0.87514526 0.94753194 0.70539588 0.95285261
		 0.70907336 0.94826001 0.69449455 0.95655936 0.708435 0.94850558 0.74642432 0.95966011
		 0.68943805 0.93013257 0.93547004 0.9176001 0.93552589 0.94266474 0.93541414 0.90506715
		 0.93558121 0.95410311 0.93134761 0.95519698 0.9353587 0.89253509 0.93563753 0.96663547
		 0.93129182 0.81734049 0.93597174 0.87890875 0.93168223 0.88000304 0.93569344 0.82987326
		 0.93591642 0.86747044 0.93574888 0.84240556 0.93586051 0.85493809 0.93580437 0.83260727
		 0.5546459 0.8233611 0.55471551 0.81934619 0.020202646 0.82859266 0.020133117 0.88130939
		 0.55571461 0.872141 0.55572987 0.87126631 0.025727024 0.88043463 0.025711676 0.77901775
		 0.91580474 0.77902979 0.92318207 0.77895349 0.55680168 0.7697044 0.55677003 0.77153552
		 0.022122273 0.78078461 0.022153923 0.93047798 0.55489945 0.92130953 0.55492938 0.91956991
		 0.024928411 0.92873859 0.024898311 0.67151701 0.83179361 0.19976352 0.82446605 0.56191391
		 0.6541065 0.09580221 0.81996667 0.073354773 0.01330282 0.32663614 0.3330957 0.11547814
		 0.30478269 0.059735619 0.64163965 0.015532694 0.36340183 0.84035623 0.63445705 0.83093864
		 0.62895787 0.84590882 0.61413431 0.82553244 0.61948663 0.8512615 0.63451082 0.82558632
		 0.60858142 0.86073238 0.62910455 0.83108526 0.59916383 0.8662318 0.61968738 0.84055644
		 0.59375763 0.8662855 0.60878211 0.86087924 0.59931087 0.2478407 0.86463678 0.9091661
		 0.73496479 0.91727531 0.7354306 0.91691703 0.74659234 0.93218863 0.73998976 0.92958361
		 0.69455355 0.73082113 0.035457522 0.73103881 0.63116395 0.73715252 0.035455108 0.73737031
		 0.63116145 0.69283432 0.035471469 0.69305199 0.63117754 0.95345622 0.78608298 0.96598917
		 0.78602707 0.87826234 0.7864176 0.36142287 0.85674357 0.36243844 0.97607267 0.98199797
		 0.42534193 0.97302943 0.42540088 0.46676773 0.90893584 0.77900559 0.90842736 0.77904147
		 0.93055981 0.46680373 0.93106902 0.073542766 0.011076258 0.63021314 0.058090705 0.61796033
		 0.62101144 0.059827112 0.64387232 0.91689408 0.59413391 0.90598863 0.59408009 0.90603292
		 0.5850513 0.91693842 0.585105 0.84060115 0.58472908 0.44932783 0.8793177 0.44924542
		 0.87172854 0.22475091 0.97724485 0.84185386 0.55457664 0.82342994 0.56396228 0.83783919
		 0.020063618 0.81411433 0.55478501 0.8100996 0.020271996 0.88132447 0.56488323 0.87215579
		 0.56489837 0.86209762 0.025741955 0.8896035 0.025696566 0.89047796 0.55569929 0.78820211
		 0.55683291 0.76967275 0.566019 0.79003322 0.022185871 0.76045549 0.55673802 0.7622866
		 0.022090415 0.93050796 0.56406778 0.92133951 0.56409794 0.91040152 0.024958363 0.9379068
		 0.024868121 0.9396466 0.55486917 0.017162194 0.28924304 0.041622136 0.81928009 0.04041693
		 0.82218254 0.77892154 0.56605029 0.86297238 0.55574501 0.91214079 0.55495942 0.83267689
		 0.56389266 0.96557736 0.93531221 0.9029156 0.9355908 0.8903833 0.93564695 0.87785095
		 0.93570316 0.8653183 0.93575847 0.85278594 0.93581378 0.84025347 0.93587041 0.827721
		 0.93592596 0.95304513 0.93536812 0.94051266 0.93542355 0.9279803 0.93547958 0.91544795
		 0.93553549;
	setAttr ".uvst[0].uvsp[250:267]" 0.72838753 0.84159601 0.48347223 0.65275776
		 0.26710153 0.82654208 0.10941949 0.64917678 0.31901193 0.83966166 0.89388698 0.66118079
		 0.43654147 0.64691734 0.9569301 0.70867431 0.92513484 0.70976025 0.92445564 0.70489156
		 0.92518955 0.69115281 0.23307846 0.87712085 0.22903186 0.88172215 0.95410836 0.67867637
		 0.90240002 0.72250116 0.24462652 0.85773754 0.26024291 0.84842497 0.11443795 0.35217121;
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr -s 11 ".pt";
	setAttr ".pt[60]" -type "float3" 4.0531158e-06 -2.8610229e-06 7.5232238e-06 ;
	setAttr ".pt[61]" -type "float3" 2.1457672e-06 7.6293945e-06 7.5232238e-06 ;
	setAttr ".pt[62]" -type "float3" -1.1920929e-06 2.3841858e-06 7.5232238e-06 ;
	setAttr ".pt[63]" -type "float3" -1.9073486e-06 0 0 ;
	setAttr ".pt[64]" -type "float3" 7.1525574e-07 2.3841858e-06 7.5232238e-06 ;
	setAttr ".pt[161]" -type "float3" -1.9073486e-06 0 0 ;
	setAttr ".pt[165]" -type "float3" -1.9073486e-06 0 0 ;
	setAttr ".pt[168]" -type "float3" -1.9073486e-06 0 0 ;
	setAttr ".pt[177]" -type "float3" 0 5.9604645e-08 0 ;
	setAttr ".pt[184]" -type "float3" 0 5.9604645e-08 0 ;
	setAttr ".pt[188]" -type "float3" -1.9073486e-06 0 0 ;
	setAttr -s 192 ".vt";
	setAttr ".vt[0:165]"  3.50949287 32.83629608 -2.026207447 2.026207447 32.83629608 -3.50949287
		 2.026207447 230.2117157 -3.50949287 3.50949287 230.2117157 -2.026207447 0 32.83629608 -4.052414894
		 0 230.2117157 -4.052414894 -2.026207447 32.83629608 -3.50949287 -2.026207447 230.2117157 -3.50949287
		 -3.50949287 32.83629608 -2.026207447 -3.50949287 230.2117157 -2.026207447 -4.052414894 32.83629608 0
		 -4.052414894 230.2117157 0 -3.50949287 32.83629608 2.026207447 -3.50949287 230.2117157 2.026207447
		 -2.026207447 32.83629608 3.50949287 -2.026207447 230.2117157 3.50949287 0 32.83629608 4.052414894
		 0 230.2117157 4.052414894 2.026207447 32.83629608 3.50949287 2.026207447 230.2117157 3.50949287
		 3.50949287 32.83629608 2.026207447 3.50949287 230.2117157 2.026207447 4.052414894 32.83629608 0
		 4.052414894 230.2117157 0 4.33012676 4.83732986 -2.5 2.5 4.83732986 -4.33012676 0 4.83732986 -5
		 -2.5 4.83732986 -4.33012676 -4.33012676 4.83732986 -2.5 -5 4.83732986 0 -4.33012676 4.83732986 2.5
		 -2.5 4.83732986 4.33012676 0 4.83732986 5 2.5 4.83732986 4.33012676 4.33012676 4.83732986 2.5
		 5 4.83732986 0 4.33012676 34.83732986 -2.5 2.5 34.83732986 -4.33012676 0 34.83732986 -5
		 -2.5 34.83732986 -4.33012676 -4.33012676 34.83732986 -2.5 -5 34.83732986 0 -4.33012676 34.83732986 2.5
		 -2.5 34.83732986 4.33012676 0 34.83732986 5 2.5 34.83732986 4.33012676 4.33012676 34.83732986 2.5
		 5 34.83732986 0 4.14143276 34.83732986 0 3.58658576 34.83732986 -2.070716381 2.070716381 34.83732986 -3.58658576
		 0 34.83732986 -4.14143276 -2.070716381 34.83732986 -3.58658576 -3.58658576 34.83732986 -2.070716381
		 -4.14143276 34.83732986 0 -3.58658576 34.83732986 2.070716381 -2.070716381 34.83732986 3.58658576
		 0 34.83732986 4.14143276 2.070716381 34.83732986 3.58658576 3.58658576 34.83732986 2.070716381
		 -32.49999619 -2.8610229e-06 32.50000763 -32.49999619 5.000007629395 32.50000763 -32.5 5.000002384186 -32.49999237
		 32.5 5 -32.5 -32.5 2.3841858e-06 -32.49999237 32.5 0 -32.5 -1.47284281 231.38331604 -2.337677
		 1.52715719 231.38331604 -2.337677 -1.47284281 234.20237732 -3.36374664 1.52715719 234.20237732 -3.36374664
		 -1.47284281 190.77671814 -122.67404938 1.52715719 190.77671814 -122.67404938 -1.47284281 187.95765686 -121.64797974
		 1.52715719 187.95765686 -121.64797974 -4.67495728 230.89103699 -2.66327286 -2.55517578 230.84388733 -4.78560638
		 -5.16995239 233.79664612 -3.222229 -3.050170898 233.74949646 -5.34456253 -124.50263977 190.72291565 -121.45445251
		 -122.38285828 190.67576599 -123.57679749 -124.0076446533 187.81730652 -120.89550781
		 -121.88786316 187.77015686 -123.017837524 3.55853653 230.52555847 -4.73241806 5.68087006 230.47840881 -2.61263657
		 4.11749268 233.4311676 -5.22741318 6.2398262 233.38401794 -3.10763168 122.34971619 190.35743713 -124.56010437
		 124.47206116 190.31028748 -122.44032288 121.79077148 187.451828 -124.065109253 123.9131012 187.40467834 -121.94532776
		 2.77618408 231.38331604 -1.38055885 2.77618408 231.38331604 1.61944115 3.80225372 234.20237732 -1.38055885
		 3.80225372 234.20237732 1.61944115 123.11255646 190.77671814 -1.38055885 123.11255646 190.77671814 1.61944115
		 122.086486816 187.95765686 -1.38055885 122.086486816 187.95765686 1.61944115 4.39080429 231.28849792 1.64106369
		 2.2489357 231.22084045 3.74054718 4.86462784 234.19410706 2.21807098 2.72275925 234.12644958 4.31755447
		 123.16204834 191.2117157 121.51908875 121.020179749 191.14407349 123.61856842 122.68822479 188.30610657 120.94208527
		 120.5463562 188.23846436 123.041564941 -0.4327774 231.22306824 3.79772186 -2.52704239 231.15541077 1.65074921
		 -1.010936737 234.12867737 4.2701416 -3.10520172 234.061019897 2.12316895 -120.59944153 191.14628601 122.27693176
		 -122.6937027 191.078643799 120.12997437 -120.021278381 188.24067688 121.80451965
		 -122.11553955 188.17303467 119.657547 125 190.6477356 125 -125 190.6477356 125 125 189.6477356 125
		 -125 189.6477356 125 125 189.6477356 -125 -125 189.6477356 -125 125 190.6477356 -125
		 -125 190.6477356 -125 6.1232343e-17 235.32023621 0 -6.1232343e-17 236.32023621 0
		 6.062177658 229.72425842 -3.5 3.5 229.72425842 -6.062177658 0 229.72425842 -7 -3.5 229.72425842 -6.062177658
		 -6.062177658 229.72425842 -3.5 -7 229.72425842 0 -6.062177658 229.72425842 3.5 -3.5 229.72425842 6.062177658
		 0 229.72425842 7 3.5 229.72425842 6.062177658 6.062177658 229.72425842 3.5 7 229.72425842 0
		 6.062177658 232.72425842 -3.5 3.5 232.72425842 -6.062177658 0 232.72425842 -7 -3.5 232.72425842 -6.062177658
		 -6.062177658 232.72425842 -3.5 -7 232.72425842 0 -6.062177658 232.72425842 3.5 -3.5 232.72425842 6.062177658
		 0 232.72425842 7 3.5 232.72425842 6.062177658 6.062177658 232.72425842 3.5 7 232.72425842 0
		 4.7683716e-07 229.72425842 3.5762787e-07 1.513955 231.38331604 3.15361786 -1.486045 231.38331604 3.15361786
		 1.513955 234.20237732 4.1796875 -1.486045 234.20237732 4.1796875 1.513955 190.77671814 123.48999023
		 -1.486045 190.77671814 123.48999023 1.513955 187.95765686 122.46392059 -1.486045 187.95765686 122.46392059
		 -125 174.36727905 0.024002075 -125 173.36727905 0 -83.1563797 189.65609741 0.015967404
		 -82.48036957 188.90310669 0 32.5 5 26.12020302 21.99612808 5 32.5 16.40729904 0 32.5
		 32.5 0 17.57116508 23.015262604 5 25.81046295;
	setAttr ".vt[166:191]" 17.60404396 1.7881393e-07 25.38119316 21.43667603 4.1723251e-07 17.48669243
		 28.72745323 5 24.40153313 31.86375237 3.65279579 21.91868782 30.58725739 1.14815187 19.21801567
		 24.072429657 1.47580922 19.94677734 26.74957275 2.97977209 21.52179718 27.56557083 1.97163987 19.19297981
		 29.81149292 2.71849084 17.48694801 28.090425491 4.24773979 21.58294106 19.50870705 2.77464986 32.5
		 22.30682945 5 30.26534271 18.20518112 0.70753503 25.35131836 22.90974998 3.33496904 29.81884384
		 19.89361382 2.26473808 31.16702461 17.96813011 1.87090206 28.91472626 22.90953636 3.33028007 29.78277779
		 22.37069702 3.6930871 27.33892822 23.22428703 4.15488768 28.21430206 23.47792625 4.42703819 29.20611
		 22.59653664 3.89581227 26.69813347 18.73767471 1.80217898 26.25403023 22.80249977 5 26.7003212
		 15.32915688 0.28194606 29.59620476 22.94620514 3.34616876 29.79101753 18.41574097 1.30469966 31.73208046;
	setAttr -s 335 ".ed";
	setAttr ".ed[0:165]"  0 1 0 1 2 1 3 2 0 0 3 1 1 4 0 4 5 1 2 5 0 4 6 0 6 7 1
		 5 7 0 6 8 0 8 9 1 7 9 0 8 10 0 10 11 1 9 11 0 10 12 0 12 13 1 11 13 0 12 14 0 14 15 1
		 13 15 0 14 16 0 16 17 1 15 17 0 16 18 0 18 19 1 17 19 0 18 20 0 20 21 1 19 21 0 20 22 0
		 22 23 1 21 23 0 22 0 0 23 3 0 24 25 0 25 26 0 26 27 0 27 28 0 28 29 0 29 30 0 30 31 0
		 31 32 0 32 33 0 33 34 0 34 35 0 35 24 0 36 37 0 37 38 0 38 39 0 39 40 0 40 41 0 41 42 0
		 42 43 0 43 44 0 44 45 0 45 46 0 46 47 0 47 36 0 25 37 1 26 38 1 28 40 1 29 41 1 30 42 1
		 31 43 1 32 44 1 33 45 1 34 46 1 35 47 1 47 48 0 36 49 0 48 49 0 37 50 0 49 50 0 38 51 0
		 50 51 0 39 52 0 51 52 0 40 53 0 52 53 0 41 54 0 53 54 0 42 55 0 54 55 0 43 56 0 55 56 0
		 44 57 0 56 57 0 45 58 0 57 58 0 46 59 0 58 59 0 59 48 0 60 163 0 61 162 0 62 63 0
		 64 65 0 60 61 0 62 64 0 63 65 0 64 60 0 65 164 0 66 67 0 70 71 0 72 73 0 66 68 0
		 67 69 0 68 70 0 69 71 0 70 72 0 71 73 0 72 66 0 73 67 0 74 75 0 78 79 0 80 81 0 74 76 0
		 75 77 0 76 78 0 77 79 0 78 80 0 79 81 0 80 74 0 81 75 0 82 83 0 86 87 0 88 89 0 82 84 0
		 83 85 0 84 86 0 85 87 0 86 88 0 87 89 0 88 82 0 89 83 0 90 91 0 94 95 0 96 97 0 90 92 0
		 91 93 0 92 94 0 93 95 0 94 96 0 95 97 0 96 90 0 97 91 0 98 99 0 102 103 0 104 105 0
		 98 100 0 99 101 0 100 102 0 101 103 0 102 104 0 103 105 0 104 98 0 105 99 0 106 107 0
		 110 111 0 112 113 0 106 108 0 107 109 0 108 110 0 109 111 0 110 112 0;
	setAttr ".ed[166:331]" 111 113 0 112 106 0 113 107 0 114 115 0 116 117 0 118 119 0
		 120 121 0 114 116 0 115 117 0 116 118 0 117 158 0 118 120 0 119 121 0 120 114 0 121 157 0
		 118 122 0 122 117 0 116 122 0 122 119 0 114 123 0 123 121 0 115 123 0 123 120 0 124 125 0
		 125 126 0 126 127 0 127 128 0 128 129 0 129 130 0 130 131 0 131 132 0 132 133 0 133 134 0
		 134 135 0 135 124 0 136 137 0 137 138 0 138 139 0 139 140 0 140 141 0 141 142 0 142 143 0
		 143 144 0 144 145 0 145 146 0 146 147 0 147 136 0 124 136 1 125 137 1 126 138 1 127 139 1
		 128 140 1 129 141 1 130 142 1 131 143 1 132 144 1 133 145 1 134 146 1 135 147 1 148 124 1
		 148 125 1 148 126 1 148 127 1 148 128 1 148 129 1 148 130 1 148 131 1 148 132 1 148 133 1
		 148 134 1 148 135 1 149 150 0 153 154 0 155 156 0 149 151 0 150 152 0 151 153 0 152 154 0
		 153 155 0 154 156 0 155 149 0 156 150 0 157 115 0 123 159 0 158 119 0 158 160 0 159 157 0
		 121 159 1 159 115 1 160 122 0 119 160 1 160 117 1 161 63 0 161 168 0 162 176 0 163 189 0
		 166 178 0 167 164 0 165 167 0 161 164 0 166 167 0 168 165 0 168 169 0 169 170 0 170 171 0
		 171 172 0 172 173 0 173 174 0 174 175 0 175 172 0 175 168 0 174 169 0 173 170 0 176 163 0
		 177 162 0 178 165 0 176 177 0 177 179 0 179 180 0 180 181 0 181 182 0 181 183 0 183 184 0
		 184 185 0 184 186 0 186 187 0 187 178 0 179 190 0 181 187 0 180 176 0 166 181 0 175 165 0
		 172 165 0 171 165 0 171 167 0 170 164 0 161 169 0 174 170 0 180 191 0 61 62 0 188 177 0
		 186 188 0 186 165 0 186 183 0 184 177 0 185 177 0 189 166 0 190 184 0 182 179 0 181 163 0
		 190 182 1 181 189 0 185 190 0 182 183 0 191 163 0 181 191 0 157 158 1 169 164 0 176 60 1
		 177 61 1 165 62 1 165 188 0 188 61 1 168 62 1 176 191 0 24 36 1;
	setAttr ".ed[332:334]" 27 39 1 173 171 0 178 167 1;
	setAttr -s 154 -ch 560 ".fc[0:153]" -type "polyFaces" 
		f 4 0 1 -3 -4
		mu 0 4 14 18 19 15
		f 4 4 5 -7 -2
		mu 0 4 18 182 183 19
		f 4 7 8 -10 -6
		mu 0 4 182 184 185 183
		f 4 10 11 -13 -9
		mu 0 4 6 0 3 7
		f 4 13 14 -16 -12
		mu 0 4 0 1 2 3
		f 4 16 17 -19 -15
		mu 0 4 1 4 5 2
		f 4 19 20 -22 -18
		mu 0 4 4 8 9 5
		f 4 22 23 -25 -21
		mu 0 4 8 186 187 9
		f 4 25 26 -28 -24
		mu 0 4 186 16 17 187
		f 4 28 29 -31 -27
		mu 0 4 16 10 13 17
		f 4 31 32 -34 -30
		mu 0 4 10 11 12 13
		f 4 34 3 -36 -33
		mu 0 4 11 14 15 12
		f 4 36 60 -49 -332
		mu 0 4 36 38 39 37
		f 4 -61 37 61 -50
		mu 0 4 39 38 188 126
		f 4 -62 38 332 -51
		mu 0 4 126 188 189 129
		f 4 39 62 -52 -333
		mu 0 4 26 20 23 27
		f 4 40 63 -53 -63
		mu 0 4 20 21 22 23
		f 4 41 64 -54 -64
		mu 0 4 21 24 25 22
		f 4 42 65 -55 -65
		mu 0 4 24 28 29 25
		f 4 43 66 -56 -66
		mu 0 4 28 190 131 29
		f 4 44 67 -57 -67
		mu 0 4 190 34 35 131
		f 4 45 68 -58 -68
		mu 0 4 34 31 30 35
		f 4 -69 46 69 -59
		mu 0 4 30 31 32 33
		f 4 -70 47 331 -60
		mu 0 4 33 32 36 37
		f 4 59 71 -73 -71
		mu 0 4 33 37 248 123
		f 4 48 73 -75 -72
		mu 0 4 37 39 247 122
		f 4 49 75 -77 -74
		mu 0 4 39 126 246 124
		f 4 50 77 -79 -76
		mu 0 4 126 129 238 127
		f 4 51 79 -81 -78
		mu 0 4 27 23 245 130
		f 4 52 81 -83 -80
		mu 0 4 23 22 244 133
		f 4 53 83 -85 -82
		mu 0 4 22 25 243 135
		f 4 54 85 -87 -84
		mu 0 4 25 29 242 136
		f 4 55 87 -89 -86
		mu 0 4 29 131 241 134
		f 4 56 89 -91 -88
		mu 0 4 131 35 240 132
		f 4 57 91 -93 -90
		mu 0 4 35 30 239 128
		f 4 58 70 -94 -92
		mu 0 4 30 33 249 125
		f 4 96 100 -98 -100
		mu 0 4 43 97 191 192
		f 4 101 98 305 99
		mu 0 4 40 41 42 43
		f 4 104 111 -106 -111
		mu 0 4 193 194 45 48
		f 4 105 113 -104 -113
		mu 0 4 48 45 44 49
		f 4 -114 -112 -110 -108
		mu 0 4 44 45 46 47
		f 4 112 106 108 110
		mu 0 4 48 49 50 51
		f 4 115 122 -117 -122
		mu 0 4 237 212 138 137
		f 4 116 124 -115 -124
		mu 0 4 137 138 139 140
		f 4 -125 -123 -121 -119
		mu 0 4 139 138 214 215
		f 4 123 117 119 121
		mu 0 4 137 140 213 211
		f 4 126 133 -128 -133
		mu 0 4 216 217 142 141
		f 4 127 135 -126 -135
		mu 0 4 141 142 143 144
		f 4 -136 -134 -132 -130
		mu 0 4 143 142 235 218
		f 4 134 128 130 132
		mu 0 4 141 144 219 220
		f 4 137 144 -139 -144
		mu 0 4 52 53 54 55
		f 4 138 146 -137 -146
		mu 0 4 55 54 145 146
		f 4 -147 -145 -143 -141
		mu 0 4 145 54 195 196
		f 4 145 139 141 143
		mu 0 4 55 146 197 198
		f 4 148 155 -150 -155
		mu 0 4 234 222 148 147
		f 4 149 157 -148 -157
		mu 0 4 147 148 149 150
		f 4 -158 -156 -154 -152
		mu 0 4 149 148 224 225
		f 4 156 150 152 154
		mu 0 4 147 150 223 221
		f 4 159 166 -161 -166
		mu 0 4 226 227 152 151
		f 4 160 168 -159 -168
		mu 0 4 151 152 153 154
		f 4 -169 -167 -165 -163
		mu 0 4 153 152 236 228
		f 4 167 161 163 165
		mu 0 4 151 154 229 230
		f 4 169 174 -171 -174
		mu 0 4 63 159 199 200
		f 3 181 184 -172
		mu 0 3 256 252 253
		f 4 171 178 -173 -178
		mu 0 4 201 202 162 62
		f 3 187 249 254
		mu 0 3 159 160 161
		f 4 -249 322 -177 -175
		mu 0 4 56 233 58 59
		f 4 179 173 175 177
		mu 0 4 62 63 64 65
		f 3 183 -182 -176
		mu 0 3 254 251 155
		f 3 170 -183 -184
		mu 0 3 157 255 250
		f 3 251 257 176
		mu 0 3 58 158 59
		f 3 172 -187 188
		mu 0 3 62 162 160
		f 3 185 -188 -170
		mu 0 3 63 160 159
		f 3 -189 -186 -180
		mu 0 3 62 160 63
		f 4 189 214 -202 -214
		mu 0 4 80 84 85 81
		f 4 190 215 -203 -215
		mu 0 4 203 204 205 206
		f 4 191 216 -204 -216
		mu 0 4 204 72 73 205
		f 4 192 217 -205 -217
		mu 0 4 72 66 69 73
		f 4 193 218 -206 -218
		mu 0 4 66 67 68 69
		f 4 194 219 -207 -219
		mu 0 4 67 70 71 68
		f 4 195 220 -208 -220
		mu 0 4 70 74 75 71
		f 4 196 221 -209 -221
		mu 0 4 74 173 207 75
		f 4 197 222 -210 -222
		mu 0 4 173 82 83 207
		f 4 198 223 -211 -223
		mu 0 4 82 76 79 83
		f 4 199 224 -212 -224
		mu 0 4 76 77 78 79
		f 4 200 213 -213 -225
		mu 0 4 77 80 81 78
		f 3 -190 -226 226
		mu 0 3 164 165 166
		f 3 -191 -227 227
		mu 0 3 168 164 166
		f 3 -192 -228 228
		mu 0 3 170 168 166
		f 3 -193 -229 229
		mu 0 3 172 170 166
		f 3 -194 -230 230
		mu 0 3 174 172 166
		f 3 -195 -231 231
		mu 0 3 175 174 166
		f 3 -196 -232 232
		mu 0 3 74 175 166
		f 3 -197 -233 233
		mu 0 3 173 74 166
		f 3 -198 -234 234
		mu 0 3 171 173 166
		f 3 -199 -235 235
		mu 0 3 169 171 166
		f 3 -200 -236 236
		mu 0 3 167 169 166
		f 3 -201 -237 225
		mu 0 3 165 167 166
		f 4 238 245 -240 -245
		mu 0 4 208 209 87 90
		f 4 239 247 -238 -247
		mu 0 4 90 87 86 91
		f 4 -248 -246 -244 -242
		mu 0 4 86 87 88 89
		f 4 246 240 242 244
		mu 0 4 90 91 92 93
		f 3 253 -250 186
		mu 0 3 162 267 160
		f 3 256 -252 250
		mu 0 3 61 158 232
		f 3 -253 -254 180
		mu 0 3 163 267 162
		f 3 -255 252 248
		mu 0 3 159 161 231
		f 3 -185 -256 -257
		mu 0 3 61 156 158
		f 3 -258 255 182
		mu 0 3 59 158 156
		f 3 95 -281 325
		mu 0 3 42 261 104
		f 3 94 -280 324
		mu 0 3 210 114 262
		f 3 334 -265 -282
		mu 0 3 117 120 258
		f 4 265 -103 -101 -259
		mu 0 4 265 266 96 97
		f 4 275 272 273 274
		mu 0 4 177 178 179 99
		f 3 260 282 280
		mu 0 3 111 108 260
		f 3 323 -266 302
		mu 0 3 98 95 94
		f 4 -277 -275 277 -269
		mu 0 4 264 177 99 98
		f 3 -278 303 -270
		mu 0 3 98 99 100
		f 3 -279 333 -271
		mu 0 3 100 179 180
		f 3 318 313 289
		mu 0 3 101 102 103
		f 4 294 -292 309 -288
		mu 0 4 118 116 110 107
		f 4 -314 316 319 288
		mu 0 4 103 102 106 107
		f 3 317 312 296
		mu 0 3 118 121 119
		f 4 -283 -296 -285 -284
		mu 0 4 260 108 109 105
		f 4 -297 262 -293 -295
		mu 0 4 118 119 117 116
		f 3 -298 276 267
		mu 0 3 258 177 264
		f 3 -299 -276 297
		mu 0 3 258 178 177
		f 3 -300 271 298
		mu 0 3 258 180 178
		f 3 264 -301 299
		mu 0 3 258 120 180
		f 4 300 263 -302 270
		mu 0 4 180 120 95 100
		f 3 -303 259 268
		mu 0 3 98 94 264
		f 3 -304 -274 278
		mu 0 3 100 99 179
		f 3 295 330 -305
		mu 0 3 109 108 112
		f 3 321 320 -316
		mu 0 3 118 112 263
		f 3 -308 308 327
		mu 0 3 259 110 258
		f 4 -309 291 292 281
		mu 0 4 258 110 116 117
		f 3 -310 -291 -289
		mu 0 3 107 110 103
		f 4 -311 290 307 306
		mu 0 4 260 103 110 259
		f 3 -312 -290 310
		mu 0 3 260 101 103
		f 4 286 314 284 285
		mu 0 4 118 106 105 109
		f 3 -317 -294 -315
		mu 0 3 106 181 105
		f 3 -318 315 261
		mu 0 3 121 118 263
		f 4 283 293 -319 311
		mu 0 4 260 105 102 101
		f 3 -320 -287 287
		mu 0 3 107 106 118
		f 3 304 -322 -286
		mu 0 3 109 112 118
		f 4 -323 -181 -179 -251
		mu 0 4 232 57 60 61
		f 3 301 -324 269
		mu 0 3 100 95 98
		f 4 -325 -261 -96 -99
		mu 0 4 210 262 261 42
		f 3 -326 -307 328
		mu 0 3 42 104 113
		f 3 -327 -268 329
		mu 0 3 43 115 176
		f 4 -329 -328 326 -306
		mu 0 4 42 113 115 43
		f 4 -330 -260 258 -97
		mu 0 4 43 176 265 97
		f 3 -331 279 -321
		mu 0 3 112 108 263
		f 3 -334 -273 -272
		mu 0 3 180 179 178
		f 3 266 -335 -263
		mu 0 3 257 120 117;
	setAttr ".cd" -type "dataPolyComponent" Index_Data Edge 0 ;
	setAttr ".cvd" -type "dataPolyComponent" Index_Data Vertex 0 ;
	setAttr ".pd[0]" -type "dataPolyComponent" Index_Data UV 0 ;
	setAttr ".hfd" -type "dataPolyComponent" Index_Data Face 0 ;
createNode lightLinker -s -n "lightLinker1";
	rename -uid "41853BEA-4524-94C1-0645-40A13A12A0EC";
	setAttr -s 4 ".lnk";
	setAttr -s 4 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "AA18B1D7-4DBB-65B7-916E-F698D67F54B2";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "043EFD2A-4EB8-FCA0-4364-11AD5F277A23";
createNode displayLayerManager -n "layerManager";
	rename -uid "7F525EFD-4C5B-28C0-4D2A-A5A1B928616B";
createNode displayLayer -n "defaultLayer";
	rename -uid "45D86949-4101-3F2D-C3A0-C8B00BB0C9F2";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "C581BF92-4D82-81D3-F0D1-5FA1E9382BA8";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "2BAB7981-4BD2-8476-69FE-50B8CB25C14A";
	setAttr ".g" yes;
createNode file -n "groundplane";
	rename -uid "E827D49E-4B61-5242-F115-5087B7D2A5A2";
	setAttr ".ftn" -type "string" "C:/Users/jarne/Documents/DAE/sem_2/3D/5props_Ass/parasol/sourceimages/tex_template.jpg";
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
		+ "            -strokes 1\n            -motionTrails 1\n            -clipGhosts 1\n            -greasePencils 1\n            -shadows 0\n            -captureSequenceNumber -1\n            -width 1119\n            -height 734\n            -sceneRenderFilter 0\n            $editorName;\n        modelEditor -e -viewSelected 0 $editorName;\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextPanel \"outlinerPanel\" (localizedPanelLabel(\"ToggledOutliner\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\toutlinerPanel -edit -l (localizedPanelLabel(\"ToggledOutliner\")) -mbv $menusOkayInPanels  $panelName;\n\t\t$editorName = $panelName;\n        outlinerEditor -e \n            -docTag \"isolOutln_fromSeln\" \n            -showShapes 0\n            -showAssignedMaterials 0\n            -showTimeEditor 1\n            -showReferenceNodes 1\n            -showReferenceMembers 1\n            -showAttributes 0\n            -showConnected 0\n            -showAnimCurvesOnly 0\n            -showMuteInfo 0\n"
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
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1119\\n    -height 734\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Persp View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -cam `findStartUpCamera persp` \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 1\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 16384\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1119\\n    -height 734\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 5 -size 100 -divisions 1 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "B974DBF3-4293-F109-E37E-96A1B02E6C8A";
	setAttr ".b" -type "string" "playbackOptions -min 1 -max 120 -ast 1 -aet 200 ";
	setAttr ".st" 6;
createNode groupId -n "groupId2";
	rename -uid "DA0320F8-4503-41FC-3EAC-7E84AAEEA9B4";
	setAttr ".ihi" 0;
createNode groupId -n "groupId3";
	rename -uid "A999873B-443A-F83C-AFCA-41B7253E203D";
	setAttr ".ihi" 0;
createNode shadingEngine -n "standardSurface1SG";
	rename -uid "E36E70DB-4101-7C78-9EBB-87A727C00688";
	setAttr ".ihi" 0;
	setAttr ".ro" yes;
createNode materialInfo -n "materialInfo4";
	rename -uid "20FA1839-407A-4CB8-A74F-5DB13A38B5D1";
createNode file -n "file1";
	rename -uid "34BA6A7D-475D-A62D-FD95-9B8C66F718D8";
	setAttr ".ftn" -type "string" "C:/Users/jarne/Documents/DAE/sem_2/3D/1GD22_WiemeJarne_Diorama/Prop_Parasol/sourceimages/T_Parasol_BC.png";
	setAttr ".cs" -type "string" "sRGB";
createNode place2dTexture -n "place2dTexture3";
	rename -uid "D8BDEEF5-434B-7B14-50E6-859CBE1B8483";
createNode nodeGraphEditorInfo -n "hyperShadePrimaryNodeEditorSavedTabsInfo";
	rename -uid "E9599374-47A1-9955-568C-88A8F0A9AD67";
	setAttr ".tgi[0].tn" -type "string" "Untitled_1";
	setAttr ".tgi[0].vl" -type "double2" -365.75763098001761 190.55787488578616 ;
	setAttr ".tgi[0].vh" -type "double2" 1021.1470758141025 1605.4551537436409 ;
	setAttr -s 4 ".tgi[0].ni";
	setAttr ".tgi[0].ni[0].x" -15.714285850524902;
	setAttr ".tgi[0].ni[0].y" 1235.7142333984375;
	setAttr ".tgi[0].ni[0].nvs" 1923;
	setAttr ".tgi[0].ni[1].x" 291.42855834960938;
	setAttr ".tgi[0].ni[1].y" 1257.142822265625;
	setAttr ".tgi[0].ni[1].nvs" 2387;
	setAttr ".tgi[0].ni[2].x" 640;
	setAttr ".tgi[0].ni[2].y" 1234.2857666015625;
	setAttr ".tgi[0].ni[2].nvs" 1923;
	setAttr ".tgi[0].ni[3].x" -322.85714721679688;
	setAttr ".tgi[0].ni[3].y" 1212.857177734375;
	setAttr ".tgi[0].ni[3].nvs" 1923;
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
	setAttr -s 4 ".st";
select -ne :renderGlobalsList1;
select -ne :defaultShaderList1;
	setAttr -s 6 ".s";
select -ne :postProcessList1;
	setAttr -s 2 ".p";
select -ne :defaultRenderUtilityList1;
	setAttr -s 2 ".u";
select -ne :defaultRenderingList1;
select -ne :lightList1;
select -ne :defaultTextureList1;
	setAttr -s 2 ".tx";
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
connectAttr "groupId2.id" "ParasolShape.iog.og[1].gid";
connectAttr "groupId3.id" "ParasolShape.iog.og[3].gid";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" "standardSurface1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "aiStandardSurface1SG.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" "standardSurface1SG.message" ":defaultLightSet.message";
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
connectAttr ":standardSurface1.oc" "standardSurface1SG.ss";
connectAttr "ParasolShape.iog" "standardSurface1SG.dsm" -na;
connectAttr "standardSurface1SG.msg" "materialInfo4.sg";
connectAttr ":standardSurface1.msg" "materialInfo4.m";
connectAttr ":standardSurface1.msg" "materialInfo4.t" -na;
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
connectAttr "groundplane.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[0].dn"
		;
connectAttr "groundplane_shader.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[1].dn"
		;
connectAttr "aiStandardSurface1SG.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[2].dn"
		;
connectAttr "place2dTexture1.msg" "hyperShadePrimaryNodeEditorSavedTabsInfo.tgi[0].ni[3].dn"
		;
connectAttr "aiStandardSurface1SG.pa" ":renderPartition.st" -na;
connectAttr "standardSurface1SG.pa" ":renderPartition.st" -na;
connectAttr "groundplane_shader.msg" ":defaultShaderList1.s" -na;
connectAttr "place2dTexture1.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "place2dTexture3.msg" ":defaultRenderUtilityList1.u" -na;
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "Skydome_lShape.ltd" ":lightList1.l" -na;
connectAttr "groundplane.msg" ":defaultTextureList1.tx" -na;
connectAttr "file1.msg" ":defaultTextureList1.tx" -na;
connectAttr "file1.oc" ":standardSurface1.bc";
connectAttr "Skydome_l.iog" ":defaultLightSet.dsm" -na;
connectAttr "groupId2.msg" ":defaultLastHiddenSet.gn" -na;
connectAttr "groupId3.msg" ":defaultLastHiddenSet.gn" -na;
connectAttr "ParasolShape.iog.og[1]" ":defaultLastHiddenSet.dsm" -na;
connectAttr "ParasolShape.iog.og[3]" ":defaultLastHiddenSet.dsm" -na;
// End of 1GD22_WiemeJarne_Parasol.ma
