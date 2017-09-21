class ProducerConsumer{
	int n;
	boolean valueSet=false;
	synchronized int get(){
		if(!valueSet)	
		try{
			wait();
			Thread.sleep(1500);
		}
		catch(InterruptedException e){
			System.out.println(e);
		}

		System.out.println("Consumed: "+n);
		valueSet=false;
		notify();
		return n;
	}
	synchronized void put(int n){	if(valueSet)
		try{
			wait();
			Thread.sleep(1500);
		}
		catch (InterruptedException e){
			System.out.println(e);
		}

		this.n=n;
		valueSet=true;

		System.out.println("Produced: "+n);
		notify();
	}
}
class Producer implements Runnable{

	ProducerConsumer q;
	Producer(ProducerConsumer q){
		this.q=q;
		new Thread(this,"Producer").start();
	}
	public void run(){

		int i=0;
		while(true){
			q.put(i++);
		}
	}
}
class Consumer implements Runnable{

	ProducerConsumer q;
	Consumer(ProducerConsumer q){
		this.q=q;
		new Thread(this,"Consumer").start();
	}
	public void run(){

		while(true){
			q.get();
		}
	}
}
public class ProdCon{
	public static void main(String args[]){
		ProducerConsumer q=new ProducerConsumer();

		System.out.println("Press Control+C To Exit!");

		new Producer(q);
		new Consumer(q);
	}
}
