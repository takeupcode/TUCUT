##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=t-TUCUT
ConfigurationName      :=Debug
WorkspacePath          :=/home/wahid/Storage/GitHub/TUCUT
ProjectPath            :=/home/wahid/Storage/GitHub/TUCUT
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Wahid
Date                   :=16/07/19
CodeLitePath           :=/home/wahid/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
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
MakeDirCommand         :=mkdir -p
LinkOptions            := -static 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)TUCUT $(LibrarySwitch)boost_filesystem 
ArLibs                 :=  "TUCUT" "boost_filesystem" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)$(IntermediateDirectory) $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -g -O0 -std=c++17 -Wall -Wextra  $(Preprocessors)
CFLAGS   := -g -O0 -Wall  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix) $(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix) $(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d ".build-debug/s-TUCUT" $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

".build-debug/s-TUCUT":
	@$(MakeDirCommand) ".build-debug"
	@echo stam > ".build-debug/s-TUCUT"




MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix): Noise/Tests/NoiseScenarios.cpp $(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Noise/Tests/NoiseScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(DependSuffix): Noise/Tests/NoiseScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(DependSuffix) -MM Noise/Tests/NoiseScenarios.cpp

$(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(PreprocessSuffix): Noise/Tests/NoiseScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Noise_Tests_NoiseScenarios.cpp$(PreprocessSuffix) Noise/Tests/NoiseScenarios.cpp

$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix): File/Tests/FileManagerScenarios.cpp $(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/File/Tests/FileManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(DependSuffix): File/Tests/FileManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(DependSuffix) -MM File/Tests/FileManagerScenarios.cpp

$(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(PreprocessSuffix): File/Tests/FileManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/File_Tests_FileManagerScenarios.cpp$(PreprocessSuffix) File/Tests/FileManagerScenarios.cpp

$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix): Event/Tests/AdvancedPublisher.cpp $(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Event/Tests/AdvancedPublisher.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(DependSuffix): Event/Tests/AdvancedPublisher.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(DependSuffix) -MM Event/Tests/AdvancedPublisher.cpp

$(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(PreprocessSuffix): Event/Tests/AdvancedPublisher.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Event_Tests_AdvancedPublisher.cpp$(PreprocessSuffix) Event/Tests/AdvancedPublisher.cpp

$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix): Event/Tests/EventPublisherScenarios.cpp $(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Event/Tests/EventPublisherScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(DependSuffix): Event/Tests/EventPublisherScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(DependSuffix) -MM Event/Tests/EventPublisherScenarios.cpp

$(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(PreprocessSuffix): Event/Tests/EventPublisherScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Event_Tests_EventPublisherScenarios.cpp$(PreprocessSuffix) Event/Tests/EventPublisherScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix): Protocol/Tests/CodeGeneratorManagerScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/CodeGeneratorManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(DependSuffix): Protocol/Tests/CodeGeneratorManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(DependSuffix) -MM Protocol/Tests/CodeGeneratorManagerScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(PreprocessSuffix): Protocol/Tests/CodeGeneratorManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorManagerScenarios.cpp$(PreprocessSuffix) Protocol/Tests/CodeGeneratorManagerScenarios.cpp

$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix): Math/Tests/LerpScenarios.cpp $(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Math/Tests/LerpScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(DependSuffix): Math/Tests/LerpScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(DependSuffix) -MM Math/Tests/LerpScenarios.cpp

$(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(PreprocessSuffix): Math/Tests/LerpScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_LerpScenarios.cpp$(PreprocessSuffix) Math/Tests/LerpScenarios.cpp

$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix): Math/Tests/PointScenarios.cpp $(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Math/Tests/PointScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(DependSuffix): Math/Tests/PointScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(DependSuffix) -MM Math/Tests/PointScenarios.cpp

$(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(PreprocessSuffix): Math/Tests/PointScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_PointScenarios.cpp$(PreprocessSuffix) Math/Tests/PointScenarios.cpp

$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix): Math/Tests/BezierScenarios.cpp $(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Math/Tests/BezierScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(DependSuffix): Math/Tests/BezierScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(DependSuffix) -MM Math/Tests/BezierScenarios.cpp

$(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(PreprocessSuffix): Math/Tests/BezierScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_BezierScenarios.cpp$(PreprocessSuffix) Math/Tests/BezierScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix): Game/Tests/PropertyValueScenarios.cpp $(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/Tests/PropertyValueScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(DependSuffix): Game/Tests/PropertyValueScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(DependSuffix) -MM Game/Tests/PropertyValueScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(PreprocessSuffix): Game/Tests/PropertyValueScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_PropertyValueScenarios.cpp$(PreprocessSuffix) Game/Tests/PropertyValueScenarios.cpp

$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix): Math/Tests/VectorScenarios.cpp $(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Math/Tests/VectorScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(DependSuffix): Math/Tests/VectorScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(DependSuffix) -MM Math/Tests/VectorScenarios.cpp

$(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(PreprocessSuffix): Math/Tests/VectorScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_VectorScenarios.cpp$(PreprocessSuffix) Math/Tests/VectorScenarios.cpp

$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix): Text/Tests/TextUtilScenarios.cpp $(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Text/Tests/TextUtilScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(DependSuffix): Text/Tests/TextUtilScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(DependSuffix) -MM Text/Tests/TextUtilScenarios.cpp

$(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(PreprocessSuffix): Text/Tests/TextUtilScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_Tests_TextUtilScenarios.cpp$(PreprocessSuffix) Text/Tests/TextUtilScenarios.cpp

$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix): Log/Tests/LogManagerScenarios.cpp $(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Log/Tests/LogManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(DependSuffix): Log/Tests/LogManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(DependSuffix) -MM Log/Tests/LogManagerScenarios.cpp

$(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(PreprocessSuffix): Log/Tests/LogManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log_Tests_LogManagerScenarios.cpp$(PreprocessSuffix) Log/Tests/LogManagerScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix): Game/Tests/GameObjectScenarios.cpp $(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/Tests/GameObjectScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(DependSuffix): Game/Tests/GameObjectScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(DependSuffix) -MM Game/Tests/GameObjectScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(PreprocessSuffix): Game/Tests/GameObjectScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_GameObjectScenarios.cpp$(PreprocessSuffix) Game/Tests/GameObjectScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/OneofParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/OneofParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(DependSuffix): Protocol/Tests/OneofParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/OneofParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/OneofParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_OneofParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/OneofParserScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix): Game/Tests/PropertyContainerScenarios.cpp $(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/Tests/PropertyContainerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(DependSuffix): Game/Tests/PropertyContainerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(DependSuffix) -MM Game/Tests/PropertyContainerScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(PreprocessSuffix): Game/Tests/PropertyContainerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_PropertyContainerScenarios.cpp$(PreprocessSuffix) Game/Tests/PropertyContainerScenarios.cpp

$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix): Hash/Tests/HashScenarios.cpp $(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Hash/Tests/HashScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(DependSuffix): Hash/Tests/HashScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(DependSuffix) -MM Hash/Tests/HashScenarios.cpp

$(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(PreprocessSuffix): Hash/Tests/HashScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Hash_Tests_HashScenarios.cpp$(PreprocessSuffix) Hash/Tests/HashScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/EnumParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/EnumParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(DependSuffix): Protocol/Tests/EnumParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/EnumParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/EnumParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_EnumParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/EnumParserScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix): Game/Tests/PropertyGroupScenarios.cpp $(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/Tests/PropertyGroupScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(DependSuffix): Game/Tests/PropertyGroupScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(DependSuffix) -MM Game/Tests/PropertyGroupScenarios.cpp

$(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(PreprocessSuffix): Game/Tests/PropertyGroupScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_PropertyGroupScenarios.cpp$(PreprocessSuffix) Game/Tests/PropertyGroupScenarios.cpp

$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix): Identity/Tests/IdentifiableScenarios.cpp $(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Identity/Tests/IdentifiableScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(DependSuffix): Identity/Tests/IdentifiableScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(DependSuffix) -MM Identity/Tests/IdentifiableScenarios.cpp

$(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(PreprocessSuffix): Identity/Tests/IdentifiableScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Identity_Tests_IdentifiableScenarios.cpp$(PreprocessSuffix) Identity/Tests/IdentifiableScenarios.cpp

$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix): Color/Tests/ColorScenarios.cpp $(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Color/Tests/ColorScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(DependSuffix): Color/Tests/ColorScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(DependSuffix) -MM Color/Tests/ColorScenarios.cpp

$(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(PreprocessSuffix): Color/Tests/ColorScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Color_Tests_ColorScenarios.cpp$(PreprocessSuffix) Color/Tests/ColorScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix): Protocol/Tests/CodeGeneratorCPPScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/CodeGeneratorCPPScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(DependSuffix): Protocol/Tests/CodeGeneratorCPPScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(DependSuffix) -MM Protocol/Tests/CodeGeneratorCPPScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(PreprocessSuffix): Protocol/Tests/CodeGeneratorCPPScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_CodeGeneratorCPPScenarios.cpp$(PreprocessSuffix) Protocol/Tests/CodeGeneratorCPPScenarios.cpp

$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix): Text/Tests/StringLiteralScenarios.cpp $(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Text/Tests/StringLiteralScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(DependSuffix): Text/Tests/StringLiteralScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(DependSuffix) -MM Text/Tests/StringLiteralScenarios.cpp

$(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(PreprocessSuffix): Text/Tests/StringLiteralScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_Tests_StringLiteralScenarios.cpp$(PreprocessSuffix) Text/Tests/StringLiteralScenarios.cpp

$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix): Math/Tests/MinMaxScenarios.cpp $(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Math/Tests/MinMaxScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(DependSuffix): Math/Tests/MinMaxScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(DependSuffix) -MM Math/Tests/MinMaxScenarios.cpp

$(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(PreprocessSuffix): Math/Tests/MinMaxScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_MinMaxScenarios.cpp$(PreprocessSuffix) Math/Tests/MinMaxScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix): Protocol/Tests/ProtoModelScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/ProtoModelScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(DependSuffix): Protocol/Tests/ProtoModelScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(DependSuffix) -MM Protocol/Tests/ProtoModelScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(PreprocessSuffix): Protocol/Tests/ProtoModelScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_ProtoModelScenarios.cpp$(PreprocessSuffix) Protocol/Tests/ProtoModelScenarios.cpp

$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix): Math/Tests/BoundsScenarios.cpp $(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Math/Tests/BoundsScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(DependSuffix): Math/Tests/BoundsScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(DependSuffix) -MM Math/Tests/BoundsScenarios.cpp

$(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(PreprocessSuffix): Math/Tests/BoundsScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Math_Tests_BoundsScenarios.cpp$(PreprocessSuffix) Math/Tests/BoundsScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/EnumValueParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/EnumValueParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(DependSuffix): Protocol/Tests/EnumValueParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/EnumValueParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/EnumValueParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_EnumValueParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/EnumValueParserScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(ObjectSuffix): Game/Tests/GameObjectManagerScenarios.cpp $(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/Tests/GameObjectManagerScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(DependSuffix): Game/Tests/GameObjectManagerScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(DependSuffix) -MM Game/Tests/GameObjectManagerScenarios.cpp

$(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(PreprocessSuffix): Game/Tests/GameObjectManagerScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_Tests_GameObjectManagerScenarios.cpp$(PreprocessSuffix) Game/Tests/GameObjectManagerScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/MessageFieldParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/MessageFieldParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(DependSuffix): Protocol/Tests/MessageFieldParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/MessageFieldParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/MessageFieldParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_MessageFieldParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/MessageFieldParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/MessageParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/MessageParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(DependSuffix): Protocol/Tests/MessageParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/MessageParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/MessageParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_MessageParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/MessageParserScenarios.cpp

$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix): Event/Tests/EventSubscriberScenarios.cpp $(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Event/Tests/EventSubscriberScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(DependSuffix): Event/Tests/EventSubscriberScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(DependSuffix) -MM Event/Tests/EventSubscriberScenarios.cpp

$(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(PreprocessSuffix): Event/Tests/EventSubscriberScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Event_Tests_EventSubscriberScenarios.cpp$(PreprocessSuffix) Event/Tests/EventSubscriberScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix): Protocol/Tests/TokenReaderScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/TokenReaderScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(DependSuffix): Protocol/Tests/TokenReaderScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(DependSuffix) -MM Protocol/Tests/TokenReaderScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(PreprocessSuffix): Protocol/Tests/TokenReaderScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_TokenReaderScenarios.cpp$(PreprocessSuffix) Protocol/Tests/TokenReaderScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/ProtoParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/ProtoParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(DependSuffix): Protocol/Tests/ProtoParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/ProtoParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/ProtoParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_ProtoParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/ProtoParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/ImportParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/ImportParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(DependSuffix): Protocol/Tests/ImportParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/ImportParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/ImportParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_ImportParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/ImportParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/PackageParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/PackageParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(DependSuffix): Protocol/Tests/PackageParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/PackageParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/PackageParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_PackageParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/PackageParserScenarios.cpp

$(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix): Test/Tests/main.cpp $(IntermediateDirectory)/Test_Tests_main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Test/Tests/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Tests_main.cpp$(DependSuffix): Test/Tests/main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Tests_main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Tests_main.cpp$(DependSuffix) -MM Test/Tests/main.cpp

$(IntermediateDirectory)/Test_Tests_main.cpp$(PreprocessSuffix): Test/Tests/main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Tests_main.cpp$(PreprocessSuffix) Test/Tests/main.cpp

$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix): Protocol/Tests/OptionParserScenarios.cpp $(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/Tests/OptionParserScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(DependSuffix): Protocol/Tests/OptionParserScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(DependSuffix) -MM Protocol/Tests/OptionParserScenarios.cpp

$(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(PreprocessSuffix): Protocol/Tests/OptionParserScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_Tests_OptionParserScenarios.cpp$(PreprocessSuffix) Protocol/Tests/OptionParserScenarios.cpp

$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix): Config/Tests/ConfigInfoScenarios.cpp $(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Config/Tests/ConfigInfoScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(DependSuffix): Config/Tests/ConfigInfoScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(DependSuffix) -MM Config/Tests/ConfigInfoScenarios.cpp

$(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(PreprocessSuffix): Config/Tests/ConfigInfoScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Config_Tests_ConfigInfoScenarios.cpp$(PreprocessSuffix) Config/Tests/ConfigInfoScenarios.cpp

$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix): Test/Tests/ScenarioScenarios.cpp $(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Test/Tests/ScenarioScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(DependSuffix): Test/Tests/ScenarioScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(DependSuffix) -MM Test/Tests/ScenarioScenarios.cpp

$(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(PreprocessSuffix): Test/Tests/ScenarioScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Test_Tests_ScenarioScenarios.cpp$(PreprocessSuffix) Test/Tests/ScenarioScenarios.cpp

$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix): Exception/Tests/ExceptionScenarios.cpp $(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Exception/Tests/ExceptionScenarios.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(DependSuffix): Exception/Tests/ExceptionScenarios.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(DependSuffix) -MM Exception/Tests/ExceptionScenarios.cpp

$(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(PreprocessSuffix): Exception/Tests/ExceptionScenarios.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Exception_Tests_ExceptionScenarios.cpp$(PreprocessSuffix) Exception/Tests/ExceptionScenarios.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


