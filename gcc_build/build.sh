mkdir -p build
cd build

############################################## UNITY BUILD ####################################################
#
# g++ -std=c++11 -m32 -DPLATFORM_LINUX -DCALL_CONVENTION_CDECL -DUNITY_BUILD ../../main.cpp -o main_unity_build
#
###############################################################################################################


########################################## Building a static LIB ################################################
# 
# g++ -std=c++11 -m32 -c -DBUILD_STATIC_LIB -DPLATFORM_LINUX -DCALL_CONVENTION_CDECL ../../vectors.cpp -o vectors.o
#
# ar rs libvectors.a vectors.o
#
# g++ -std=c++11 -m32 -DPLATFORM_LINUX -DCALL_CONVENTION_CDECL ../../main.cpp -L./ -lvectors -o main_static_lib_build
#
##################################################################################################################


################################################## Building a dll ################################################
# 
# g++ -std=c++11 -m64 -c -DBUILD_DLL -DPLATFORM_LINUX -fpic -c ../../vectors.cpp -o vectors.o
#
# g++ -m64 -shared -o libvectors.so vectors.o
#
# g++ -std=c++11 -m64 -DPLATFORM_LINUX -DUSING_DLL ../../main.cpp -o main_shared_lib_build -ldl
##################################################################################################################

cd ..


