##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=s-TUCUT
ConfigurationName      :=Debug
WorkspacePath          :=/home/wahid/Storage/GitHub/TUCUT
ProjectPath            :=/home/wahid/Storage/GitHub/TUCUT
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Wahid Tanner
Date                   :=17/09/18
CodeLitePath           :=/home/wahid/.codelite
LinkerName             :=/usr/bin/clang++
SharedObjectLinkerName :=/usr/bin/clang++ -shared -fPIC
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
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/llvm-ar rcu
CXX      := /usr/bin/clang++
CC       := /usr/bin/clang
CXXFLAGS :=  -g -std=c++14 -stdlib=libc++ $(Preprocessors)
CFLAGS   :=  -g $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/llvm-as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) $(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Game_GameObjectManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) \
	$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(IntermediateDirectory) $(OutputFile)

$(OutputFile): $(Objects)
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(AR) $(ArchiveOutputSwitch)$(OutputFile) @$(ObjectsFileList) $(ArLibs)
	@$(MakeDirCommand) "/home/wahid/Storage/GitHub/TUCUT/.build-debug"
	@echo rebuilt > "/home/wahid/Storage/GitHub/TUCUT/.build-debug/s-TUCUT"

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


./Debug:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix): Config/ConfigInfo.cpp $(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Config/ConfigInfo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix): Config/ConfigInfo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Config_ConfigInfo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Config_ConfigInfo.cpp$(DependSuffix) -MM Config/ConfigInfo.cpp

$(IntermediateDirectory)/Config_ConfigInfo.cpp$(PreprocessSuffix): Config/ConfigInfo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Config_ConfigInfo.cpp$(PreprocessSuffix) Config/ConfigInfo.cpp

$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix): Log/LogManager.cpp $(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Log/LogManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix): Log/LogManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Log_LogManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Log_LogManager.cpp$(DependSuffix) -MM Log/LogManager.cpp

$(IntermediateDirectory)/Log_LogManager.cpp$(PreprocessSuffix): Log/LogManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Log_LogManager.cpp$(PreprocessSuffix) Log/LogManager.cpp

$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix): Protocol/ProtoParser.cpp $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/ProtoParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix): Protocol/ProtoParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(DependSuffix) -MM Protocol/ProtoParser.cpp

$(IntermediateDirectory)/Protocol_ProtoParser.cpp$(PreprocessSuffix): Protocol/ProtoParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ProtoParser.cpp$(PreprocessSuffix) Protocol/ProtoParser.cpp

$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix): Protocol/TokenReader.cpp $(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/TokenReader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix): Protocol/TokenReader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_TokenReader.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_TokenReader.cpp$(DependSuffix) -MM Protocol/TokenReader.cpp

$(IntermediateDirectory)/Protocol_TokenReader.cpp$(PreprocessSuffix): Protocol/TokenReader.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_TokenReader.cpp$(PreprocessSuffix) Protocol/TokenReader.cpp

$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix): Protocol/OptionSingleParser.cpp $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OptionSingleParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix): Protocol/OptionSingleParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(DependSuffix) -MM Protocol/OptionSingleParser.cpp

$(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(PreprocessSuffix): Protocol/OptionSingleParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionSingleParser.cpp$(PreprocessSuffix) Protocol/OptionSingleParser.cpp

$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix): Protocol/OneofParser.cpp $(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OneofParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix): Protocol/OneofParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofParser.cpp$(DependSuffix) -MM Protocol/OneofParser.cpp

$(IntermediateDirectory)/Protocol_OneofParser.cpp$(PreprocessSuffix): Protocol/OneofParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofParser.cpp$(PreprocessSuffix) Protocol/OneofParser.cpp

$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix): Protocol/MessageModel.cpp $(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/MessageModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix): Protocol/MessageModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageModel.cpp$(DependSuffix) -MM Protocol/MessageModel.cpp

$(IntermediateDirectory)/Protocol_MessageModel.cpp$(PreprocessSuffix): Protocol/MessageModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageModel.cpp$(PreprocessSuffix) Protocol/MessageModel.cpp

$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix): Protocol/OneofFieldParser.cpp $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OneofFieldParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix): Protocol/OneofFieldParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(DependSuffix) -MM Protocol/OneofFieldParser.cpp

$(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(PreprocessSuffix): Protocol/OneofFieldParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofFieldParser.cpp$(PreprocessSuffix) Protocol/OneofFieldParser.cpp

$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix): Protocol/OptionValueParser.cpp $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OptionValueParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix): Protocol/OptionValueParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(DependSuffix) -MM Protocol/OptionValueParser.cpp

$(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(PreprocessSuffix): Protocol/OptionValueParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionValueParser.cpp$(PreprocessSuffix) Protocol/OptionValueParser.cpp

$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix): Game/PropertyContainer.cpp $(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/PropertyContainer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix): Game/PropertyContainer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyContainer.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyContainer.cpp$(DependSuffix) -MM Game/PropertyContainer.cpp

$(IntermediateDirectory)/Game_PropertyContainer.cpp$(PreprocessSuffix): Game/PropertyContainer.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyContainer.cpp$(PreprocessSuffix) Game/PropertyContainer.cpp

$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix): Game/PropertyGroup.cpp $(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/PropertyGroup.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix): Game/PropertyGroup.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyGroup.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyGroup.cpp$(DependSuffix) -MM Game/PropertyGroup.cpp

$(IntermediateDirectory)/Game_PropertyGroup.cpp$(PreprocessSuffix): Game/PropertyGroup.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyGroup.cpp$(PreprocessSuffix) Game/PropertyGroup.cpp

$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix): Game/PropertyValue.cpp $(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/PropertyValue.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix): Game/PropertyValue.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_PropertyValue.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_PropertyValue.cpp$(DependSuffix) -MM Game/PropertyValue.cpp

$(IntermediateDirectory)/Game_PropertyValue.cpp$(PreprocessSuffix): Game/PropertyValue.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_PropertyValue.cpp$(PreprocessSuffix) Game/PropertyValue.cpp

$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix): Protocol/OptionModel.cpp $(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OptionModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix): Protocol/OptionModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionModel.cpp$(DependSuffix) -MM Protocol/OptionModel.cpp

$(IntermediateDirectory)/Protocol_OptionModel.cpp$(PreprocessSuffix): Protocol/OptionModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionModel.cpp$(PreprocessSuffix) Protocol/OptionModel.cpp

$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix): Text/TextUtil.cpp $(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Text/TextUtil.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix): Text/TextUtil.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Text_TextUtil.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Text_TextUtil.cpp$(DependSuffix) -MM Text/TextUtil.cpp

$(IntermediateDirectory)/Text_TextUtil.cpp$(PreprocessSuffix): Text/TextUtil.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Text_TextUtil.cpp$(PreprocessSuffix) Text/TextUtil.cpp

$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix): Protocol/PackageParser.cpp $(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/PackageParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix): Protocol/PackageParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_PackageParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_PackageParser.cpp$(DependSuffix) -MM Protocol/PackageParser.cpp

$(IntermediateDirectory)/Protocol_PackageParser.cpp$(PreprocessSuffix): Protocol/PackageParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_PackageParser.cpp$(PreprocessSuffix) Protocol/PackageParser.cpp

$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix): Protocol/OneofModel.cpp $(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OneofModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix): Protocol/OneofModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OneofModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OneofModel.cpp$(DependSuffix) -MM Protocol/OneofModel.cpp

$(IntermediateDirectory)/Protocol_OneofModel.cpp$(PreprocessSuffix): Protocol/OneofModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OneofModel.cpp$(PreprocessSuffix) Protocol/OneofModel.cpp

$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix): Protocol/EnumParser.cpp $(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/EnumParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix): Protocol/EnumParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumParser.cpp$(DependSuffix) -MM Protocol/EnumParser.cpp

$(IntermediateDirectory)/Protocol_EnumParser.cpp$(PreprocessSuffix): Protocol/EnumParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumParser.cpp$(PreprocessSuffix) Protocol/EnumParser.cpp

$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix): Protocol/ProtoModel.cpp $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/ProtoModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix): Protocol/ProtoModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(DependSuffix) -MM Protocol/ProtoModel.cpp

$(IntermediateDirectory)/Protocol_ProtoModel.cpp$(PreprocessSuffix): Protocol/ProtoModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ProtoModel.cpp$(PreprocessSuffix) Protocol/ProtoModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix): Protocol/MessageFieldModel.cpp $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/MessageFieldModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix): Protocol/MessageFieldModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(DependSuffix) -MM Protocol/MessageFieldModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(PreprocessSuffix): Protocol/MessageFieldModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageFieldModel.cpp$(PreprocessSuffix) Protocol/MessageFieldModel.cpp

$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix): Game/GameObject.cpp $(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/GameObject.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix): Game/GameObject.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameObject.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameObject.cpp$(DependSuffix) -MM Game/GameObject.cpp

$(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix): Game/GameObject.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameObject.cpp$(PreprocessSuffix) Game/GameObject.cpp

$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix): Protocol/EnumModel.cpp $(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/EnumModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix): Protocol/EnumModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumModel.cpp$(DependSuffix) -MM Protocol/EnumModel.cpp

$(IntermediateDirectory)/Protocol_EnumModel.cpp$(PreprocessSuffix): Protocol/EnumModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumModel.cpp$(PreprocessSuffix) Protocol/EnumModel.cpp

$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix): Protocol/OptionGroupParser.cpp $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/OptionGroupParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix): Protocol/OptionGroupParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(DependSuffix) -MM Protocol/OptionGroupParser.cpp

$(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(PreprocessSuffix): Protocol/OptionGroupParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_OptionGroupParser.cpp$(PreprocessSuffix) Protocol/OptionGroupParser.cpp

$(IntermediateDirectory)/Game_GameObjectManager.cpp$(ObjectSuffix): Game/GameObjectManager.cpp $(IntermediateDirectory)/Game_GameObjectManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Game/GameObjectManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Game_GameObjectManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Game_GameObjectManager.cpp$(DependSuffix): Game/GameObjectManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Game_GameObjectManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Game_GameObjectManager.cpp$(DependSuffix) -MM Game/GameObjectManager.cpp

$(IntermediateDirectory)/Game_GameObjectManager.cpp$(PreprocessSuffix): Game/GameObjectManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Game_GameObjectManager.cpp$(PreprocessSuffix) Game/GameObjectManager.cpp

$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix): Protocol/EnumValueModel.cpp $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/EnumValueModel.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix): Protocol/EnumValueModel.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(DependSuffix) -MM Protocol/EnumValueModel.cpp

$(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(PreprocessSuffix): Protocol/EnumValueModel.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumValueModel.cpp$(PreprocessSuffix) Protocol/EnumValueModel.cpp

$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix): Protocol/MessageFieldParser.cpp $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/MessageFieldParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix): Protocol/MessageFieldParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(DependSuffix) -MM Protocol/MessageFieldParser.cpp

$(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(PreprocessSuffix): Protocol/MessageFieldParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageFieldParser.cpp$(PreprocessSuffix) Protocol/MessageFieldParser.cpp

$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix): Protocol/ImportParser.cpp $(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/ImportParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix): Protocol/ImportParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ImportParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ImportParser.cpp$(DependSuffix) -MM Protocol/ImportParser.cpp

$(IntermediateDirectory)/Protocol_ImportParser.cpp$(PreprocessSuffix): Protocol/ImportParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ImportParser.cpp$(PreprocessSuffix) Protocol/ImportParser.cpp

$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix): Protocol/ParserManager.cpp $(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/ParserManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix): Protocol/ParserManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_ParserManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_ParserManager.cpp$(DependSuffix) -MM Protocol/ParserManager.cpp

$(IntermediateDirectory)/Protocol_ParserManager.cpp$(PreprocessSuffix): Protocol/ParserManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_ParserManager.cpp$(PreprocessSuffix) Protocol/ParserManager.cpp

$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix): File/FileManager.cpp $(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/File/FileManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix): File/FileManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/File_FileManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/File_FileManager.cpp$(DependSuffix) -MM File/FileManager.cpp

$(IntermediateDirectory)/File_FileManager.cpp$(PreprocessSuffix): File/FileManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/File_FileManager.cpp$(PreprocessSuffix) File/FileManager.cpp

$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix): Protocol/MessageParser.cpp $(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/MessageParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix): Protocol/MessageParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_MessageParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_MessageParser.cpp$(DependSuffix) -MM Protocol/MessageParser.cpp

$(IntermediateDirectory)/Protocol_MessageParser.cpp$(PreprocessSuffix): Protocol/MessageParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_MessageParser.cpp$(PreprocessSuffix) Protocol/MessageParser.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix): Protocol/CodeGeneratorCPP.cpp $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/CodeGeneratorCPP.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix): Protocol/CodeGeneratorCPP.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(DependSuffix) -MM Protocol/CodeGeneratorCPP.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(PreprocessSuffix): Protocol/CodeGeneratorCPP.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_CodeGeneratorCPP.cpp$(PreprocessSuffix) Protocol/CodeGeneratorCPP.cpp

$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix): Protocol/EnumValueParser.cpp $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/EnumValueParser.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix): Protocol/EnumValueParser.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(DependSuffix) -MM Protocol/EnumValueParser.cpp

$(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(PreprocessSuffix): Protocol/EnumValueParser.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_EnumValueParser.cpp$(PreprocessSuffix) Protocol/EnumValueParser.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix): Protocol/CodeGeneratorManager.cpp $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/wahid/Storage/GitHub/TUCUT/Protocol/CodeGeneratorManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix): Protocol/CodeGeneratorManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(DependSuffix) -MM Protocol/CodeGeneratorManager.cpp

$(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(PreprocessSuffix): Protocol/CodeGeneratorManager.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Protocol_CodeGeneratorManager.cpp$(PreprocessSuffix) Protocol/CodeGeneratorManager.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


