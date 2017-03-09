package topological;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class topologic_right {
	public static void main(String[] args) {

		@SuppressWarnings("resource")
		Scanner cin = new Scanner(System.in);
		int point_num = cin.nextInt();
		int edge_num = cin.nextInt();
		int [] edges = new int[2*edge_num];
        for(int i=0;i<2*edge_num;i++){
    		edges[i] = cin.nextInt() - 1;
        }
        
    	int[][] matrix = ChangeToMatrix(point_num, edge_num, edges);
    	int[] indegree = InDegree(point_num, matrix);
    	int[] outdegree = OutDegree(point_num, matrix);
    	
    	List<Integer> list = topologicalsort(matrix, indegree, outdegree, point_num);
    	for(int i=0;i<list.size();i++){
    		if(i<list.size()-1){
    			System.out.print(list.get(i) + ",");
    		}else{
    			System.out.print(list.get(i));
    		}
    	}
	}
	
	//构造邻接矩阵
	public static int[][] ChangeToMatrix(int point_num, int edge_num, int[] edges){
		int [][] matrix = new int[point_num][point_num];
		for(int i=0;i<edge_num;i++){
			int m = edges[2*i];
			int n = edges[2*i+1];
			matrix[m][n] = 1;
		}
		return matrix;
	}

	//计算入度
	public static int[] InDegree(int point_num,int[][] matrix){
		int[] indegree = new int[point_num];
		for(int i=0;i<point_num;i++){
			int sum = 0;
			for(int j=0;j<point_num;j++){
				sum += matrix[j][i];
			}
			indegree[i] = sum;
		}
		return indegree;
	}

	//计算出度
	public static int[] OutDegree(int point_num, int[][] matrix){
		int[] outdegree = new int[point_num];
		for(int i=0;i<point_num;i++){
			int sum = 0;
			for(int j=0;j<point_num;j++){
				sum += matrix[i][j];
			}
			outdegree[i] = sum;
		}
		return outdegree;
	}
	
	//找到入度为0的点
	public static int PointIndegreeZero(int point_num, int[] indegree){
		for(int i=0;i<point_num;i++){
			if(indegree[i]==0){
				return i;
			}
		}
		return -1;
	}
	
	//找到出度为0的点
	public static int PointOutdegreeZero(int point_num, int[] outdegree){
		for(int i=0;i<point_num;i++){
			if(outdegree[i]==0){
				return i;
			}
		}
		return -1;
	}
	
	//进行拓扑排序
	public static List<Integer> topologicalsort(int[][] matrix, int[] indegree, int[] outdegree, int point_num){
		List<Integer> toposort = new ArrayList<Integer>();
		List<Integer> circle = new ArrayList<Integer>();
		
		//如果有点入度为0，则将该点加入拓扑集合，并使该点入度减1，出度为0；与该点有关的点矩阵为0，入度减1
		while(PointIndegreeZero(point_num, indegree)!=-1){
			int m = PointIndegreeZero(point_num, indegree);
			toposort.add(m+1);
			indegree[m]--;
			outdegree[m] = 0;
			
			for(int i=0;i<point_num;i++){
				if(matrix[m][i]==1){
					matrix[m][i] = 0;
					indegree[i]--;
				}
			}
		}
		
		//如果拓扑集合数量小于点的数量，则有环；否则输出拓扑排序
		if(toposort.size()==point_num){
			System.out.println("YES");
			return toposort;
		}else{
			System.out.println("NO");
			//如果有点出度为0，则将该点出度减1；与该点有关的点矩阵为0，出度减1
			while(PointOutdegreeZero(point_num, outdegree)!=-1){
				int m = PointOutdegreeZero(point_num, outdegree);
				outdegree[m]--;
				for(int i=0;i<point_num;i++){
					if(matrix[i][m]==1){
						matrix[i][m] = 0;
						outdegree[i]--;
					}
				}
			}
			//找到出度不为0的点的集合
			List<Integer> circle_points = new ArrayList<Integer>();
			for(int i=0;i<point_num;i++){
				if(outdegree[i]!=-1){
					circle_points.add(i);
				}
			}
			//从集合选出一个环 
			circle.add(circle_points.get(0)+1);
			int temp = -1;
			for(int i=0;i<point_num;i++){
				if(matrix[circle_points.get(0)][i]==1){
					matrix[circle_points.get(0)][i] = 0;
					temp = i;
					break;
				}
			}
			while(temp!=circle_points.get(0)){
				for(int i=0;i<point_num;i++){
					if(matrix[temp][i]==1){
						matrix[temp][i] = 0;
						circle.add(temp+1);
						temp = i;
						break;
					}
				}
			}
			circle.add(circle_points.get(0)+1);
			return circle;
		}
	}
}
