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
python C:\Python27\Scripts\gcovr

echo "Running gcovr XML"
python C:\Python27\Scripts\gcovr -x > coverage.xml

Invoke-WebRequest -Uri 'https://codecov.io/bash' -OutFile codecov.sh
bash codecov.sh -f "coverage.xml"

dir

popd