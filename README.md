# embed_qt

If you are not familiar with Eclipse plugin development, here are the steps you need to perform before you can reproduce the behaviour I'm experiencing.

SET UP JAVA
1. Download openjdk from
https://download.java.net/java/GA/jdk11/9/GPL/openjdk-11.0.2_windows-x64_bin.zip and extract the archive
2. Create an environment variable JAVA_HOME and point it to the directory
where you extracted openjdk
3. Add %JAVA_HOME%\bin to your PATH environment variable

BUILD QtWinMigrate
1. Clone https://github.com/qtproject/qt-solutions
2. cd qtwinmigrate
3. configure -library (this will built the required dll)
4. Run qmake and nmake

BUILD PLUGIN's NATIVE CODE
1. cd com.foo.test/cpp
2. Amend the QtWinMigrate INCLUDEPATH and LIBS paths in the native.pro to point to your installation
3. Run qmake and nmake

SET UP ECLIPSE
1. Download eclipse from https://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/2020-06/R/eclipse-rcp-2020-06-R-win32-x86_64.zip
2. Extract the archive, cd into the extracted directory and double click eclipse.exe
3. It will prompt you to select a directory for your workspace; choose one and check “Use this as the default and do not ask again”. Eclipse will launch; you can close the Welcome page.
4. From the left (Project Explorer tab), click “Import projects…”
5. Select "Plugin-in Development->Plug-ins and Fragments"
6. In the “Import From” group, select Directory and point to the eclipse_plugin folder from this repo
7. In the "Plugin-ins and Fragments to Import", select from all plug-ins and fragments found at the specified location
8. In the “Import As” group, choose "Projects with source folders"
9. Click Next. In the “Plug-ins and Fragments Found”, select the com.foo.test plugin and click "Add" and then "Finish". You should see “com.foo.test” appear in the project explorer tab.
10. Expand the com.foo.test->src->com.lgc.foo.handlers and double click
on FooHandler.java. This will open the text editor.
11. Change the paths in lines 14 and 15 to point to the directories where you’ve built QtWinMigrate and the native.dll.
12. From the menubar, click Run->Run Configurations…. Double click “Eclipse Application” from the left, click Run on the window that will appear.
13. A new instance of Eclipse will launch where the plugin will be installed.
14. From the menubar, go to “Qt->Launch”. This will bring
up an Eclipse window where I've embedded my Qt widget (painted with a black
background).
15. Click anywhere in the widget's background, the dialog will appear.
16. Try closing it, you’ll see it’s not responding.
17. Try to resize it or click anywhere outside the application, you’ll see the
dialog will close.

You'll need to have the directory where the Qt5 dlls live somewhere in your
%PATH% variable, otherwise Java won't be able to load QtWinMigrate and the
plugin's ddl (native.dll).

Please let me know if there any questions.
