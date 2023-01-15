FROM_CD="/media/cdrom"
INSTALLATION_PATH="$HOME/Games/CMR2"
NAME_OF_GAME="CMR2"
CURRENT_FOLDER="$PWD"

mkdir -p "/tmp/downloads"
mkdir -p "$INSTALLATION_PATH"

FILE="/tmp/downloads/silentpatch_cmr2.zip"
if [ ! -f $FILE ]; then
   wget https://github.com/CookiePLMonster/SilentPatchCMR2/releases/latest/download/silentpatch_cmr2.zip -O $FILE
	if [ ! -f $FILE ]; then
		echo "Can't download file"
		exit;
	fi
fi

unshield x $FROM_CD/data1.cab -d $INSTALLATION_PATH
cd $INSTALLATION_PATH
rm -r _Engine_Log_Services_Placeholder "_Support_French_(Standard)_Files" "_Support_French_(Standard)_String_Tables" _Support_German_Files
rm -r _Support_German_String_Tables _Support_Italian_Files _Support_Italian_String_Tables _Support_Spanish_Files _Support_Spanish_String_Tables
mv */* .
find . -type d -empty -delete
mkdir Configuration
mkdir gamesave
mkdir Networkleaderboards
mkdir pps
mkdir Replays
cp -r $FROM_CD/Game $INSTALLATION_PATH
cp -r $FROM_CD/SetupRep $INSTALLATION_PATH
cp -r $FROM_CD/Sounds $INSTALLATION_PATH
cp -r $FROM_CD/FrontEnd $INSTALLATION_PATH
cp -r $FROM_CD/CountrySpecific $INSTALLATION_PATH
rm $INSTALLATION_PATH/CMR2.exe
unzip -o /tmp/silentpatch_cmr2.zip -d $INSTALLATION_PATH
cp $CURRENT_FOLDER/GameInfo.rcf $INSTALLATION_PATH/Configuration
cp $CURRENT_FOLDER/Controller.rcf $INSTALLATION_PATH/Configuration
