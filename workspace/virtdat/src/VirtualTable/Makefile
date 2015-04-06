all: VirtColum VirtualTable VirtualTableMetadata VritualIntegrityChecker
VritualIntegrityChecker:
	c++ VritualIntegrityChecker.cpp -std=c++11 -c
VirtualTableMetadata:
	c++ VirtualTableMetadata.cpp -std=c++11 -c
VirtColum:
	c++ VirtColum.cpp -std=c++11 -c
VirtualTable:
	c++ VirtualTable.cpp -std=c++11 -c
clean:
	$(RM) VirtColum.o VirtualTable.o VirtualTableMetadata.o VritualIntegrityChecker.o 
