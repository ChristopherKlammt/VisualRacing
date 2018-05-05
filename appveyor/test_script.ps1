pushd VRTest/debug
echo "Running Tests"
.\tst_vrtest.exe
.\tst_vrtest.exe -xunitxml > tests.xml

#$folder = Get-ChildItem -Path *.cpp

# Loop through each file
#foreach ($file in $folder) {
#    gcov $file
#}
#dir
echo "Running gcovr"
python C:\Python36\Scripts\gcovr

echo "Running gcovr XML"
python C:\Python36\Scripts\gcovr -x > coverage.xml

dir

popd