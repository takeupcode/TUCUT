##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=s-TUCUT
ConfigurationName      :=Debug
WorkspacePath          :=C:/Projects/TUCUT
ProjectPath            :=C:/Projects/TUCUT
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=wahid
Date                   :=13/04/2023
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
OutputFile             :=$(IntermediateDirectory)/libTUCUT.a
Preprocessors          :=$(PreprocessorSwitch)UNICODE $(PreprocessorSwitch)_UNICODE 
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="s-TUCUT.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=C:/MinGW/bin/windres.exe
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/local/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := C:/MinGW/bin/ar.exe rcu
CXX      := C:/MinGW/bin/g++.exe
CC       := C:/MinGW/bin/gcc.exe
CXXFLAGS := -g -std=c++20 -Wall -Wextra -O0 $(Preprocessors)
CFLAGS   := -g  $(Preprocessors)
ASFLAGS  := 
AS       := C:/MinGW/bin/as.exe


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/TUI_Prompt.cpp$(ObjectSuffix) $(IntermediateDirectory)/TUI_Input.cpp$(ObjectSuffix) $(IntermediateDirectory)/TUI_Game.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/TUI_Event.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) 

Objects1=$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Text_Encoding.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/TUI_MessageQueue.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/TUI_Terminal.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) \
	



Objects=$(Objects0) $(Objects1) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	@echo $(Objects1) >> $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList)
	@$(MakeDirCommand) "C:\Projects\TUCUT/.build-debug"
	@echo rebuilt > "C:\Projects\TUCUT/.build-debug/s-TUCUT"

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


./Debug:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/TUI_Prompt.cpp$(ObjectSuffix): TUI/Prompt.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TUI_Prompt.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TUI_Prompt.cpp$(DependSuffix) -MM TUI/Prompt.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/TUI/Prompt.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TUI_Prompt.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TUI_Prompt.cpp$(PreprocessSuffix): TUI/Prompt.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TUI_Prompt.cpp$(PreprocessSuffix) TUI/Prompt.cpp

$(IntermediateDirectory)/TUI_Input.cpp$(ObjectSuffix): TUI/Input.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TUI_Input.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TUI_Input.cpp$(DependSuffix) -MM TUI/Input.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/TUI/Input.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TUI_Input.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TUI_Input.cpp$(PreprocessSuffix): TUI/Input.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TUI_Input.cpp$(PreprocessSuffix) TUI/Input.cpp

$(IntermediateDirectory)/TUI_Game.cpp$(ObjectSuffix): TUI/Game.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TUI_Game.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TUI_Game.cpp$(DependSuffix) -MM TUI/Game.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/TUI/Game.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TUI_Game.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TUI_Game.cpp$(PreprocessSuffix): TUI/Game.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TUI_Game.cpp$(PreprocessSuffix) TUI/Game.cpp

$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix): Game/PropertyGroup.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix) -MM Game/PropertyGroup.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/PropertyGroup.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyGroup.cpp$(PreprocessSuffix): Game/PropertyGroup.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyGroup.cpp$(PreprocessSuffix) Game/PropertyGroup.cpp

$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix): Game/PropertyContainer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix) -MM Game/PropertyContainer.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/PropertyContainer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyContainer.cpp$(PreprocessSuffix): Game/PropertyContainer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyContainer.cpp$(PreprocessSuffix) Game/PropertyContainer.cpp

$(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix): Game/GameManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameManager.cpp$(DependSuffix) -MM Game/GameManager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/GameManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameManager.cpp$(PreprocessSuffix): Game/GameManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameManager.cpp$(PreprocessSuffix) Game/GameManager.cpp

$(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix): Game/GameRegion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameRegion.cpp$(DependSuffix) -MM Game/GameRegion.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/GameRegion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameRegion.cpp$(PreprocessSuffix): Game/GameRegion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameRegion.cpp$(PreprocessSuffix) Game/GameRegion.cpp

$(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix): Game/IMovementSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_IMovementSystem.cpp$(DependSuffix) -MM Game/IMovementSystem.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/IMovementSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_IMovementSystem.cpp$(PreprocessSuffix): Game/IMovementSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_IMovementSystem.cpp$(PreprocessSuffix) Game/IMovementSystem.cpp

$(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix): Game/IPositionComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_IPositionComponent.cpp$(DependSuffix) -MM Game/IPositionComponent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/IPositionComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_IPositionComponent.cpp$(PreprocessSuffix): Game/IPositionComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_IPositionComponent.cpp$(PreprocessSuffix) Game/IPositionComponent.cpp

$(IntermediateDirectory)/TUI_Event.cpp$(ObjectSuffix): TUI/Event.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TUI_Event.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TUI_Event.cpp$(DependSuffix) -MM TUI/Event.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/TUI/Event.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TUI_Event.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TUI_Event.cpp$(PreprocessSuffix): TUI/Event.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TUI_Event.cpp$(PreprocessSuffix) TUI/Event.cpp

$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix): Game/MovementComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_MovementComponent.cpp$(DependSuffix) -MM Game/MovementComponent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/MovementComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_MovementComponent.cpp$(PreprocessSuffix): Game/MovementComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_MovementComponent.cpp$(PreprocessSuffix) Game/MovementComponent.cpp

$(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix): Game/MovementSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_MovementSystem.cpp$(DependSuffix) -MM Game/MovementSystem.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/MovementSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_MovementSystem.cpp$(PreprocessSuffix): Game/MovementSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_MovementSystem.cpp$(PreprocessSuffix) Game/MovementSystem.cpp

$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix): Protocol/ProtoModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix) -MM Protocol/ProtoModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/ProtoModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(PreprocessSuffix): Protocol/ProtoModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(PreprocessSuffix) Protocol/ProtoModel.cpp

$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix): Protocol/OneofParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix) -MM Protocol/OneofParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OneofParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofParser.cpp$(PreprocessSuffix): Protocol/OneofParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofParser.cpp$(PreprocessSuffix) Protocol/OneofParser.cpp

$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix): Protocol/OptionSingleParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix) -MM Protocol/OptionSingleParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OptionSingleParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(PreprocessSuffix): Protocol/OptionSingleParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(PreprocessSuffix) Protocol/OptionSingleParser.cpp

$(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix): Game/IMovementComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_IMovementComponent.cpp$(DependSuffix) -MM Game/IMovementComponent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/IMovementComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_IMovementComponent.cpp$(PreprocessSuffix): Game/IMovementComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_IMovementComponent.cpp$(PreprocessSuffix) Game/IMovementComponent.cpp

$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix): Protocol/EnumValueParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix) -MM Protocol/EnumValueParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/EnumValueParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(PreprocessSuffix): Protocol/EnumValueParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(PreprocessSuffix) Protocol/EnumValueParser.cpp

$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix): Text/TextUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix) -MM Text/TextUtil.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Text/TextUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_TextUtil.cpp$(PreprocessSuffix): Text/TextUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_TextUtil.cpp$(PreprocessSuffix) Text/TextUtil.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix): Protocol/CodeGeneratorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix) -MM Protocol/CodeGeneratorManager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/CodeGeneratorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(PreprocessSuffix): Protocol/CodeGeneratorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(PreprocessSuffix) Protocol/CodeGeneratorManager.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix): Protocol/CodeGeneratorCPP.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix) -MM Protocol/CodeGeneratorCPP.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/CodeGeneratorCPP.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(PreprocessSuffix): Protocol/CodeGeneratorCPP.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(PreprocessSuffix) Protocol/CodeGeneratorCPP.cpp

$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix): Protocol/ParserManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix) -MM Protocol/ParserManager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/ParserManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ParserManager.cpp$(PreprocessSuffix): Protocol/ParserManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ParserManager.cpp$(PreprocessSuffix) Protocol/ParserManager.cpp

$(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix): Game/PositionComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PositionComponent.cpp$(DependSuffix) -MM Game/PositionComponent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/PositionComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PositionComponent.cpp$(PreprocessSuffix): Game/PositionComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PositionComponent.cpp$(PreprocessSuffix) Game/PositionComponent.cpp

$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix): Noise/NoiseUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(DependSuffix) -MM Noise/NoiseUtil.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Noise/NoiseUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(PreprocessSuffix): Noise/NoiseUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Noise_NoiseUtil.cpp$(PreprocessSuffix) Noise/NoiseUtil.cpp

$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix): Config/ConfigInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix) -MM Config/ConfigInfo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Config/ConfigInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Config_ConfigInfo.cpp$(PreprocessSuffix): Config/ConfigInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Config_ConfigInfo.cpp$(PreprocessSuffix) Config/ConfigInfo.cpp

$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix): Protocol/OptionValueParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix) -MM Protocol/OptionValueParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OptionValueParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(PreprocessSuffix): Protocol/OptionValueParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(PreprocessSuffix) Protocol/OptionValueParser.cpp

$(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix): Noise/Noise.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Noise_Noise.cpp$(DependSuffix) -MM Noise/Noise.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Noise/Noise.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Noise_Noise.cpp$(PreprocessSuffix): Noise/Noise.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Noise_Noise.cpp$(PreprocessSuffix) Noise/Noise.cpp

$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix): Protocol/OptionModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix) -MM Protocol/OptionModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OptionModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionModel.cpp$(PreprocessSuffix): Protocol/OptionModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionModel.cpp$(PreprocessSuffix) Protocol/OptionModel.cpp

$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix): Protocol/EnumModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix) -MM Protocol/EnumModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/EnumModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumModel.cpp$(PreprocessSuffix): Protocol/EnumModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumModel.cpp$(PreprocessSuffix) Protocol/EnumModel.cpp

$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix): Protocol/OneofModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix) -MM Protocol/OneofModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OneofModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofModel.cpp$(PreprocessSuffix): Protocol/OneofModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofModel.cpp$(PreprocessSuffix) Protocol/OneofModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix): Protocol/MessageFieldModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix) -MM Protocol/MessageFieldModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/MessageFieldModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(PreprocessSuffix): Protocol/MessageFieldModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(PreprocessSuffix) Protocol/MessageFieldModel.cpp

$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix): Protocol/ProtoParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix) -MM Protocol/ProtoParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/ProtoParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(PreprocessSuffix): Protocol/ProtoParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(PreprocessSuffix) Protocol/ProtoParser.cpp

$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix): Protocol/MessageParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix) -MM Protocol/MessageParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/MessageParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageParser.cpp$(PreprocessSuffix): Protocol/MessageParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageParser.cpp$(PreprocessSuffix) Protocol/MessageParser.cpp

$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix): File/FileManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix) -MM File/FileManager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/File/FileManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/File_FileManager.cpp$(PreprocessSuffix): File/FileManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/File_FileManager.cpp$(PreprocessSuffix) File/FileManager.cpp

$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix): Game/GameComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameComponent.cpp$(DependSuffix) -MM Game/GameComponent.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/GameComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameComponent.cpp$(PreprocessSuffix): Game/GameComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameComponent.cpp$(PreprocessSuffix) Game/GameComponent.cpp

$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix): Game/GameSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameSystem.cpp$(DependSuffix) -MM Game/GameSystem.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/GameSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameSystem.cpp$(PreprocessSuffix): Game/GameSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameSystem.cpp$(PreprocessSuffix) Game/GameSystem.cpp

$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix): Protocol/MessageFieldParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix) -MM Protocol/MessageFieldParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/MessageFieldParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(PreprocessSuffix): Protocol/MessageFieldParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(PreprocessSuffix) Protocol/MessageFieldParser.cpp

$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix): Game/PropertyValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix) -MM Game/PropertyValue.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/PropertyValue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyValue.cpp$(PreprocessSuffix): Game/PropertyValue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyValue.cpp$(PreprocessSuffix) Game/PropertyValue.cpp

$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix): Protocol/EnumValueModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix) -MM Protocol/EnumValueModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/EnumValueModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(PreprocessSuffix): Protocol/EnumValueModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(PreprocessSuffix) Protocol/EnumValueModel.cpp

$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix): Protocol/EnumParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix) -MM Protocol/EnumParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/EnumParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumParser.cpp$(PreprocessSuffix): Protocol/EnumParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumParser.cpp$(PreprocessSuffix) Protocol/EnumParser.cpp

$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix): Game/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix) -MM Game/GameObject.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Game/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix): Game/GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix) Game/GameObject.cpp

$(IntermediateDirectory)/Text_Encoding.cpp$(ObjectSuffix): Text/Encoding.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_Encoding.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_Encoding.cpp$(DependSuffix) -MM Text/Encoding.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Text/Encoding.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_Encoding.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_Encoding.cpp$(PreprocessSuffix): Text/Encoding.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_Encoding.cpp$(PreprocessSuffix) Text/Encoding.cpp

$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix): Protocol/TokenReader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix) -MM Protocol/TokenReader.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/TokenReader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_TokenReader.cpp$(PreprocessSuffix): Protocol/TokenReader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_TokenReader.cpp$(PreprocessSuffix) Protocol/TokenReader.cpp

$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix): Protocol/OptionGroupParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix) -MM Protocol/OptionGroupParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OptionGroupParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(PreprocessSuffix): Protocol/OptionGroupParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(PreprocessSuffix) Protocol/OptionGroupParser.cpp

$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix): Protocol/OneofFieldParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix) -MM Protocol/OneofFieldParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/OneofFieldParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(PreprocessSuffix): Protocol/OneofFieldParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(PreprocessSuffix) Protocol/OneofFieldParser.cpp

$(IntermediateDirectory)/TUI_MessageQueue.cpp$(ObjectSuffix): TUI/MessageQueue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TUI_MessageQueue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TUI_MessageQueue.cpp$(DependSuffix) -MM TUI/MessageQueue.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/TUI/MessageQueue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TUI_MessageQueue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TUI_MessageQueue.cpp$(PreprocessSuffix): TUI/MessageQueue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TUI_MessageQueue.cpp$(PreprocessSuffix) TUI/MessageQueue.cpp

$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix): Protocol/PackageParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix) -MM Protocol/PackageParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/PackageParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_PackageParser.cpp$(PreprocessSuffix): Protocol/PackageParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_PackageParser.cpp$(PreprocessSuffix) Protocol/PackageParser.cpp

$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix): Log/LogManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix) -MM Log/LogManager.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Log/LogManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log_LogManager.cpp$(PreprocessSuffix): Log/LogManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log_LogManager.cpp$(PreprocessSuffix) Log/LogManager.cpp

$(IntermediateDirectory)/TUI_Terminal.cpp$(ObjectSuffix): TUI/Terminal.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/TUI_Terminal.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/TUI_Terminal.cpp$(DependSuffix) -MM TUI/Terminal.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/TUI/Terminal.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/TUI_Terminal.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/TUI_Terminal.cpp$(PreprocessSuffix): TUI/Terminal.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/TUI_Terminal.cpp$(PreprocessSuffix) TUI/Terminal.cpp

$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix): Protocol/MessageModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix) -MM Protocol/MessageModel.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/MessageModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageModel.cpp$(PreprocessSuffix): Protocol/MessageModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageModel.cpp$(PreprocessSuffix) Protocol/MessageModel.cpp

$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix): Protocol/ImportParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix) -MM Protocol/ImportParser.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Projects/TUCUT/Protocol/ImportParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ImportParser.cpp$(PreprocessSuffix): Protocol/ImportParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ImportParser.cpp$(PreprocessSuffix) Protocol/ImportParser.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


