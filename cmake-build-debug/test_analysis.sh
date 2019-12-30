/home/daniele/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5233.144/bin/cmake/linux/bin/cmake --build /home/daniele/CLionProjects/Algorithm_Project_2019/cmake-build-debug --target Algorithm_Project_2019 -- -j 2

echo start doing testing
for i in {0..10000..20}
	do
		echo doing test $i
		./Algorithm_Project_2019 $i >> result.txt
	done