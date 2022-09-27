public class libkernel {

    static {
        System.loadLibrary("kernel");
    }
    
    public static native long usleep(int usec);
    
    public static native int open(String path, int flags);
    
    public static native long lseek(int fd, long offset, int whence);
    
    public static native long write(int fd, long buf, int count);
    
    public static native int close(int fd);

    public static native int getpid();
    
    public static native int kqueue();
    
    public static native int kevent(int kq, long changelist, int nchanges,
				    long eventlist, int nevents, long timeout);
    
    public static native long memset(long dest, int c, long len);
    
    public static native int socket(int domain, int type, int protocol);

    public static native int getsockopt(int sockfd, int level, int optname, long optval,
					long optlen);

    public static native int setsockopt(int sockfd, int level, int optname, long optval,
					int optlen);
}

