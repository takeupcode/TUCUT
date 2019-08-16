##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=s-TUCUT
ConfigurationName      :=Debug
WorkspacePath          :=/home/wahid/Storage/GitHub/aboqa
ProjectPath            :=/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Wahid
Date                   :=16/08/19
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
OutputFile             :=$(IntermediateDirectory)/libTUCUT.a
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="s-TUCUT.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)/usr/local/include $(IncludeSwitch)/opt/ncurses/include/ncursesw $(IncludeSwitch)/opt/ncurses/include 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)/usr/local/lib $(LibraryPathSwitch)/opt/ncurses/lib 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS := -g -std=c++17 -Wall -Wextra  $(Preprocessors)
CFLAGS   := -g  $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Curses_ListBox.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_Window.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_TextRegion.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_Button.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_NumberBox.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_Label.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_DisplayBox.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_Colors.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_Visibility.cpp$(ObjectSuffix) $(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_CheckBox.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_TextBox.cpp$(ObjectSuffix) \
	

Objects1=$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_ConsoleManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_WindowSystem.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) $(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Curses_Control.cpp$(ObjectSuffix) $(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Curses_CursesUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) 



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
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/wahid/Storage/GitHub/aboqa/.build-debug"
	@echo rebuilt > "/home/wahid/Storage/GitHub/aboqa/.build-debug/s-TUCUT"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix): Game/GameObject.cpp $(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix): Game/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix) -MM Game/GameObject.cpp

$(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix): Game/GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix) Game/GameObject.cpp

$(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix): Game/GameManager.cpp $(IntermediateDirectory)/Game_GameManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/GameManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameManager.cpp$(DependSuffix): Game/GameManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameManager.cpp$(DependSuffix) -MM Game/GameManager.cpp

$(IntermediateDirectory)/Game_GameManager.cpp$(PreprocessSuffix): Game/GameManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameManager.cpp$(PreprocessSuffix) Game/GameManager.cpp

$(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix): Game/GameRegion.cpp $(IntermediateDirectory)/Game_GameRegion.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/GameRegion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameRegion.cpp$(DependSuffix): Game/GameRegion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameRegion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameRegion.cpp$(DependSuffix) -MM Game/GameRegion.cpp

$(IntermediateDirectory)/Game_GameRegion.cpp$(PreprocessSuffix): Game/GameRegion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameRegion.cpp$(PreprocessSuffix) Game/GameRegion.cpp

$(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix): Game/IMovementSystem.cpp $(IntermediateDirectory)/Game_IMovementSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/IMovementSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_IMovementSystem.cpp$(DependSuffix): Game/IMovementSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_IMovementSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_IMovementSystem.cpp$(DependSuffix) -MM Game/IMovementSystem.cpp

$(IntermediateDirectory)/Game_IMovementSystem.cpp$(PreprocessSuffix): Game/IMovementSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_IMovementSystem.cpp$(PreprocessSuffix) Game/IMovementSystem.cpp

$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix): Game/MovementComponent.cpp $(IntermediateDirectory)/Game_MovementComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/MovementComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_MovementComponent.cpp$(DependSuffix): Game/MovementComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_MovementComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_MovementComponent.cpp$(DependSuffix) -MM Game/MovementComponent.cpp

$(IntermediateDirectory)/Game_MovementComponent.cpp$(PreprocessSuffix): Game/MovementComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_MovementComponent.cpp$(PreprocessSuffix) Game/MovementComponent.cpp

$(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix): Game/MovementSystem.cpp $(IntermediateDirectory)/Game_MovementSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/MovementSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_MovementSystem.cpp$(DependSuffix): Game/MovementSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_MovementSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_MovementSystem.cpp$(DependSuffix) -MM Game/MovementSystem.cpp

$(IntermediateDirectory)/Game_MovementSystem.cpp$(PreprocessSuffix): Game/MovementSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_MovementSystem.cpp$(PreprocessSuffix) Game/MovementSystem.cpp

$(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix): Game/IMovementComponent.cpp $(IntermediateDirectory)/Game_IMovementComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/IMovementComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_IMovementComponent.cpp$(DependSuffix): Game/IMovementComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_IMovementComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_IMovementComponent.cpp$(DependSuffix) -MM Game/IMovementComponent.cpp

$(IntermediateDirectory)/Game_IMovementComponent.cpp$(PreprocessSuffix): Game/IMovementComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_IMovementComponent.cpp$(PreprocessSuffix) Game/IMovementComponent.cpp

$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix): Protocol/OneofParser.cpp $(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OneofParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix): Protocol/OneofParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix) -MM Protocol/OneofParser.cpp

$(IntermediateDirectory)/Protocol_OneofParser.cpp$(PreprocessSuffix): Protocol/OneofParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofParser.cpp$(PreprocessSuffix) Protocol/OneofParser.cpp

$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix): Protocol/PackageParser.cpp $(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/PackageParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix): Protocol/PackageParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix) -MM Protocol/PackageParser.cpp

$(IntermediateDirectory)/Protocol_PackageParser.cpp$(PreprocessSuffix): Protocol/PackageParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_PackageParser.cpp$(PreprocessSuffix) Protocol/PackageParser.cpp

$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix): Protocol/EnumParser.cpp $(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/EnumParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix): Protocol/EnumParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix) -MM Protocol/EnumParser.cpp

$(IntermediateDirectory)/Protocol_EnumParser.cpp$(PreprocessSuffix): Protocol/EnumParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumParser.cpp$(PreprocessSuffix) Protocol/EnumParser.cpp

$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix): Game/PropertyGroup.cpp $(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/PropertyGroup.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix): Game/PropertyGroup.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix) -MM Game/PropertyGroup.cpp

$(IntermediateDirectory)/Game_PropertyGroup.cpp$(PreprocessSuffix): Game/PropertyGroup.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyGroup.cpp$(PreprocessSuffix) Game/PropertyGroup.cpp

$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix): Protocol/OneofFieldParser.cpp $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OneofFieldParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix): Protocol/OneofFieldParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix) -MM Protocol/OneofFieldParser.cpp

$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(PreprocessSuffix): Protocol/OneofFieldParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(PreprocessSuffix) Protocol/OneofFieldParser.cpp

$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix): Game/GameComponent.cpp $(IntermediateDirectory)/Game_GameComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/GameComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameComponent.cpp$(DependSuffix): Game/GameComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameComponent.cpp$(DependSuffix) -MM Game/GameComponent.cpp

$(IntermediateDirectory)/Game_GameComponent.cpp$(PreprocessSuffix): Game/GameComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameComponent.cpp$(PreprocessSuffix) Game/GameComponent.cpp

$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix): Protocol/EnumValueModel.cpp $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/EnumValueModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix): Protocol/EnumValueModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix) -MM Protocol/EnumValueModel.cpp

$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(PreprocessSuffix): Protocol/EnumValueModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(PreprocessSuffix) Protocol/EnumValueModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix): Protocol/MessageFieldParser.cpp $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/MessageFieldParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix): Protocol/MessageFieldParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix) -MM Protocol/MessageFieldParser.cpp

$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(PreprocessSuffix): Protocol/MessageFieldParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(PreprocessSuffix) Protocol/MessageFieldParser.cpp

$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix): Protocol/MessageModel.cpp $(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/MessageModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix): Protocol/MessageModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix) -MM Protocol/MessageModel.cpp

$(IntermediateDirectory)/Protocol_MessageModel.cpp$(PreprocessSuffix): Protocol/MessageModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageModel.cpp$(PreprocessSuffix) Protocol/MessageModel.cpp

$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix): Protocol/OptionValueParser.cpp $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OptionValueParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix): Protocol/OptionValueParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix) -MM Protocol/OptionValueParser.cpp

$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(PreprocessSuffix): Protocol/OptionValueParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(PreprocessSuffix) Protocol/OptionValueParser.cpp

$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix): Protocol/ImportParser.cpp $(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/ImportParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix): Protocol/ImportParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix) -MM Protocol/ImportParser.cpp

$(IntermediateDirectory)/Protocol_ImportParser.cpp$(PreprocessSuffix): Protocol/ImportParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ImportParser.cpp$(PreprocessSuffix) Protocol/ImportParser.cpp

$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix): Protocol/OptionSingleParser.cpp $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OptionSingleParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix): Protocol/OptionSingleParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix) -MM Protocol/OptionSingleParser.cpp

$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(PreprocessSuffix): Protocol/OptionSingleParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(PreprocessSuffix) Protocol/OptionSingleParser.cpp

$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix): Game/PropertyValue.cpp $(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/PropertyValue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix): Game/PropertyValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix) -MM Game/PropertyValue.cpp

$(IntermediateDirectory)/Game_PropertyValue.cpp$(PreprocessSuffix): Game/PropertyValue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyValue.cpp$(PreprocessSuffix) Game/PropertyValue.cpp

$(IntermediateDirectory)/Curses_ListBox.cpp$(ObjectSuffix): Curses/ListBox.cpp $(IntermediateDirectory)/Curses_ListBox.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/ListBox.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_ListBox.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_ListBox.cpp$(DependSuffix): Curses/ListBox.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_ListBox.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_ListBox.cpp$(DependSuffix) -MM Curses/ListBox.cpp

$(IntermediateDirectory)/Curses_ListBox.cpp$(PreprocessSuffix): Curses/ListBox.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_ListBox.cpp$(PreprocessSuffix) Curses/ListBox.cpp

$(IntermediateDirectory)/Curses_Window.cpp$(ObjectSuffix): Curses/Window.cpp $(IntermediateDirectory)/Curses_Window.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/Window.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_Window.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_Window.cpp$(DependSuffix): Curses/Window.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_Window.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_Window.cpp$(DependSuffix) -MM Curses/Window.cpp

$(IntermediateDirectory)/Curses_Window.cpp$(PreprocessSuffix): Curses/Window.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_Window.cpp$(PreprocessSuffix) Curses/Window.cpp

$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix): Protocol/ProtoModel.cpp $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/ProtoModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix): Protocol/ProtoModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix) -MM Protocol/ProtoModel.cpp

$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(PreprocessSuffix): Protocol/ProtoModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(PreprocessSuffix) Protocol/ProtoModel.cpp

$(IntermediateDirectory)/Curses_TextRegion.cpp$(ObjectSuffix): Curses/TextRegion.cpp $(IntermediateDirectory)/Curses_TextRegion.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/TextRegion.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_TextRegion.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_TextRegion.cpp$(DependSuffix): Curses/TextRegion.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_TextRegion.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_TextRegion.cpp$(DependSuffix) -MM Curses/TextRegion.cpp

$(IntermediateDirectory)/Curses_TextRegion.cpp$(PreprocessSuffix): Curses/TextRegion.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_TextRegion.cpp$(PreprocessSuffix) Curses/TextRegion.cpp

$(IntermediateDirectory)/Curses_Button.cpp$(ObjectSuffix): Curses/Button.cpp $(IntermediateDirectory)/Curses_Button.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/Button.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_Button.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_Button.cpp$(DependSuffix): Curses/Button.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_Button.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_Button.cpp$(DependSuffix) -MM Curses/Button.cpp

$(IntermediateDirectory)/Curses_Button.cpp$(PreprocessSuffix): Curses/Button.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_Button.cpp$(PreprocessSuffix) Curses/Button.cpp

$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix): Log/LogManager.cpp $(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Log/LogManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix): Log/LogManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix) -MM Log/LogManager.cpp

$(IntermediateDirectory)/Log_LogManager.cpp$(PreprocessSuffix): Log/LogManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log_LogManager.cpp$(PreprocessSuffix) Log/LogManager.cpp

$(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix): Game/IPositionComponent.cpp $(IntermediateDirectory)/Game_IPositionComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/IPositionComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_IPositionComponent.cpp$(DependSuffix): Game/IPositionComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_IPositionComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_IPositionComponent.cpp$(DependSuffix) -MM Game/IPositionComponent.cpp

$(IntermediateDirectory)/Game_IPositionComponent.cpp$(PreprocessSuffix): Game/IPositionComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_IPositionComponent.cpp$(PreprocessSuffix) Game/IPositionComponent.cpp

$(IntermediateDirectory)/Curses_NumberBox.cpp$(ObjectSuffix): Curses/NumberBox.cpp $(IntermediateDirectory)/Curses_NumberBox.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/NumberBox.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_NumberBox.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_NumberBox.cpp$(DependSuffix): Curses/NumberBox.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_NumberBox.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_NumberBox.cpp$(DependSuffix) -MM Curses/NumberBox.cpp

$(IntermediateDirectory)/Curses_NumberBox.cpp$(PreprocessSuffix): Curses/NumberBox.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_NumberBox.cpp$(PreprocessSuffix) Curses/NumberBox.cpp

$(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix): Game/PositionComponent.cpp $(IntermediateDirectory)/Game_PositionComponent.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/PositionComponent.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PositionComponent.cpp$(DependSuffix): Game/PositionComponent.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PositionComponent.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PositionComponent.cpp$(DependSuffix) -MM Game/PositionComponent.cpp

$(IntermediateDirectory)/Game_PositionComponent.cpp$(PreprocessSuffix): Game/PositionComponent.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PositionComponent.cpp$(PreprocessSuffix) Game/PositionComponent.cpp

$(IntermediateDirectory)/Curses_Label.cpp$(ObjectSuffix): Curses/Label.cpp $(IntermediateDirectory)/Curses_Label.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/Label.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_Label.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_Label.cpp$(DependSuffix): Curses/Label.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_Label.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_Label.cpp$(DependSuffix) -MM Curses/Label.cpp

$(IntermediateDirectory)/Curses_Label.cpp$(PreprocessSuffix): Curses/Label.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_Label.cpp$(PreprocessSuffix) Curses/Label.cpp

$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix): Game/GameSystem.cpp $(IntermediateDirectory)/Game_GameSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/GameSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameSystem.cpp$(DependSuffix): Game/GameSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameSystem.cpp$(DependSuffix) -MM Game/GameSystem.cpp

$(IntermediateDirectory)/Game_GameSystem.cpp$(PreprocessSuffix): Game/GameSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameSystem.cpp$(PreprocessSuffix) Game/GameSystem.cpp

$(IntermediateDirectory)/Curses_DisplayBox.cpp$(ObjectSuffix): Curses/DisplayBox.cpp $(IntermediateDirectory)/Curses_DisplayBox.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/DisplayBox.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_DisplayBox.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_DisplayBox.cpp$(DependSuffix): Curses/DisplayBox.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_DisplayBox.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_DisplayBox.cpp$(DependSuffix) -MM Curses/DisplayBox.cpp

$(IntermediateDirectory)/Curses_DisplayBox.cpp$(PreprocessSuffix): Curses/DisplayBox.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_DisplayBox.cpp$(PreprocessSuffix) Curses/DisplayBox.cpp

$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix): Protocol/OptionGroupParser.cpp $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OptionGroupParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix): Protocol/OptionGroupParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix) -MM Protocol/OptionGroupParser.cpp

$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(PreprocessSuffix): Protocol/OptionGroupParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(PreprocessSuffix) Protocol/OptionGroupParser.cpp

$(IntermediateDirectory)/Curses_Colors.cpp$(ObjectSuffix): Curses/Colors.cpp $(IntermediateDirectory)/Curses_Colors.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/Colors.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_Colors.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_Colors.cpp$(DependSuffix): Curses/Colors.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_Colors.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_Colors.cpp$(DependSuffix) -MM Curses/Colors.cpp

$(IntermediateDirectory)/Curses_Colors.cpp$(PreprocessSuffix): Curses/Colors.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_Colors.cpp$(PreprocessSuffix) Curses/Colors.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix): Protocol/CodeGeneratorCPP.cpp $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/CodeGeneratorCPP.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix): Protocol/CodeGeneratorCPP.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix) -MM Protocol/CodeGeneratorCPP.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(PreprocessSuffix): Protocol/CodeGeneratorCPP.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(PreprocessSuffix) Protocol/CodeGeneratorCPP.cpp

$(IntermediateDirectory)/Curses_Visibility.cpp$(ObjectSuffix): Curses/Visibility.cpp $(IntermediateDirectory)/Curses_Visibility.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/Visibility.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_Visibility.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_Visibility.cpp$(DependSuffix): Curses/Visibility.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_Visibility.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_Visibility.cpp$(DependSuffix) -MM Curses/Visibility.cpp

$(IntermediateDirectory)/Curses_Visibility.cpp$(PreprocessSuffix): Curses/Visibility.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_Visibility.cpp$(PreprocessSuffix) Curses/Visibility.cpp

$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix): Text/TextUtil.cpp $(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Text/TextUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix): Text/TextUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix) -MM Text/TextUtil.cpp

$(IntermediateDirectory)/Text_TextUtil.cpp$(PreprocessSuffix): Text/TextUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_TextUtil.cpp$(PreprocessSuffix) Text/TextUtil.cpp

$(IntermediateDirectory)/Curses_CheckBox.cpp$(ObjectSuffix): Curses/CheckBox.cpp $(IntermediateDirectory)/Curses_CheckBox.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/CheckBox.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_CheckBox.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_CheckBox.cpp$(DependSuffix): Curses/CheckBox.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_CheckBox.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_CheckBox.cpp$(DependSuffix) -MM Curses/CheckBox.cpp

$(IntermediateDirectory)/Curses_CheckBox.cpp$(PreprocessSuffix): Curses/CheckBox.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_CheckBox.cpp$(PreprocessSuffix) Curses/CheckBox.cpp

$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix): Protocol/MessageParser.cpp $(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/MessageParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix): Protocol/MessageParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix) -MM Protocol/MessageParser.cpp

$(IntermediateDirectory)/Protocol_MessageParser.cpp$(PreprocessSuffix): Protocol/MessageParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageParser.cpp$(PreprocessSuffix) Protocol/MessageParser.cpp

$(IntermediateDirectory)/Curses_TextBox.cpp$(ObjectSuffix): Curses/TextBox.cpp $(IntermediateDirectory)/Curses_TextBox.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/TextBox.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_TextBox.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_TextBox.cpp$(DependSuffix): Curses/TextBox.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_TextBox.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_TextBox.cpp$(DependSuffix) -MM Curses/TextBox.cpp

$(IntermediateDirectory)/Curses_TextBox.cpp$(PreprocessSuffix): Curses/TextBox.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_TextBox.cpp$(PreprocessSuffix) Curses/TextBox.cpp

$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix): Protocol/ParserManager.cpp $(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/ParserManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix): Protocol/ParserManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix) -MM Protocol/ParserManager.cpp

$(IntermediateDirectory)/Protocol_ParserManager.cpp$(PreprocessSuffix): Protocol/ParserManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ParserManager.cpp$(PreprocessSuffix) Protocol/ParserManager.cpp

$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix): Protocol/EnumModel.cpp $(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/EnumModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix): Protocol/EnumModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix) -MM Protocol/EnumModel.cpp

$(IntermediateDirectory)/Protocol_EnumModel.cpp$(PreprocessSuffix): Protocol/EnumModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumModel.cpp$(PreprocessSuffix) Protocol/EnumModel.cpp

$(IntermediateDirectory)/Curses_ConsoleManager.cpp$(ObjectSuffix): Curses/ConsoleManager.cpp $(IntermediateDirectory)/Curses_ConsoleManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/ConsoleManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_ConsoleManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_ConsoleManager.cpp$(DependSuffix): Curses/ConsoleManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_ConsoleManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_ConsoleManager.cpp$(DependSuffix) -MM Curses/ConsoleManager.cpp

$(IntermediateDirectory)/Curses_ConsoleManager.cpp$(PreprocessSuffix): Curses/ConsoleManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_ConsoleManager.cpp$(PreprocessSuffix) Curses/ConsoleManager.cpp

$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix): Noise/NoiseUtil.cpp $(IntermediateDirectory)/Noise_NoiseUtil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Noise/NoiseUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(DependSuffix): Noise/NoiseUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(DependSuffix) -MM Noise/NoiseUtil.cpp

$(IntermediateDirectory)/Noise_NoiseUtil.cpp$(PreprocessSuffix): Noise/NoiseUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Noise_NoiseUtil.cpp$(PreprocessSuffix) Noise/NoiseUtil.cpp

$(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix): Noise/Noise.cpp $(IntermediateDirectory)/Noise_Noise.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Noise/Noise.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Noise_Noise.cpp$(DependSuffix): Noise/Noise.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Noise_Noise.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Noise_Noise.cpp$(DependSuffix) -MM Noise/Noise.cpp

$(IntermediateDirectory)/Noise_Noise.cpp$(PreprocessSuffix): Noise/Noise.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Noise_Noise.cpp$(PreprocessSuffix) Noise/Noise.cpp

$(IntermediateDirectory)/Curses_WindowSystem.cpp$(ObjectSuffix): Curses/WindowSystem.cpp $(IntermediateDirectory)/Curses_WindowSystem.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/WindowSystem.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_WindowSystem.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_WindowSystem.cpp$(DependSuffix): Curses/WindowSystem.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_WindowSystem.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_WindowSystem.cpp$(DependSuffix) -MM Curses/WindowSystem.cpp

$(IntermediateDirectory)/Curses_WindowSystem.cpp$(PreprocessSuffix): Curses/WindowSystem.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_WindowSystem.cpp$(PreprocessSuffix) Curses/WindowSystem.cpp

$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix): Game/PropertyContainer.cpp $(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Game/PropertyContainer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix): Game/PropertyContainer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix) -MM Game/PropertyContainer.cpp

$(IntermediateDirectory)/Game_PropertyContainer.cpp$(PreprocessSuffix): Game/PropertyContainer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyContainer.cpp$(PreprocessSuffix) Game/PropertyContainer.cpp

$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix): Protocol/EnumValueParser.cpp $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/EnumValueParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix): Protocol/EnumValueParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix) -MM Protocol/EnumValueParser.cpp

$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(PreprocessSuffix): Protocol/EnumValueParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(PreprocessSuffix) Protocol/EnumValueParser.cpp

$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix): Protocol/TokenReader.cpp $(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/TokenReader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix): Protocol/TokenReader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix) -MM Protocol/TokenReader.cpp

$(IntermediateDirectory)/Protocol_TokenReader.cpp$(PreprocessSuffix): Protocol/TokenReader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_TokenReader.cpp$(PreprocessSuffix) Protocol/TokenReader.cpp

$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix): Config/ConfigInfo.cpp $(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Config/ConfigInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix): Config/ConfigInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix) -MM Config/ConfigInfo.cpp

$(IntermediateDirectory)/Config_ConfigInfo.cpp$(PreprocessSuffix): Config/ConfigInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Config_ConfigInfo.cpp$(PreprocessSuffix) Config/ConfigInfo.cpp

$(IntermediateDirectory)/Curses_Control.cpp$(ObjectSuffix): Curses/Control.cpp $(IntermediateDirectory)/Curses_Control.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/Control.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_Control.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_Control.cpp$(DependSuffix): Curses/Control.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_Control.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_Control.cpp$(DependSuffix) -MM Curses/Control.cpp

$(IntermediateDirectory)/Curses_Control.cpp$(PreprocessSuffix): Curses/Control.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_Control.cpp$(PreprocessSuffix) Curses/Control.cpp

$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix): File/FileManager.cpp $(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/File/FileManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix): File/FileManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix) -MM File/FileManager.cpp

$(IntermediateDirectory)/File_FileManager.cpp$(PreprocessSuffix): File/FileManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/File_FileManager.cpp$(PreprocessSuffix) File/FileManager.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix): Protocol/CodeGeneratorManager.cpp $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/CodeGeneratorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix): Protocol/CodeGeneratorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix) -MM Protocol/CodeGeneratorManager.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(PreprocessSuffix): Protocol/CodeGeneratorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(PreprocessSuffix) Protocol/CodeGeneratorManager.cpp

$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix): Protocol/OneofModel.cpp $(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OneofModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix): Protocol/OneofModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix) -MM Protocol/OneofModel.cpp

$(IntermediateDirectory)/Protocol_OneofModel.cpp$(PreprocessSuffix): Protocol/OneofModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofModel.cpp$(PreprocessSuffix) Protocol/OneofModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix): Protocol/MessageFieldModel.cpp $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/MessageFieldModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix): Protocol/MessageFieldModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix) -MM Protocol/MessageFieldModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(PreprocessSuffix): Protocol/MessageFieldModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(PreprocessSuffix) Protocol/MessageFieldModel.cpp

$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix): Protocol/OptionModel.cpp $(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/OptionModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix): Protocol/OptionModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix) -MM Protocol/OptionModel.cpp

$(IntermediateDirectory)/Protocol_OptionModel.cpp$(PreprocessSuffix): Protocol/OptionModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionModel.cpp$(PreprocessSuffix) Protocol/OptionModel.cpp

$(IntermediateDirectory)/Curses_CursesUtil.cpp$(ObjectSuffix): Curses/CursesUtil.cpp $(IntermediateDirectory)/Curses_CursesUtil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Curses/CursesUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Curses_CursesUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Curses_CursesUtil.cpp$(DependSuffix): Curses/CursesUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Curses_CursesUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Curses_CursesUtil.cpp$(DependSuffix) -MM Curses/CursesUtil.cpp

$(IntermediateDirectory)/Curses_CursesUtil.cpp$(PreprocessSuffix): Curses/CursesUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Curses_CursesUtil.cpp$(PreprocessSuffix) Curses/CursesUtil.cpp

$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix): Protocol/ProtoParser.cpp $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/aboqa/submodules/TUCUT/Protocol/ProtoParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix): Protocol/ProtoParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix) -MM Protocol/ProtoParser.cpp

$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(PreprocessSuffix): Protocol/ProtoParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(PreprocessSuffix) Protocol/ProtoParser.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


