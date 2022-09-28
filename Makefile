all: libkernel.so classes

classes: KernelExploit.class NativeMemory.class libkernel.class

libkernel.so: libkernel.c
	cc -I/usr/local/openjdk8/include -I/usr/local/openjdk8/include/freebsd -shared -fPIC -o $@ libkernel.c

KernelExploit.class: KernelExploit.java
	javac KernelExploit.java

NativeMemory.class: NativeMemory.java
	javac NativeMemory.java

libkernel.class: libkernel.java
	javac libkernel.java

test: classes libkernel.so
	java -Djava.library.path=. KernelExploit

clean:
	rm -f *.class *.so
