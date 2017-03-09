package ProducerConsumer;

import java.util.LinkedList;

public class ProducerConsumer {

	static final int N = 100;
	static LinkedList<Object> product = new LinkedList<Object>();
	
	public void start(){
		new producer().start();
		new consumer().start();
	}

	static class producer extends Thread{
		public void run(){
			while(true){
				synchronized (product) {
					try{
						while(product.size() == N){
							System.out.println("product is full!");
							product.wait();
						}
						Object new_product = new Object();
						product.add(new_product);
						System.out.println("producer makes a product");
						product.notify();
						Thread.sleep((long)(Math.random()*30));
					}catch(InterruptedException e){
						System.out.println("producer is interrupted!");
					}
				}
			}
		}
	}
	
	static class consumer extends Thread{
		public void run(){
			while(true){
				synchronized (product) {
					try{
						while(product.size() == 0){
							System.out.println("product is empty!");
							product.wait();
						}
						product.removeLast();
						System.out.println("consumer gets a product");
						product.notify();
						Thread.sleep((long)(Math.random()*100));
					}catch(InterruptedException e){
						System.out.println("consumer is interrupted!");
					}
				}
			}
		}
	}
	
	public static void main(String[] args) throws Exception{
		ProducerConsumer pc = new ProducerConsumer();
		pc.start();
	}
}
