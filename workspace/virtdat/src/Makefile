all: 
	
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Компилиране и асемблиране на модула за виртуалните таблици  !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cd VirtualTable; make
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Компилиране и асемблиране на модула за съхранение и прехвърляне на мета данни  !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cd SerializationManager; make
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Компилиране и асемблиране на модула за интернет комуникация !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cd InternetModule; make
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Компилиране и асемблиране на конверциония модул !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	#cd Convertor; make
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Компилиране и асемблиране на графичния модул !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	#cd GuiModule; make
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Компилиране и асемблиране на модула за командване и контрол на сървъра за виртуализация на данни  !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	cd CommandAndControllModule; make
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	@echo !!!   Сглобяване на всички модули !!!
	@echo !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	g++ -L/home/x000ff4/workspace/virtdat/src/VirtualTable/  -L/home/x000ff4/workspace/virtdat/src/Convertor/ -L/home/x000ff4/workspace/virtdat/src/GuiModule/  -L/home/x000ff4/workspace/virtdat/src/SerializationManager/  -L/home/x000ff4/workspace/virtdat/src/InternetModule/  -L/home/x000ff4/workspace/virtdat/src/CommandAndControllModule/ -o virtdata CommandAndControllModule/CommandAndControll.o CommandAndControllModule/VirtTableHolder.o   GuiModule/NewVirtTable.o GuiModule/LineParams.o GuiModule/main.o VirtualTable/VirtColum.o VirtualTable/VirtualTable.o VirtualTable/VirtualTableMetadata.o VirtualTable/VritualIntegrityChecker.o InternetModule/ClientModule.o InternetModule/Commands.o InternetModule/MainServer.o InternetModule/ServerModule.o Convertor/JsonConvertor.o -lssl -ldl -lcrypto `pkg-config  --cflags --libs gtk+-3.0`
clean:
	cd CommandAndControllModule; make clean
	cd VirtualTable; make clean
	cd GuiModule; make clean
