package topological;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class test {

	//点和边的数量以及具体值
	private int point_num;
	private int edge_num;
	private int[] points = new int[point_num];
	private int[][] edges= new int[edge_num][2];
	
	//点的入度
	private int[] in_degree = new int[edge_num];
	
	//构造函数
	public test(int point_num, int edge_num, int[][] edges) {
		super();
		this.point_num = point_num;
		this.edge_num = edge_num;
		this.edges = edges;
	}

	//计算点的入度
	int[] in_degree(){
		for(int i=0;i<edge_num;i++){    
//			if(edges[i][0]!=-1){
				in_degree[i] = edges[i][1];
				//in_degree[edges[i][1]]++;
//			}
		}
		return in_degree;
	}
	
	
	int test(){
		return edges[0][1];
	}
	public static void main(String[] args) {
//		//进行数据的输入
		Scanner cin = new Scanner(System.in);
		int point_num = cin.nextInt();
		int edge_num = cin.nextInt();
		int [][] edges = new int[edge_num][2];
        for(int i=0;i<edge_num;i++){
        	for(int j=0;j<2;j++){
        		edges[i][j] = cin.nextInt() - 1;
        	}
        }
        
        //类实例化
		test tp = new test(point_num, edge_num, edges);
//		for(int i=0;i<edge_num;i++){
//			for(int j=0;j<2;j++){
//				System.out.println(tp.edges[i][j]);
//			}
//		}
		System.out.println(tp.test());
		//输出所有点的入度
//		int[] in = tp.in_degree();
//		for(int i=0;i<edge_num;i++){
//			System.out.println(in[i]);
//		}
	}
}
