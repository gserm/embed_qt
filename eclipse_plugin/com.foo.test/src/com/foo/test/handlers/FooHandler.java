package com.foo.test.handlers;

import org.eclipse.core.commands.AbstractHandler;
import org.eclipse.core.commands.ExecutionEvent;
import org.eclipse.core.commands.ExecutionException;
import org.eclipse.swt.widgets.Shell;

public class FooHandler extends AbstractHandler {

private native void embedQtWidget(long parentHandle);
	
	static {
		// Change these paths accordingly
		System.load("D:/development/qtwinmigrate/5/lib/QtSolutions_MFCMigrationFramework-headd.dll");
		System.load("D:/eclipse-workspace/com.foo.test/cpp/debug/native.dll");
	}

	@Override
	public Object execute(ExecutionEvent event) throws ExecutionException {

		Shell shell = new Shell();
		shell.open();
		embedQtWidget(shell.handle);
		
		return null;
	}
}
