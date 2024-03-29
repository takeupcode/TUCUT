##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=t-TUCUT
ConfigurationName      :=Debug
WorkspacePath          :=C:/Projects/TUCUT
ProjectPath            :=C:/Projects/TUCUT
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=wahid
Date                   :=12/04/2023
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :=C:/MinGW/bin/g++.exe
SharedObjectLinkerName :=C:/MinGW/bin/g++.exe -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="t-TUCUT.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            := -static 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/local/include $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)TUCUT 
ArLibs                 :=  "TUCUT" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(IntermediateDirectory) $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS := -g -std=c++20 -Wall -Wextra -O0 $(Preprocessors)
CFLAGS   := -g -Wall -O0 $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix) $(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d ".build-debug\s-TUCUT" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

".build-debug\s-TUCUT":
	@$(MakeDirCommand) ".build-debug"
	@echo stam > ".build-debug\s-TUCUT"




PostBuild:
	@echo Executing Post Build commands ...
	mkdir -p ./Debug/Messages
	cp Protocol/Tests/Messages/*.proto ./Debug/Messages/
	@echo Done

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix): Event/Tests/AdvancedPublisher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(DependSuffix) -MM Event/Tests/AdvancedPublisher.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Event/Tests/AdvancedPublisher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(PreprocessSuffix): Event/Tests/AdvancedPublisher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(PreprocessSuffix) Event/Tests/AdvancedPublisher.cpp

$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix): Event/Tests/EventSubscriberScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(DependSuffix) -MM Event/Tests/EventSubscriberScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Event/Tests/EventSubscriberScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(PreprocessSuffix): Event/Tests/EventSubscriberScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(PreprocessSuffix) Event/Tests/EventSubscriberScenarios.cpp

$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix): Exception/Tests/ExceptionScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(DependSuffix) -MM Exception/Tests/ExceptionScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Exception/Tests/ExceptionScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(PreprocessSuffix): Exception/Tests/ExceptionScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(PreprocessSuffix) Exception/Tests/ExceptionScenarios.cpp

$(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix): Test/Tests/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Tests_main.cpp$(DependSuffix) -MM Test/Tests/main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Test/Tests/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Tests_main.cpp$(PreprocessSuffix): Test/Tests/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Tests_main.cpp$(PreprocessSuffix) Test/Tests/main.cpp

$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix): Test/Tests/ScenarioScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(DependSuffix) -MM Test/Tests/ScenarioScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Test/Tests/ScenarioScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(PreprocessSuffix): Test/Tests/ScenarioScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(PreprocessSuffix) Test/Tests/ScenarioScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/OptionParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/OptionParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/OptionParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/OptionParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/OptionParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/EnumValueParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/EnumValueParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/EnumValueParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/EnumValueParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/EnumValueParserScenarios.cpp

$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix): Noise/Tests/NoiseScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(DependSuffix) -MM Noise/Tests/NoiseScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Noise/Tests/NoiseScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(PreprocessSuffix): Noise/Tests/NoiseScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(PreprocessSuffix) Noise/Tests/NoiseScenarios.cpp

$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix): Math/Tests/BezierScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(DependSuffix) -MM Math/Tests/BezierScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Math/Tests/BezierScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(PreprocessSuffix): Math/Tests/BezierScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(PreprocessSuffix) Math/Tests/BezierScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix): Protocol/Tests/TokenReaderScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(DependSuffix) -MM Protocol/Tests/TokenReaderScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/TokenReaderScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(PreprocessSuffix): Protocol/Tests/TokenReaderScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(PreprocessSuffix) Protocol/Tests/TokenReaderScenarios.cpp

$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix): Text/Tests/TextUtilScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(DependSuffix) -MM Text/Tests/TextUtilScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Text/Tests/TextUtilScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(PreprocessSuffix): Text/Tests/TextUtilScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(PreprocessSuffix) Text/Tests/TextUtilScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix): Protocol/Tests/CodeGeneratorCPPScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(DependSuffix) -MM Protocol/Tests/CodeGeneratorCPPScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/CodeGeneratorCPPScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(PreprocessSuffix): Protocol/Tests/CodeGeneratorCPPScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(PreprocessSuffix) Protocol/Tests/CodeGeneratorCPPScenarios.cpp

$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix): Math/Tests/VectorScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(DependSuffix) -MM Math/Tests/VectorScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Math/Tests/VectorScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(PreprocessSuffix): Math/Tests/VectorScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(PreprocessSuffix) Math/Tests/VectorScenarios.cpp

$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix): Identity/Tests/IdentifiableScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(DependSuffix) -MM Identity/Tests/IdentifiableScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Identity/Tests/IdentifiableScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(PreprocessSuffix): Identity/Tests/IdentifiableScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(PreprocessSuffix) Identity/Tests/IdentifiableScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/MessageParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/MessageParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/MessageParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/MessageParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/MessageParserScenarios.cpp

$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix): Color/Tests/ColorScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(DependSuffix) -MM Color/Tests/ColorScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Color/Tests/ColorScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(PreprocessSuffix): Color/Tests/ColorScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(PreprocessSuffix) Color/Tests/ColorScenarios.cpp

$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix): Hash/Tests/HashScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(DependSuffix) -MM Hash/Tests/HashScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Hash/Tests/HashScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(PreprocessSuffix): Hash/Tests/HashScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(PreprocessSuffix) Hash/Tests/HashScenarios.cpp

$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix): Math/Tests/BoundsScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(DependSuffix) -MM Math/Tests/BoundsScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Math/Tests/BoundsScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(PreprocessSuffix): Math/Tests/BoundsScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(PreprocessSuffix) Math/Tests/BoundsScenarios.cpp

$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix): Math/Tests/MinMaxScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(DependSuffix) -MM Math/Tests/MinMaxScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Math/Tests/MinMaxScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(PreprocessSuffix): Math/Tests/MinMaxScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(PreprocessSuffix) Math/Tests/MinMaxScenarios.cpp

$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix): Config/Tests/ConfigInfoScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(DependSuffix) -MM Config/Tests/ConfigInfoScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Config/Tests/ConfigInfoScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(PreprocessSuffix): Config/Tests/ConfigInfoScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(PreprocessSuffix) Config/Tests/ConfigInfoScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/ImportParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/ImportParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/ImportParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/ImportParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/ImportParserScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(ObjectSuffix): Game/Tests/GameManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(DependSuffix) -MM Game/Tests/GameManagerScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/GameManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(PreprocessSuffix): Game/Tests/GameManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_GameManagerScenarios.cpp$(PreprocessSuffix) Game/Tests/GameManagerScenarios.cpp

$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix): Math/Tests/PointScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(DependSuffix) -MM Math/Tests/PointScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Math/Tests/PointScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(PreprocessSuffix): Math/Tests/PointScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(PreprocessSuffix) Math/Tests/PointScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(ObjectSuffix): Game/Tests/GameSystemScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(DependSuffix) -MM Game/Tests/GameSystemScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/GameSystemScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(PreprocessSuffix): Game/Tests/GameSystemScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_GameSystemScenarios.cpp$(PreprocessSuffix) Game/Tests/GameSystemScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(ObjectSuffix): Game/Tests/GameComponentScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(DependSuffix) -MM Game/Tests/GameComponentScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/GameComponentScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(PreprocessSuffix): Game/Tests/GameComponentScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_GameComponentScenarios.cpp$(PreprocessSuffix) Game/Tests/GameComponentScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix): Game/Tests/PropertyValueScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(DependSuffix) -MM Game/Tests/PropertyValueScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/PropertyValueScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(PreprocessSuffix): Game/Tests/PropertyValueScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(PreprocessSuffix) Game/Tests/PropertyValueScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix): Game/Tests/PropertyContainerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(DependSuffix) -MM Game/Tests/PropertyContainerScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/PropertyContainerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(PreprocessSuffix): Game/Tests/PropertyContainerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(PreprocessSuffix) Game/Tests/PropertyContainerScenarios.cpp

$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix): Math/Tests/LerpScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(DependSuffix) -MM Math/Tests/LerpScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Math/Tests/LerpScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(PreprocessSuffix): Math/Tests/LerpScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(PreprocessSuffix) Math/Tests/LerpScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/PackageParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/PackageParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/PackageParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/PackageParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/PackageParserScenarios.cpp

$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix): Text/Tests/StringLiteralScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(DependSuffix) -MM Text/Tests/StringLiteralScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Text/Tests/StringLiteralScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(PreprocessSuffix): Text/Tests/StringLiteralScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(PreprocessSuffix) Text/Tests/StringLiteralScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix): Game/Tests/GameObjectScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(DependSuffix) -MM Game/Tests/GameObjectScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/GameObjectScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(PreprocessSuffix): Game/Tests/GameObjectScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(PreprocessSuffix) Game/Tests/GameObjectScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/MessageFieldParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/MessageFieldParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/MessageFieldParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/MessageFieldParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/MessageFieldParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix): Protocol/Tests/ProtoModelScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(DependSuffix) -MM Protocol/Tests/ProtoModelScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/ProtoModelScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(PreprocessSuffix): Protocol/Tests/ProtoModelScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(PreprocessSuffix) Protocol/Tests/ProtoModelScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/OneofParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/OneofParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/OneofParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/OneofParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/OneofParserScenarios.cpp

$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix): Event/Tests/EventPublisherScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(DependSuffix) -MM Event/Tests/EventPublisherScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Event/Tests/EventPublisherScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(PreprocessSuffix): Event/Tests/EventPublisherScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(PreprocessSuffix) Event/Tests/EventPublisherScenarios.cpp

$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix): Log/Tests/LogManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(DependSuffix) -MM Log/Tests/LogManagerScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Log/Tests/LogManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(PreprocessSuffix): Log/Tests/LogManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(PreprocessSuffix) Log/Tests/LogManagerScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/ProtoParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/ProtoParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/ProtoParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/ProtoParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/ProtoParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix): Protocol/Tests/CodeGeneratorManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(DependSuffix) -MM Protocol/Tests/CodeGeneratorManagerScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/CodeGeneratorManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(PreprocessSuffix): Protocol/Tests/CodeGeneratorManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(PreprocessSuffix) Protocol/Tests/CodeGeneratorManagerScenarios.cpp

$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix): File/Tests/FileManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(DependSuffix) -MM File/Tests/FileManagerScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/File/Tests/FileManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(PreprocessSuffix): File/Tests/FileManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(PreprocessSuffix) File/Tests/FileManagerScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix): Game/Tests/PropertyGroupScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(DependSuffix) -MM Game/Tests/PropertyGroupScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/Tests/PropertyGroupScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(PreprocessSuffix): Game/Tests/PropertyGroupScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(PreprocessSuffix) Game/Tests/PropertyGroupScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/EnumParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/EnumParserScenarios.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/Tests/EnumParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/EnumParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/EnumParserScenarios.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


