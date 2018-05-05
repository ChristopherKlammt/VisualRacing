echo "Running gcovr and outputting XML"
python C:\Python27\Scripts\gcovr --xml -o coverage.xml

Invoke-WebRequest -Uri 'https://codecov.io/bash' -OutFile codecov.sh
bash codecov.sh -f "coverage.xml"