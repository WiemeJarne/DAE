//Maya ASCII 2022 scene
//Name: Chess_King.ma
//Last modified: Fri, Mar 04, 2022 10:30:30 AM
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
fileInfo "UUID" "60E33339-4820-8FD3-C3B3-66928A06B404";
createNode transform -s -n "persp";
	rename -uid "8BA0B6A4-4220-C943-0EAF-6BB6F8CA93E6";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 66.879595814435305 74.112072001938301 -55.20282041541806 ;
	setAttr ".r" -type "double3" -24.938352729616621 122.19999999998853 0 ;
createNode camera -s -n "perspShape" -p "persp";
	rename -uid "57638C70-4E72-AB4C-C5E9-04A29E3109A1";
	setAttr -k off ".v" no;
	setAttr ".fl" 34.999999999999993;
	setAttr ".coi" 77.178901828227623;
	setAttr ".imn" -type "string" "persp";
	setAttr ".den" -type "string" "persp_depth";
	setAttr ".man" -type "string" "persp_mask";
	setAttr ".hc" -type "string" "viewSet -p %camera";
	setAttr ".ai_translator" -type "string" "perspective";
createNode transform -s -n "top";
	rename -uid "5F4A27E1-4A71-3C9D-AC1C-C282BA7BDC61";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 1000.1 0 ;
	setAttr ".r" -type "double3" -90 0 0 ;
createNode camera -s -n "topShape" -p "top";
	rename -uid "B7D94B96-4CAF-DA24-8ADC-D98392136A11";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 45.090612438995443;
	setAttr ".imn" -type "string" "top";
	setAttr ".den" -type "string" "top_depth";
	setAttr ".man" -type "string" "top_mask";
	setAttr ".hc" -type "string" "viewSet -t %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -s -n "front";
	rename -uid "107BA8B3-4E4B-17A0-1455-5FA66CEFF38A";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 0 0 1000.1 ;
createNode camera -s -n "frontShape" -p "front";
	rename -uid "63D6DEC3-41AD-DD1A-5A2F-68A666E006A4";
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
	rename -uid "53991F32-4C11-3C40-2165-A79FDDDC9D88";
	setAttr ".v" no;
	setAttr ".t" -type "double3" 1000.1 50.248329947092451 -1.5902979430907216 ;
	setAttr ".r" -type "double3" 0 90 0 ;
createNode camera -s -n "sideShape" -p "side";
	rename -uid "2B3C879F-4746-C854-3E0E-528D146820F9";
	setAttr -k off ".v" no;
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 111.82396359970041;
	setAttr ".imn" -type "string" "side";
	setAttr ".den" -type "string" "side_depth";
	setAttr ".man" -type "string" "side_mask";
	setAttr ".hc" -type "string" "viewSet -s %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "left";
	rename -uid "3FCB24A2-489A-F455-D1EE-E3A98F9A29B9";
	setAttr ".t" -type "double3" -1000.1 5.8232775670781258 -1.0716565880180982 ;
	setAttr ".r" -type "double3" 0 -90 0 ;
createNode camera -n "leftShape" -p "left";
	rename -uid "D985F442-4C5B-F8A2-16CA-DC9703D89500";
	setAttr -k off ".v";
	setAttr ".rnd" no;
	setAttr ".coi" 1000.1;
	setAttr ".ow" 51.658657783370884;
	setAttr ".imn" -type "string" "left1";
	setAttr ".den" -type "string" "left1_depth";
	setAttr ".man" -type "string" "left1_mask";
	setAttr ".hc" -type "string" "viewSet -ls %camera";
	setAttr ".o" yes;
	setAttr ".ai_translator" -type "string" "orthographic";
createNode transform -n "imagePlane1";
	rename -uid "5FB3E256-4504-9733-874B-1A9127241662";
	setAttr ".t" -type "double3" -995.1 37.569812643731986 22.34756096911644 ;
	setAttr ".r" -type "double3" 0 -90 0 ;
	setAttr ".s" -type "double3" 12.140286901316395 12.140286901316395 1.0729701239329466 ;
createNode imagePlane -n "imagePlaneShape1" -p "imagePlane1";
	rename -uid "09661619-4906-9DDB-BE65-35A9F7F50E81";
	setAttr -k off ".v";
	setAttr ".fc" 98;
	setAttr ".imn" -type "string" "C:/Users/Jarne/Downloads/ChessKing.jpg";
	setAttr ".cov" -type "short2" 800 800 ;
	setAttr ".ag" 0.12987012999108086;
	setAttr ".dlc" no;
	setAttr ".w" 8;
	setAttr ".h" 8;
	setAttr ".cs" -type "string" "sRGB";
createNode transform -n "curve1";
	rename -uid "BA0C766E-43E8-6A8D-641F-018E43BA744B";
createNode nurbsCurve -n "curveShape1" -p "curve1";
	rename -uid "60B1C651-416A-A901-A544-97A36F1237CF";
	setAttr -k off ".v";
	setAttr ".cc" -type "nurbsCurve" 
		3 49 0 no 3
		54 0 0 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
		 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 49 49
		52
		0 -2.152395183900917 -0.55212050313797245
		0 -2.0277969194855396 -3.1800364956524252
		0 -1.7786003906547718 -8.4358684806812896
		0 -1.4981465969447574 -14.692476351584018
		0 3.9918847431237094 -13.486361833662491
		0 4.8576580054133363 -12.054212026461729
		0 6.1143172535684691 -13.077998383963356
		0 7.744905467650895 -12.564430878510553
		0 9.6383199573318841 -11.982843444378746
		0 11.718571484995174 -11.061261465105334
		0 11.176577492673067 -10.492963532492704
		0 16.100515239375092 -8.3141669172989943
		0 16.828968476216673 -7.9252247208911557
		0 18.126287363658182 -7.8982909004314701
		0 19.194200032057239 -7.8576113590162109
		0 21.685585981090117 -8.0472633513903471
		0 19.249842054904192 -6.791977887797251
		0 27.038788852617621 -5.1751833544968946
		0 26.798668352281084 -4.2999344311321543
		0 32.86677235050513 -4.5815113610701204
		0 35.702328520402247 -4.8678095699804
		0 39.248924141753982 -3.4410397085081388
		0 38.885053502336866 -4.562964622879468
		0 39.480725579979477 -7.9503192294717211
		0 40.148693078775366 -8.8623298631277372
		0 42.254721353785058 -8.8125741598280474
		0 42.835067373926179 -8.0995863565618524
		0 42.706511296231184 -6.7024370265423583
		0 44.25246070170283 -7.0930948052267242
		0 45.182860605026249 -6.9276130390515158
		0 45.28888192226816 -6.1241682809923548
		0 45.546467875632565 -4.6672157960765803
		0 46.559530901942971 -4.3128290711266128
		0 47.623263196913982 -5.575257362070122
		0 49.878269470723602 -5.7161442260962492
		0 48.929581646678344 -3.8901684901816851
		0 54.230825881570098 -4.6049001848945768
		0 58.692960279480673 -6.2587343130045463
		0 59.724244926000942 -6.9890216025114693
		0 62.421469631244022 -8.3249656821714257
		0 63.497854959866629 -9.2365435068228692
		0 64.555444449636994 -9.0905014212864153
		0 65.69698557554176 -8.7630919323720935
		0 65.446801938319282 -7.5319868111419384
		0 65.843352407172276 -7.4102464588344681
		0 66.119405284011719 -5.904170796601985
		0 66.768071456784426 -6.1392864395394033
		0 67.121496103140544 -4.5554714009244943
		0 67.208559494492022 -4.2073315194944927
		0 67.581595367269784 -2.8848498231072237
		0 67.245266835277732 -0.91175258411748872
		0 67.077102569281706 0.074796035377378431
		;
createNode transform -n "revolvedSurface1";
	rename -uid "7766B44D-4E11-8A19-1827-459EDB4FCC69";
createNode mesh -n "revolvedSurfaceShape1" -p "revolvedSurface1";
	rename -uid "0D535068-4E26-A8E4-1025-9AB1749B0F60";
	setAttr -k off ".v";
	setAttr ".vir" yes;
	setAttr ".vif" yes;
	setAttr ".pv" -type "double2" 0.93841969966888428 0.5 ;
	setAttr ".uvst[0].uvsn" -type "string" "map1";
	setAttr ".cuvs" -type "string" "map1";
	setAttr ".dcc" -type "string" "Ambient+Diffuse";
	setAttr ".covm[0]"  0 1 1;
	setAttr ".cdvm[0]"  0 1 1;
	setAttr ".ai_translator" -type "string" "polymesh";
createNode lightLinker -s -n "lightLinker1";
	rename -uid "F24E2390-4090-5028-A858-CBBED478522C";
	setAttr -s 2 ".lnk";
	setAttr -s 2 ".slnk";
createNode shapeEditorManager -n "shapeEditorManager";
	rename -uid "CB522897-41BD-8B21-6348-0CA24AFB29B5";
createNode poseInterpolatorManager -n "poseInterpolatorManager";
	rename -uid "CAF88A06-48DA-505F-DF14-9EB7CADE1A84";
createNode displayLayerManager -n "layerManager";
	rename -uid "B3496B59-4C21-5B31-8FFD-5ABE227557A1";
createNode displayLayer -n "defaultLayer";
	rename -uid "9E1EAB86-4C04-EEED-BBE9-FC8B319B23EE";
createNode renderLayerManager -n "renderLayerManager";
	rename -uid "896BFEF3-4FD5-48E6-6FE1-65AD2ABA20FA";
createNode renderLayer -n "defaultRenderLayer";
	rename -uid "5373FFB5-45FF-670E-A506-4A9BAE6E2255";
	setAttr ".g" yes;
createNode revolve -n "revolve1";
	rename -uid "441C6534-4AEB-1062-C135-7BBD30727C03";
	setAttr ".ax" -type "double3" 0 1 0 ;
createNode nurbsTessellate -n "nurbsTessellate1";
	rename -uid "5A216273-40FF-4FA5-F3AE-D78FC7ECB12B";
	setAttr ".f" 0;
	setAttr ".pt" 1;
	setAttr ".pc" 250;
	setAttr ".chr" 0.9;
	setAttr ".ut" 1;
	setAttr ".vt" 1;
	setAttr ".ucr" no;
	setAttr ".cht" 0.2;
createNode polyMergeVert -n "polyMergeVert1";
	rename -uid "CF4B5220-4E49-75C1-DE79-18A909021BE6";
	setAttr ".ics" -type "componentList" 12 "vtx[0]" "vtx[4]" "vtx[8]" "vtx[12]" "vtx[16]" "vtx[30]" "vtx[33]" "vtx[78]" "vtx[81]" "vtx[84]" "vtx[96]" "vtx[99]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".d" 1;
	setAttr ".am" yes;
createNode polyTweak -n "polyTweak1";
	rename -uid "C272B44E-40AF-18AD-4175-718BEBA90AA6";
	setAttr ".uopa" yes;
	setAttr -s 52 ".tk";
	setAttr ".tk[9]" -type "float3" -9.1420617e-17 0.40771079 -1.4703041 ;
	setAttr ".tk[10]" -type "float3" 1.4703041 0.40771079 -2.3764385e-16 ;
	setAttr ".tk[11]" -type "float3" 0.73455191 0.40771079 -1.2721301 ;
	setAttr ".tk[13]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[14]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[15]" -type "float3" 1.2721301 0.40771079 -0.73455191 ;
	setAttr ".tk[17]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[18]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[20]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[21]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[22]" -type "float3" 2.2546657e-17 0 0.43244249 ;
	setAttr ".tk[23]" -type "float3" -0.21604477 0 0.3741557 ;
	setAttr ".tk[24]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[25]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[27]" -type "float3" -0.3741557 0 0.21604477 ;
	setAttr ".tk[28]" -type "float3" -0.43244249 0 7.7690074e-17 ;
	setAttr ".tk[29]" -type "float3" 1.578231e-15 0.40771079 1.4703041 ;
	setAttr ".tk[31]" -type "float3" 1.2721301 0.40771079 0.73455191 ;
	setAttr ".tk[32]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[34]" -type "float3" 0.73455191 0.40771079 1.2721301 ;
	setAttr ".tk[35]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[36]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[38]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[39]" -type "float3" -0.3741557 0 -0.21604477 ;
	setAttr ".tk[40]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[41]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[43]" -type "float3" -0.21604477 0 -0.3741557 ;
	setAttr ".tk[44]" -type "float3" -4.7365611e-16 0 -0.43244249 ;
	setAttr ".tk[80]" -type "float3" -1.4703041 0.40771079 3.1869361e-15 ;
	setAttr ".tk[82]" -type "float3" -0.73455191 0.40771079 1.2721301 ;
	setAttr ".tk[83]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[85]" -type "float3" -1.2721301 0.40771079 0.73455191 ;
	setAttr ".tk[86]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[87]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[89]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[90]" -type "float3" 0.21604477 0 -0.3741557 ;
	setAttr ".tk[91]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[92]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[94]" -type "float3" 0.3741557 0 -0.21604477 ;
	setAttr ".tk[95]" -type "float3" 0.43244249 0 -9.3228131e-16 ;
	setAttr ".tk[97]" -type "float3" -1.2721301 0.40771079 -0.73455191 ;
	setAttr ".tk[98]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[100]" -type "float3" -0.73455191 0.40771079 -1.2721301 ;
	setAttr ".tk[101]" -type "float3" 0 0.65233725 0 ;
	setAttr ".tk[103]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[104]" -type "float3" 0.3741557 0 0.21604477 ;
	setAttr ".tk[105]" -type "float3" 0 1.3046747 0 ;
	setAttr ".tk[107]" -type "float3" 0.21604477 0 0.3741557 ;
createNode polyMergeVert -n "polyMergeVert2";
	rename -uid "418FBE85-4849-A4EA-806E-18AD34AA23C1";
	setAttr ".ics" -type "componentList" 12 "vtx[1]" "vtx[122]" "vtx[158]" "vtx[167]" "vtx[174]" "vtx[183]" "vtx[188]" "vtx[216]" "vtx[223]" "vtx[228]" "vtx[235]" "vtx[239]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".d" 1;
	setAttr ".am" yes;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_105__pntx";
	rename -uid "2C34A670-4E47-E802-225B-64BD2126BA33";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_105__pnty";
	rename -uid "7A632D6C-4823-8207-EE3A-A8BEAFB8493F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_105__pntz";
	rename -uid "A404EB9C-4E59-D32F-FA79-9D9214A4FC1D";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_107__pntx";
	rename -uid "C9C0C646-4245-1245-1635-C485E6D4C447";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_107__pnty";
	rename -uid "5F851CC7-4199-2AC9-B378-E19B3343C3B4";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_107__pntz";
	rename -uid "0599A578-45B1-13AE-B253-ECA922288911";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_108__pntx";
	rename -uid "500111E2-4AA0-C54F-96F5-7A9315AA968A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_108__pnty";
	rename -uid "3C33E932-41D8-5A6A-127E-58A4EDA62DD2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_108__pntz";
	rename -uid "7CD33C6C-4E9E-FF2D-C670-F08668E5CE3B";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_117__pntx";
	rename -uid "95A0BB16-4CA6-571F-0CC0-7D8DB99B2632";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_117__pnty";
	rename -uid "C2F71367-41D9-DB2A-5757-97BE0A710D94";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_117__pntz";
	rename -uid "EBBD7274-4F91-2F1C-4FEC-3FA0AD616B1A";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_119__pntx";
	rename -uid "76D7372E-47A3-4625-EAB9-41932A570E94";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_119__pnty";
	rename -uid "4DC21B9B-4485-AC78-2E3D-AAB8DA066C56";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_119__pntz";
	rename -uid "3457740F-470A-EF82-7793-8B91C13E8B31";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_49__pntx";
	rename -uid "C86623DE-40C1-1FB7-C105-F8AA9071F145";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_49__pnty";
	rename -uid "92844557-4DB1-4722-8102-7BA337A5D0F2";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_49__pntz";
	rename -uid "26B5DB0B-4D0E-794B-C346-479BE77C4CA0";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_50__pntx";
	rename -uid "9FBBD2C1-45FF-4982-E45F-F89037DD60AD";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_50__pnty";
	rename -uid "7EFF1852-44D3-CCDE-8DA1-1E9C74506684";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_50__pntz";
	rename -uid "C7270867-4B7B-A546-67E7-D1AD05583FDE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_53__pntx";
	rename -uid "CC174386-4F4C-B6C0-9A9B-56BFB906D578";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_53__pnty";
	rename -uid "C0814E73-4F68-1235-2705-9EB7B9814533";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_53__pntz";
	rename -uid "D3845A26-4BD8-3301-6C1A-099F9BFC2029";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_54__pntx";
	rename -uid "6E24F80B-41F6-709F-163F-4792BEDF80C1";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_54__pnty";
	rename -uid "F46EFAA0-45E5-57A3-5DAB-8F902E9EFDAE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_54__pntz";
	rename -uid "8724FD36-4478-078F-C8F8-2B8A59B5C868";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_65__pntx";
	rename -uid "0FBC9375-462F-152B-1B24-F994276AD17F";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_65__pnty";
	rename -uid "A38924DB-49E3-9AD8-7763-FAB2DC599281";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_65__pntz";
	rename -uid "9978EACA-4199-12F9-C9BE-1493FEAF5480";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_67__pntx";
	rename -uid "E6ACEBC2-4C5A-16F9-C5BC-BBBA613D75CB";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_67__pnty";
	rename -uid "3EB2BA53-4C13-7FB6-9A29-1688424D9A44";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_67__pntz";
	rename -uid "F07B9921-49DB-75A0-7D09-0B904B9493FE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_68__pntx";
	rename -uid "763C4D54-40B5-D731-E982-5AA1D35680B7";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_68__pnty";
	rename -uid "5D49D3EF-415E-2ED6-4063-B2B762B26EEE";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 -2.1282014846801758;
createNode animCurveTL -n "revolvedSurfaceShape1_pnts_68__pntz";
	rename -uid "18336EF9-4CE1-9261-2A8E-4782C6435299";
	setAttr ".tan" 18;
	setAttr ".wgt" no;
	setAttr ".ktv[0]"  1 0;
createNode polyDelEdge -n "polyDelEdge1";
	rename -uid "728F0918-49CC-048F-EBD5-13A522CE22B6";
	setAttr ".ics" -type "componentList" 12 "e[21]" "e[26]" "e[30]" "e[51]" "e[56]" "e[59]" "e[146]" "e[149]" "e[152]" "e[169]" "e[174]" "e[177]";
	setAttr ".cv" yes;
createNode polyTweak -n "polyTweak2";
	rename -uid "E7E90BD4-4E2B-05C5-EE29-A6A979D61A1A";
	setAttr ".uopa" yes;
	setAttr -s 112 ".tk";
	setAttr ".tk[0]" -type "float3" 0.29778957 0.95252413 0 ;
	setAttr ".tk[4]" -type "float3" -4.7148481e-17 0 -0.8072263 ;
	setAttr ".tk[5]" -type "float3" 8.9383925e-16 0 0.8072263 ;
	setAttr ".tk[6]" -type "float3" 0.8072263 0 -1.0968284e-16 ;
	setAttr ".tk[15]" -type "float3" 0.40328339 0 -0.69842434 ;
	setAttr ".tk[22]" -type "float3" 0.69842434 0 -0.40328339 ;
	setAttr ".tk[31]" -type "float3" 0.69842434 0 0.40328339 ;
	setAttr ".tk[36]" -type "float3" 0.40328339 0 0.69842434 ;
	setAttr ".tk[40]" -type "float3" 3.2854552e-17 -1.060048 0.39015043 ;
	setAttr ".tk[41]" -type "float3" -0.39015043 -1.060048 6.6434369e-17 ;
	setAttr ".tk[42]" -type "float3" -0.19491574 -1.060048 0.3375639 ;
	setAttr ".tk[45]" -type "float3" -0.3375639 -1.060048 0.19491574 ;
	setAttr ".tk[58]" -type "float3" -4.095579e-16 -1.060048 -0.39015043 ;
	setAttr ".tk[59]" -type "float3" -0.3375639 -1.060048 -0.19491574 ;
	setAttr ".tk[61]" -type "float3" -0.19491574 -1.060048 -0.3375639 ;
	setAttr ".tk[72]" -type "float3" -0.8072263 0 1.7405311e-15 ;
	setAttr ".tk[79]" -type "float3" -0.40328339 0 0.69842434 ;
	setAttr ".tk[84]" -type "float3" -0.69842434 0 0.40328339 ;
	setAttr ".tk[91]" -type "float3" -0.69842434 0 -0.40328339 ;
	setAttr ".tk[95]" -type "float3" -0.40328339 0 -0.69842434 ;
	setAttr ".tk[98]" -type "float3" 0.39015043 -1.060048 -8.410187e-16 ;
	setAttr ".tk[99]" -type "float3" 0.19491574 -1.060048 -0.3375639 ;
	setAttr ".tk[101]" -type "float3" 0.3375639 -1.060048 -0.19491574 ;
	setAttr ".tk[112]" -type "float3" 0.3375639 -1.060048 0.19491574 ;
	setAttr ".tk[114]" -type "float3" 0.19491574 -1.060048 0.3375639 ;
	setAttr ".tk[122]" -type "float3" -9.3099125e-17 -5.7801838 -1.1895614 ;
	setAttr ".tk[123]" -type "float3" 1.2828838e-15 -5.7801838 1.1895614 ;
	setAttr ".tk[124]" -type "float3" 1.1895614 -5.7801838 -1.9312531e-16 ;
	setAttr ".tk[125]" -type "float3" -2.3034973e-17 0 -0.27867883 ;
	setAttr ".tk[126]" -type "float3" 0.27867883 0 -4.6876368e-17 ;
	setAttr ".tk[127]" -type "float3" 0.13922559 0 -0.24111727 ;
	setAttr ".tk[130]" -type "float3" 0.24111727 0 -0.13922559 ;
	setAttr ".tk[133]" -type "float3" 0.59429377 -5.7801838 -1.0292264 ;
	setAttr ".tk[134]" -type "float3" -1.0056602e-16 -1.4582123 -2.090091 ;
	setAttr ".tk[135]" -type "float3" 1.0441918 -1.4582123 -1.8083795 ;
	setAttr ".tk[136]" -type "float3" -2.103575e-16 -3.5075908 -2.9261265 ;
	setAttr ".tk[137]" -type "float3" 1.4618692 -3.5075908 -2.5317318 ;
	setAttr ".tk[138]" -type "float3" 2.090091 -1.4582123 -3.8939918e-16 ;
	setAttr ".tk[139]" -type "float3" 1.8083795 -1.4582123 -1.0441918 ;
	setAttr ".tk[140]" -type "float3" 1.0292264 -5.7801838 -0.59429377 ;
	setAttr ".tk[141]" -type "float3" 2.5317318 -3.5075908 -1.4618692 ;
	setAttr ".tk[142]" -type "float3" 2.9261265 -3.5075908 -5.2030772e-16 ;
	setAttr ".tk[143]" -type "float3" 2.966149e-16 0 0.27867883 ;
	setAttr ".tk[144]" -type "float3" 0.24111727 0 0.13922559 ;
	setAttr ".tk[146]" -type "float3" 0.13922559 0 0.24111727 ;
	setAttr ".tk[149]" -type "float3" 1.0292264 -5.7801838 0.59429377 ;
	setAttr ".tk[150]" -type "float3" 1.8083795 -1.4582123 1.0441918 ;
	setAttr ".tk[151]" -type "float3" 2.5317318 -3.5075908 1.4618692 ;
	setAttr ".tk[152]" -type "float3" 2.3028721e-15 -1.4582123 2.090091 ;
	setAttr ".tk[153]" -type "float3" 1.0441918 -1.4582123 1.8083795 ;
	setAttr ".tk[154]" -type "float3" 0.59429377 -5.7801838 1.0292264 ;
	setAttr ".tk[155]" -type "float3" 1.4618692 -3.5075908 2.5317318 ;
	setAttr ".tk[156]" -type "float3" 3.2620857e-15 -3.5075908 2.9261265 ;
	setAttr ".tk[157]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[158]" -type "float3" 0 0.47449297 0 ;
	setAttr ".tk[159]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[160]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[161]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[162]" -type "float3" 0 0.47449297 0 ;
	setAttr ".tk[163]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[164]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[173]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[174]" -type "float3" 0 0.47449297 0 ;
	setAttr ".tk[175]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[176]" -type "float3" 0 0.47449297 0 ;
	setAttr ".tk[177]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[178]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[185]" -type "float3" -1.1895614 -5.7801838 2.4726687e-15 ;
	setAttr ".tk[186]" -type "float3" -0.27867883 0 6.009082e-16 ;
	setAttr ".tk[187]" -type "float3" -0.13922559 0 0.24111727 ;
	setAttr ".tk[189]" -type "float3" -0.24111727 0 0.13922559 ;
	setAttr ".tk[192]" -type "float3" -0.59429377 -5.7801838 1.0292264 ;
	setAttr ".tk[193]" -type "float3" -1.0441918 -1.4582123 1.8083795 ;
	setAttr ".tk[194]" -type "float3" -1.4618692 -3.5075908 2.5317318 ;
	setAttr ".tk[195]" -type "float3" -2.090091 -1.4582123 4.5051789e-15 ;
	setAttr ".tk[196]" -type "float3" -1.8083795 -1.4582123 1.0441918 ;
	setAttr ".tk[197]" -type "float3" -1.0292264 -5.7801838 0.59429377 ;
	setAttr ".tk[198]" -type "float3" -2.5317318 -3.5075908 1.4618692 ;
	setAttr ".tk[199]" -type "float3" -2.9261265 -3.5075908 6.2436992e-15 ;
	setAttr ".tk[200]" -type "float3" -0.24111727 0 -0.13922559 ;
	setAttr ".tk[202]" -type "float3" -0.13922559 0 -0.24111727 ;
	setAttr ".tk[204]" -type "float3" -1.0292264 -5.7801838 -0.59429377 ;
	setAttr ".tk[205]" -type "float3" -1.8083795 -1.4582123 -1.0441918 ;
	setAttr ".tk[206]" -type "float3" -2.5317318 -3.5075908 -1.4618692 ;
	setAttr ".tk[207]" -type "float3" -1.0441918 -1.4582123 -1.8083795 ;
	setAttr ".tk[208]" -type "float3" -0.59429377 -5.7801838 -1.0292264 ;
	setAttr ".tk[209]" -type "float3" -1.4618692 -3.5075908 -2.5317318 ;
	setAttr ".tk[210]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[211]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[212]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[213]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[214]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[215]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[222]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[223]" -type "float3" 0 -5.1331477 0 ;
	setAttr ".tk[224]" -type "float3" 0 0.47449285 0 ;
	setAttr ".tk[225]" -type "float3" 0 -5.1331477 0 ;
createNode polySoftEdge -n "polySoftEdge1";
	rename -uid "196B38F2-4173-C4E2-561A-19B7AD36A661";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[13]" "e[17]" "e[29]" "e[40]" "e[51]" "e[60]" "e[123]" "e[128]" "e[138]" "e[147]" "e[157]" "e[165]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge2";
	rename -uid "FD44BC3C-408A-C247-E1B5-E88B86A1EC5E";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[232]" "e[237]" "e[241]" "e[262]" "e[267]" "e[270]" "e[352]" "e[355]" "e[358]" "e[375]" "e[380]" "e[383]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge3";
	rename -uid "0565EE9D-4AAF-8D3E-D939-68A7D0ACC65B";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 11 "e[222]" "e[226]" "e[245]" "e[257]" "e[273]" "e[283]" "e[344:345]" "e[361]" "e[371]" "e[385]" "e[394]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polyDelEdge -n "polyDelEdge2";
	rename -uid "5FE398DD-4F2F-93BB-C8D1-A7839BD59169";
	setAttr ".ics" -type "componentList" 12 "e[224]" "e[228]" "e[247]" "e[258]" "e[275]" "e[284]" "e[342]" "e[347]" "e[363]" "e[372]" "e[387]" "e[395]";
	setAttr ".cv" yes;
createNode polySoftEdge -n "polySoftEdge4";
	rename -uid "414F4EBC-4B1E-8593-4BE8-B784CAAAEF3C";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 9 "e[277]" "e[282]" "e[287]" "e[308:309]" "e[313]" "e[379:380]" "e[384]" "e[402:403]" "e[407]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge5";
	rename -uid "94CF70A8-4954-896B-8572-42B2509CFFAA";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 11 "e[11]" "e[15]" "e[27]" "e[39]" "e[49]" "e[59]" "e[125:126]" "e[136]" "e[146]" "e[155]" "e[164]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge6";
	rename -uid "253008E9-466B-BFB6-CEEE-3FBED8F06162";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[69]" "e[74]" "e[78]" "e[98]" "e[103]" "e[106]" "e[172]" "e[177]" "e[180]" "e[197]" "e[202]" "e[205]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge7";
	rename -uid "5473D882-40E8-3F8A-D737-CFB9D9F32B10";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 18 "e[19]" "e[21]" "e[24]" "e[31]" "e[37:38]" "e[44:45]" "e[47]" "e[53]" "e[57:58]" "e[130]" "e[132]" "e[134]" "e[139]" "e[144:145]" "e[150:151]" "e[153]" "e[158]" "e[162:163]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge8";
	rename -uid "36C5E532-467C-828B-29D9-72A331789728";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[69]" "e[74]" "e[78]" "e[98]" "e[103]" "e[106]" "e[172]" "e[177]" "e[180]" "e[197]" "e[202]" "e[205]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge9";
	rename -uid "B600E741-4CD2-EAAE-7289-068B80047ACE";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 9 "e[67]" "e[72]" "e[77]" "e[100:101]" "e[105]" "e[174:175]" "e[179]" "e[199:200]" "e[204]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge10";
	rename -uid "4EB9FB30-49FA-1E01-EACF-BCB59214F81D";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 8 "e[85]" "e[91:92]" "e[113]" "e[117:118]" "e[187]" "e[191:192]" "e[211]" "e[214:215]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge11";
	rename -uid "A163CA56-4F0F-4C40-B1E5-E481D7A6EC61";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[5]" "e[9]" "e[65]" "e[83]" "e[94]" "e[111]" "e[120]" "e[169]" "e[185]" "e[194]" "e[209]" "e[217]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge12";
	rename -uid "CD6BB8BC-4283-F7CF-C29F-AE87138715F9";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[3]" "e[7]" "e[63]" "e[81]" "e[93]" "e[109]" "e[119]" "e[167]" "e[183]" "e[193]" "e[207]" "e[216]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge13";
	rename -uid "E9D5ED89-4880-864E-A811-23A57FEAD698";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 10 "e[226]" "e[231]" "e[236]" "e[255:256]" "e[260]" "e[333]" "e[336]" "e[340]" "e[356:357]" "e[361]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge14";
	rename -uid "85AC06AD-45CF-E981-C82A-E2B38C7BFC45";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 8 "e[243]" "e[248:249]" "e[267]" "e[270:271]" "e[346]" "e[350:351]" "e[366]" "e[369:370]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge15";
	rename -uid "513EB37D-41ED-1B6E-9FBF-689DB1AE250D";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[279]" "e[284]" "e[288]" "e[306]" "e[311]" "e[314]" "e[377]" "e[382]" "e[385]" "e[400]" "e[405]" "e[408]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge16";
	rename -uid "E629A27C-4E5A-F69F-22F9-8C96BF46109F";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 11 "e[222]" "e[224]" "e[240]" "e[250]" "e[264]" "e[272]" "e[329:330]" "e[344]" "e[352]" "e[364]" "e[371]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge17";
	rename -uid "4F00F058-4E30-DB5B-FE5E-16A2A1A5C452";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 8 "e[294]" "e[300:301]" "e[320]" "e[324:325]" "e[391]" "e[395:396]" "e[413]" "e[416:417]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge18";
	rename -uid "B0C4B62A-41A7-D926-CA88-CE93896B0FE3";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 9 "e[277]" "e[282]" "e[287]" "e[308:309]" "e[313]" "e[379:380]" "e[384]" "e[402:403]" "e[407]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode polySoftEdge -n "polySoftEdge19";
	rename -uid "9C908F77-48E3-BCBE-8A22-D98F4130F719";
	setAttr ".uopa" yes;
	setAttr ".ics" -type "componentList" 12 "e[1]" "e[220]" "e[275]" "e[292]" "e[302]" "e[318]" "e[326]" "e[374]" "e[389]" "e[397]" "e[411]" "e[418]";
	setAttr ".ix" -type "matrix" 1 0 0 0 0 1 0 0 0 0 1 0 0 0 0 1;
	setAttr ".a" 0;
createNode script -n "uiConfigurationScriptNode";
	rename -uid "D86477E0-4DEE-AAA3-3DC5-0FBF3D4798A9";
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
		+ "            -wireframeOnShaded 0\n            -headsUpDisplay 1\n            -holdOuts 1\n            -selectionHiliteDisplay 1\n            -useDefaultMaterial 0\n            -bufferMode \"double\" \n            -twoSidedLighting 0\n            -backfaceCulling 0\n            -xray 0\n            -jointXray 0\n            -activeComponentsXray 0\n            -displayTextures 0\n            -smoothWireframe 0\n            -lineWidth 1\n            -textureAnisotropic 0\n            -textureHilight 1\n            -textureSampling 2\n            -textureDisplay \"modulate\" \n            -textureMaxSize 32768\n            -fogging 0\n            -fogSource \"fragment\" \n            -fogMode \"linear\" \n            -fogStart 0\n            -fogEnd 100\n            -fogDensity 0.1\n            -fogColor 0.5 0.5 0.5 1 \n            -depthOfFieldPreview 1\n            -maxConstantTransparency 1\n            -rendererName \"vp2Renderer\" \n            -objectFilterShowInHUD 1\n            -isFiltered 0\n            -colorResolution 256 256 \n            -bumpResolution 512 512 \n"
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
		+ "\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\t$panelName = `sceneUIReplacement -getNextScriptedPanel \"Stereo\" (localizedPanelLabel(\"Stereo\")) `;\n\tif (\"\" != $panelName) {\n\t\t$label = `panel -q -label $panelName`;\n\t\tscriptedPanel -edit -l (localizedPanelLabel(\"Stereo\")) -mbv $menusOkayInPanels  $panelName;\n{ string $editorName = ($panelName+\"Editor\");\n            stereoCameraView -e \n                -camera \"persp\" \n                -useInteractiveMode 0\n                -displayLights \"default\" \n                -displayAppearance \"smoothShaded\" \n                -activeOnly 0\n                -ignorePanZoom 0\n                -wireframeOnShaded 0\n                -headsUpDisplay 1\n                -holdOuts 1\n                -selectionHiliteDisplay 1\n                -useDefaultMaterial 0\n                -bufferMode \"double\" \n                -twoSidedLighting 0\n                -backfaceCulling 0\n                -xray 0\n                -jointXray 0\n                -activeComponentsXray 0\n                -displayTextures 0\n"
		+ "                -smoothWireframe 0\n                -lineWidth 1\n                -textureAnisotropic 0\n                -textureHilight 1\n                -textureSampling 2\n                -textureDisplay \"modulate\" \n                -textureMaxSize 32768\n                -fogging 0\n                -fogSource \"fragment\" \n                -fogMode \"linear\" \n                -fogStart 0\n                -fogEnd 100\n                -fogDensity 0.1\n                -fogColor 0.5 0.5 0.5 1 \n                -depthOfFieldPreview 1\n                -maxConstantTransparency 1\n                -objectFilterShowInHUD 1\n                -isFiltered 0\n                -colorResolution 4 4 \n                -bumpResolution 4 4 \n                -textureCompression 0\n                -transparencyAlgorithm \"frontAndBackCull\" \n                -transpInShadows 0\n                -cullingOverride \"none\" \n                -lowQualityLighting 0\n                -maximumNumHardwareLights 0\n                -occlusionCulling 0\n                -shadingModel 0\n"
		+ "                -useBaseRenderer 0\n                -useReducedRenderer 0\n                -smallObjectCulling 0\n                -smallObjectThreshold -1 \n                -interactiveDisableShadows 0\n                -interactiveBackFaceCull 0\n                -sortTransparent 1\n                -controllers 1\n                -nurbsCurves 1\n                -nurbsSurfaces 1\n                -polymeshes 1\n                -subdivSurfaces 1\n                -planes 1\n                -lights 1\n                -cameras 1\n                -controlVertices 1\n                -hulls 1\n                -grid 1\n                -imagePlane 1\n                -joints 1\n                -ikHandles 1\n                -deformers 1\n                -dynamics 1\n                -particleInstancers 1\n                -fluids 1\n                -hairSystems 1\n                -follicles 1\n                -nCloths 1\n                -nParticles 1\n                -nRigids 1\n                -dynamicConstraints 1\n                -locators 1\n                -manipulators 1\n"
		+ "                -pluginShapes 1\n                -dimensions 1\n                -handles 1\n                -pivots 1\n                -textures 1\n                -strokes 1\n                -motionTrails 1\n                -clipGhosts 1\n                -greasePencils 1\n                -shadows 0\n                -captureSequenceNumber -1\n                -width 0\n                -height 0\n                -sceneRenderFilter 0\n                -displayMode \"centerEye\" \n                -viewColor 0 0 0 1 \n                -useCustomBackground 1\n                $editorName;\n            stereoCameraView -e -viewSelected 0 $editorName;\n            stereoCameraView -e \n                -pluginObjects \"gpuCacheDisplayFilter\" 1 \n                $editorName; };\n\t\tif (!$useSceneConfig) {\n\t\t\tpanel -e -l $label $panelName;\n\t\t}\n\t}\n\n\n\tif ($useSceneConfig) {\n        string $configName = `getPanel -cwl (localizedPanelLabel(\"Current Layout\"))`;\n        if (\"\" != $configName) {\n\t\t\tpanelConfiguration -edit -label (localizedPanelLabel(\"Current Layout\")) \n"
		+ "\t\t\t\t-userCreated false\n\t\t\t\t-defaultImage \"vacantCell.xP:/\"\n\t\t\t\t-image \"\"\n\t\t\t\t-sc false\n\t\t\t\t-configString \"global string $gMainPane; paneLayout -e -cn \\\"single\\\" -ps 1 100 100 $gMainPane;\"\n\t\t\t\t-removeAllPanels\n\t\t\t\t-ap false\n\t\t\t\t\t(localizedPanelLabel(\"Side View\")) \n\t\t\t\t\t\"modelPanel\"\n"
		+ "\t\t\t\t\t\"$panelName = `modelPanel -unParent -l (localizedPanelLabel(\\\"Side View\\\")) -mbv $menusOkayInPanels `;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -camera \\\"persp\\\" \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1119\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t\t\"modelPanel -edit -l (localizedPanelLabel(\\\"Side View\\\")) -mbv $menusOkayInPanels  $panelName;\\n$editorName = $panelName;\\nmodelEditor -e \\n    -camera \\\"persp\\\" \\n    -useInteractiveMode 0\\n    -displayLights \\\"default\\\" \\n    -displayAppearance \\\"smoothShaded\\\" \\n    -activeOnly 0\\n    -ignorePanZoom 0\\n    -wireframeOnShaded 0\\n    -headsUpDisplay 1\\n    -holdOuts 1\\n    -selectionHiliteDisplay 1\\n    -useDefaultMaterial 0\\n    -bufferMode \\\"double\\\" \\n    -twoSidedLighting 0\\n    -backfaceCulling 0\\n    -xray 0\\n    -jointXray 0\\n    -activeComponentsXray 0\\n    -displayTextures 0\\n    -smoothWireframe 0\\n    -lineWidth 1\\n    -textureAnisotropic 0\\n    -textureHilight 1\\n    -textureSampling 2\\n    -textureDisplay \\\"modulate\\\" \\n    -textureMaxSize 32768\\n    -fogging 0\\n    -fogSource \\\"fragment\\\" \\n    -fogMode \\\"linear\\\" \\n    -fogStart 0\\n    -fogEnd 100\\n    -fogDensity 0.1\\n    -fogColor 0.5 0.5 0.5 1 \\n    -depthOfFieldPreview 1\\n    -maxConstantTransparency 1\\n    -rendererName \\\"vp2Renderer\\\" \\n    -objectFilterShowInHUD 1\\n    -isFiltered 0\\n    -colorResolution 256 256 \\n    -bumpResolution 512 512 \\n    -textureCompression 0\\n    -transparencyAlgorithm \\\"frontAndBackCull\\\" \\n    -transpInShadows 0\\n    -cullingOverride \\\"none\\\" \\n    -lowQualityLighting 0\\n    -maximumNumHardwareLights 1\\n    -occlusionCulling 0\\n    -shadingModel 0\\n    -useBaseRenderer 0\\n    -useReducedRenderer 0\\n    -smallObjectCulling 0\\n    -smallObjectThreshold -1 \\n    -interactiveDisableShadows 0\\n    -interactiveBackFaceCull 0\\n    -sortTransparent 1\\n    -controllers 1\\n    -nurbsCurves 1\\n    -nurbsSurfaces 1\\n    -polymeshes 1\\n    -subdivSurfaces 1\\n    -planes 1\\n    -lights 1\\n    -cameras 1\\n    -controlVertices 1\\n    -hulls 1\\n    -grid 1\\n    -imagePlane 1\\n    -joints 1\\n    -ikHandles 1\\n    -deformers 1\\n    -dynamics 1\\n    -particleInstancers 1\\n    -fluids 1\\n    -hairSystems 1\\n    -follicles 1\\n    -nCloths 1\\n    -nParticles 1\\n    -nRigids 1\\n    -dynamicConstraints 1\\n    -locators 1\\n    -manipulators 1\\n    -pluginShapes 1\\n    -dimensions 1\\n    -handles 1\\n    -pivots 1\\n    -textures 1\\n    -strokes 1\\n    -motionTrails 1\\n    -clipGhosts 1\\n    -greasePencils 1\\n    -shadows 0\\n    -captureSequenceNumber -1\\n    -width 1119\\n    -height 696\\n    -sceneRenderFilter 0\\n    $editorName;\\nmodelEditor -e -viewSelected 0 $editorName;\\nmodelEditor -e \\n    -pluginObjects \\\"gpuCacheDisplayFilter\\\" 1 \\n    $editorName\"\n"
		+ "\t\t\t\t$configName;\n\n            setNamedPanelLayout (localizedPanelLabel(\"Current Layout\"));\n        }\n\n        panelHistory -e -clear mainPanelHistory;\n        sceneUIReplacement -clear;\n\t}\n\n\ngrid -spacing 10 -size 100 -divisions 1 -displayAxes yes -displayGridLines yes -displayDivisionLines yes -displayPerspectiveLabels no -displayOrthographicLabels no -displayAxesBold yes -perspectiveLabelPosition axis -orthographicLabelPosition edge;\nviewManip -drawCompass 0 -compassAngle 0 -frontParameters \"\" -homeParameters \"\" -selectionLockParameters \"\";\n}\n");
	setAttr ".st" 3;
createNode script -n "sceneConfigurationScriptNode";
	rename -uid "C7F1F22D-441E-1F29-9186-EDBEFC8AAF94";
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
connectAttr ":defaultColorMgtGlobals.cme" "imagePlaneShape1.cme";
connectAttr ":defaultColorMgtGlobals.cfe" "imagePlaneShape1.cmcf";
connectAttr ":defaultColorMgtGlobals.cfp" "imagePlaneShape1.cmcp";
connectAttr ":defaultColorMgtGlobals.wsn" "imagePlaneShape1.ws";
connectAttr "leftShape.msg" "imagePlaneShape1.ltc";
connectAttr "polySoftEdge19.out" "revolvedSurfaceShape1.i";
relationship "link" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "link" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialShadingGroup.message" ":defaultLightSet.message";
relationship "shadowLink" ":lightLinker1" ":initialParticleSE.message" ":defaultLightSet.message";
connectAttr "layerManager.dli[0]" "defaultLayer.id";
connectAttr "renderLayerManager.rlmi[0]" "defaultRenderLayer.rlid";
connectAttr "curveShape1.ws" "revolve1.ic";
connectAttr "revolve1.os" "nurbsTessellate1.is";
connectAttr "polyTweak1.out" "polyMergeVert1.ip";
connectAttr "revolvedSurfaceShape1.wm" "polyMergeVert1.mp";
connectAttr "nurbsTessellate1.op" "polyTweak1.ip";
connectAttr "polyMergeVert1.out" "polyMergeVert2.ip";
connectAttr "revolvedSurfaceShape1.wm" "polyMergeVert2.mp";
connectAttr "polyTweak2.out" "polyDelEdge1.ip";
connectAttr "polyMergeVert2.out" "polyTweak2.ip";
connectAttr "revolvedSurfaceShape1_pnts_49__pntx.o" "polyTweak2.tk[49].tx";
connectAttr "revolvedSurfaceShape1_pnts_49__pnty.o" "polyTweak2.tk[49].ty";
connectAttr "revolvedSurfaceShape1_pnts_49__pntz.o" "polyTweak2.tk[49].tz";
connectAttr "revolvedSurfaceShape1_pnts_50__pntx.o" "polyTweak2.tk[50].tx";
connectAttr "revolvedSurfaceShape1_pnts_50__pnty.o" "polyTweak2.tk[50].ty";
connectAttr "revolvedSurfaceShape1_pnts_50__pntz.o" "polyTweak2.tk[50].tz";
connectAttr "revolvedSurfaceShape1_pnts_53__pntx.o" "polyTweak2.tk[53].tx";
connectAttr "revolvedSurfaceShape1_pnts_53__pnty.o" "polyTweak2.tk[53].ty";
connectAttr "revolvedSurfaceShape1_pnts_53__pntz.o" "polyTweak2.tk[53].tz";
connectAttr "revolvedSurfaceShape1_pnts_54__pntx.o" "polyTweak2.tk[54].tx";
connectAttr "revolvedSurfaceShape1_pnts_54__pnty.o" "polyTweak2.tk[54].ty";
connectAttr "revolvedSurfaceShape1_pnts_54__pntz.o" "polyTweak2.tk[54].tz";
connectAttr "revolvedSurfaceShape1_pnts_65__pntx.o" "polyTweak2.tk[65].tx";
connectAttr "revolvedSurfaceShape1_pnts_65__pnty.o" "polyTweak2.tk[65].ty";
connectAttr "revolvedSurfaceShape1_pnts_65__pntz.o" "polyTweak2.tk[65].tz";
connectAttr "revolvedSurfaceShape1_pnts_67__pntx.o" "polyTweak2.tk[67].tx";
connectAttr "revolvedSurfaceShape1_pnts_67__pnty.o" "polyTweak2.tk[67].ty";
connectAttr "revolvedSurfaceShape1_pnts_67__pntz.o" "polyTweak2.tk[67].tz";
connectAttr "revolvedSurfaceShape1_pnts_68__pntx.o" "polyTweak2.tk[68].tx";
connectAttr "revolvedSurfaceShape1_pnts_68__pnty.o" "polyTweak2.tk[68].ty";
connectAttr "revolvedSurfaceShape1_pnts_68__pntz.o" "polyTweak2.tk[68].tz";
connectAttr "revolvedSurfaceShape1_pnts_105__pntx.o" "polyTweak2.tk[105].tx";
connectAttr "revolvedSurfaceShape1_pnts_105__pnty.o" "polyTweak2.tk[105].ty";
connectAttr "revolvedSurfaceShape1_pnts_105__pntz.o" "polyTweak2.tk[105].tz";
connectAttr "revolvedSurfaceShape1_pnts_107__pntx.o" "polyTweak2.tk[107].tx";
connectAttr "revolvedSurfaceShape1_pnts_107__pnty.o" "polyTweak2.tk[107].ty";
connectAttr "revolvedSurfaceShape1_pnts_107__pntz.o" "polyTweak2.tk[107].tz";
connectAttr "revolvedSurfaceShape1_pnts_108__pntx.o" "polyTweak2.tk[108].tx";
connectAttr "revolvedSurfaceShape1_pnts_108__pnty.o" "polyTweak2.tk[108].ty";
connectAttr "revolvedSurfaceShape1_pnts_108__pntz.o" "polyTweak2.tk[108].tz";
connectAttr "revolvedSurfaceShape1_pnts_117__pntx.o" "polyTweak2.tk[117].tx";
connectAttr "revolvedSurfaceShape1_pnts_117__pnty.o" "polyTweak2.tk[117].ty";
connectAttr "revolvedSurfaceShape1_pnts_117__pntz.o" "polyTweak2.tk[117].tz";
connectAttr "revolvedSurfaceShape1_pnts_119__pntx.o" "polyTweak2.tk[119].tx";
connectAttr "revolvedSurfaceShape1_pnts_119__pnty.o" "polyTweak2.tk[119].ty";
connectAttr "revolvedSurfaceShape1_pnts_119__pntz.o" "polyTweak2.tk[119].tz";
connectAttr "polyDelEdge1.out" "polySoftEdge1.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge1.mp";
connectAttr "polySoftEdge1.out" "polySoftEdge2.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge2.mp";
connectAttr "polySoftEdge2.out" "polySoftEdge3.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge3.mp";
connectAttr "polySoftEdge3.out" "polyDelEdge2.ip";
connectAttr "polyDelEdge2.out" "polySoftEdge4.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge4.mp";
connectAttr "polySoftEdge4.out" "polySoftEdge5.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge5.mp";
connectAttr "polySoftEdge5.out" "polySoftEdge6.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge6.mp";
connectAttr "polySoftEdge6.out" "polySoftEdge7.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge7.mp";
connectAttr "polySoftEdge7.out" "polySoftEdge8.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge8.mp";
connectAttr "polySoftEdge8.out" "polySoftEdge9.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge9.mp";
connectAttr "polySoftEdge9.out" "polySoftEdge10.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge10.mp";
connectAttr "polySoftEdge10.out" "polySoftEdge11.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge11.mp";
connectAttr "polySoftEdge11.out" "polySoftEdge12.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge12.mp";
connectAttr "polySoftEdge12.out" "polySoftEdge13.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge13.mp";
connectAttr "polySoftEdge13.out" "polySoftEdge14.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge14.mp";
connectAttr "polySoftEdge14.out" "polySoftEdge15.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge15.mp";
connectAttr "polySoftEdge15.out" "polySoftEdge16.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge16.mp";
connectAttr "polySoftEdge16.out" "polySoftEdge17.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge17.mp";
connectAttr "polySoftEdge17.out" "polySoftEdge18.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge18.mp";
connectAttr "polySoftEdge18.out" "polySoftEdge19.ip";
connectAttr "revolvedSurfaceShape1.wm" "polySoftEdge19.mp";
connectAttr "defaultRenderLayer.msg" ":defaultRenderingList1.r" -na;
connectAttr "revolvedSurfaceShape1.iog" ":initialShadingGroup.dsm" -na;
// End of Chess_King.ma
