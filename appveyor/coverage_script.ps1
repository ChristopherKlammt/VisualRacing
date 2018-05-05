echo "Running gcovr and outputting XML" # excluding tst_...cpp & header-files
python C:\Python27\Scripts\gcovr --gcov-exclude=".*tst.*\.cpp" --gcov-exclude=".*\.h" --xml -o coverage.xml

Invoke-WebRequest -Uri 'https://codecov.io/bash' -OutFile codecov.sh
bash codecov.sh -f "coverage.xml"