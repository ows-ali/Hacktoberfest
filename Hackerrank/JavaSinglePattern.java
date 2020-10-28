
public class JavaSinglePattern {
	public static void main(String[] args) {
		String strCompare = "Hello I am a singleton! Let me say hello world to you";
		
		Singleton singleton1 = Singleton.getSingleInstance();
		System.out.println(singleton1.str +" and this is my hashcode: "+ singleton1.hashCode());
		
		Singleton singleton2 = Singleton.getSingleInstance();
		System.out.println(singleton2.str +" and this is my hashcode: "+ singleton2.hashCode());
		
		if (singleton2.str.equals(strCompare)){
			System.out.println(" The value of my local variable is equal to the the singleton");
			if (singleton2.str == strCompare){
				System.out.println(" But it is not the same object, hashcode : " + strCompare.hashCode());
			}
		}
		
	}

}

class Singleton {
	
	private static volatile Singleton singleton; //volatile helps to prevent cache incoherence issues
	
	public String str = "Hello I am a singleton! Let me say hello world to you";
	
	private Singleton() {
		
	}
	
	public static Singleton getSingleInstance() {
		
		//Added double check locking
		if (null == singleton) {
			synchronized (Singleton.class) {
				if (null == singleton){
					 singleton = new Singleton();
				}
			}
			 
		}
		
		return singleton;
	}
}