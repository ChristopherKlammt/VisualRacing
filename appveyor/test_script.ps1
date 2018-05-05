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
gcovr -r

echo "Running gcovr XML"
gcovr -r --xml-pretty -o coverage.xml

dir

popd