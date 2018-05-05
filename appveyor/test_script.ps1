pushd VRTest/debug
echo "Running Tests"
.\tst_vrtest.exe
.\tst_vrtest.exe -xunitxml > tests.xml
popd