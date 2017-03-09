package topological;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class topological {

	//点和边的数量以及具体值
	private int point_num;
	private int edge_num;
	private int[] points = new int[point_num];
	private int[][] edges= new int[edge_num][2];
	
	//点的入度
	private int[] in_degree = new int[point_num];
	
	//能否进行拓扑排序
	private String YNresult;
	
	//构造函数
	public topological(int point_num, int edge_num, int[][] edges) {
		super();
		this.point_num = point_num;
		this.edge_num = edge_num;
		this.edges = edges;
		for(int i=0;i<point_num;i++){
			points[i] = i;
			in_degree[i] = 0;
		}
	}

	//计算点的入度
	int[] in_degree(){
		for(int i=0;i<edges.length;i++){    
			if(edges[i][0]!=-1){
				in_degree[edges[i][1]]++;
			}
		}
		return in_degree;
	}

	//计算入度为0的点
	int pointsindegreezero(){
		for(int i=0;i<point_num;i++){
			if(in_degree()[i]==0){
				return i;
			}
		}
		return -1;
	}
	
	//进行拓扑排序
	List<Integer> topologic(){

		int output_num = 0;
		int real_point_num = point_num;
		
		//拓扑排序的集合
		List<Integer> toposort = new ArrayList<Integer>();
		//圈的集合
		List<Integer> loop = new ArrayList<Integer>();
				
		while(pointsindegreezero()!=-1){
			
			//把入度为0的点输出
			toposort.add(pointsindegreezero());
			output_num++;
			
			//把该点设为-1并把该点入度设为-1
			in_degree[pointsindegreezero()] = -1;
			for(int i=0;i<real_point_num;i++){
				if(points[i] == pointsindegreezero()){
					points[i] = -1;
				}
			}
			
			//把边中的该点设为-1并更改其他边入度
			for(int i=0;i<this.edge_num;i++){
				if((edges[i][0] == pointsindegreezero())){
					edges[i][0] = -1;
					in_degree[edges[i][1]]--;
				}
			}
		}
		
		//判断能否进行拓扑排序
		if(output_num<real_point_num){
			YNresult = "No";
			return loop;
		}else{
			YNresult = "Yes";
			return toposort;
		}
	}
	
	public static void main(String[] args) {
		//进行数据的输入
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
		topological tp = new topological(point_num, edge_num, edges);
		
		//输出所有点的入度
		int[] in = tp.in_degree();
		for(int i=0;i<point_num;i++){
			System.out.println(in[i]);
		}
//		
//		//输出入度为0的点
//		System.out.println(tp.pointsindegreezero());
		
		//输出能否拓扑排序
		System.out.println(tp.YNresult);

		
//		//输出拓扑排序或者圈
//		List<Integer> result = tp.topologic();
//		for(Integer value : result){  
//            System.out.print(value+" ");  
//        }
	}
}
