echo "Running gcovr"
python C:\Python27\Scripts\gcovr --xml-pretty

echo "Running gcovr XML"
python C:\Python27\Scripts\gcovr --xml -o coverage.xml

Invoke-WebRequest -Uri 'https://codecov.io/bash' -OutFile codecov.sh
bash codecov.sh -f "coverage.xml"