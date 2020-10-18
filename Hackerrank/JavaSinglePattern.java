

public class JavaSinglePattern {
	
	public static void main(String[] args) {
		Singleton singleton1 = Singleton.getSingleInstance();
		System.out.println(singleton1.str);
		
		Singleton singleton2 = Singleton.getSingleInstance();
		System.out.println(singleton2.str);
	}

}

class Singleton {
	
	private static Singleton singleton;
	
	public String str = "Hello I am a singleton! Let me say hello world to you";
	
	private Singleton() {
		
	}
	
	public static Singleton getSingleInstance() {
		
		if (null == singleton) {
			singleton = new Singleton();
		}
		
		return singleton;
	}
}
