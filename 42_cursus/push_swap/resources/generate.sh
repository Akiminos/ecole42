#!/bin/bash

echo "#!/bin/bash" > run.sh
echo "" >> run.sh
python ./resources/rand_gen.py $1 $2 $3
chmod 755 run.sh
./run.sh
