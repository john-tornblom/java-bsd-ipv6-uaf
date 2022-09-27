#include <unistd.h>
#include <fcntl.h>
#include <sys/event.h>
#include <string.h>
#include <sys/socket.h>
#include <jni.h>


JNIEXPORT jlong JNICALL
Java_libkernel_usleep(JNIEnv *env, jclass cls, jint usec) {
  return usleep(usec);
}


JNIEXPORT jint JNICALL
Java_libkernel_open(JNIEnv *env, jclass cls, jstring path, jint flags) {
  const char *buf = (*env)->GetStringUTFChars(env, path, 0);
   int fd = open(buf, flags);
   (*env)->ReleaseStringUTFChars(env, path, buf);
   return fd;
}


JNIEXPORT jlong JNICALL
Java_libkernel_lseek(JNIEnv *env, jclass cls, jint fd, jlong offset,
		     jint whence) {
  return lseek(fd, offset, whence);
}


JNIEXPORT jlong JNICALL
Java_libkernel_write(JNIEnv *env, jclass cls, jint fd, jlong buf, jint count) {
  return write(fd, (void*)buf, count);
}


JNIEXPORT jint JNICALL
Java_libkernel_close(JNIEnv *env, jclass cls, jint fd) {
  return close(fd);
}


JNIEXPORT jint JNICALL
Java_libkernel_getpid(JNIEnv *env, jclass cls) {
  return getpid();
}


JNIEXPORT jint JNICALL
Java_libkernel_kqueue(JNIEnv *env, jclass cls) {
  return kqueue();
}


JNIEXPORT jint JNICALL
Java_libkernel_kevent(JNIEnv *env, jclass cls, jint kg, jlong changelist,
		      jint nchanges, jlong eventlist, jint nevents,
		      jlong timeout) {
  return kevent(kg, (void*)changelist, nchanges, (void*)eventlist, nevents,
		(void*)timeout);
}


JNIEXPORT jlong JNICALL
Java_libkernel_memset(JNIEnv *env, jclass cls, jlong dest, jint c, jlong len) {
  return (jlong)memset((void*)dest, c, len);
}


JNIEXPORT jint JNICALL
Java_libkernel_socket(JNIEnv *env, jclass cls, jint domain, jint type,
		      jint protocol) {
  return socket(domain, type, protocol);
}


JNIEXPORT jint JNICALL
Java_libkernel_getsockopt(JNIEnv *env, jclass cls, jint sockfd, jint level,
			  jint optname, jlong optval, jlong optlen) {
  return getsockopt(sockfd, level, optname, (void*)optval, (void*)optlen);
}


JNIEXPORT jint JNICALL
Java_libkernel_setsockopt(JNIEnv *env, jclass cls, jint sockfd, jint level,
			  jint optname, jlong optval, jint optlen) {
  return setsockopt(sockfd, level, optname, (void*)optval, optlen);
}

