package topological;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class toposort {
	
	private int point_num;
	private int edge_num;
	private int[] edges = new int[2*edge_num];
	private int[][] matrix = new int[point_num][point_num];
	private int[] indegree = new int[point_num];
	private int[] outdegree = new int[point_num];
	private String IsToposort = null;
	
	public toposort(int point_num, int edge_num, int[] edges) {
		super();
		this.point_num = point_num;
		this.edge_num = edge_num;
		this.edges = edges;
		ChangeToMatrix();
		InDegree();
		OutDegree();
	}

	//构造邻接矩阵
	void ChangeToMatrix(){
		for(int i=0;i<edge_num;i++){
			int m = edges[2*i];
			int n = edges[2*i+1];
			matrix[m][n] = 1;
		}
	}

	//计算入度
	void InDegree(){
		for(int i=0;i<point_num;i++){
			int sum = 0;
			for(int j=0;j<point_num;j++){
				sum += matrix[j][i];
			}
			indegree[i] = sum;
		}
	}

	//计算出度
	void OutDegree(){
		for(int i=0;i<point_num;i++){
			int sum = 0;
			for(int j=0;j<point_num;j++){
				sum += matrix[i][j];
			}
			outdegree[i] = sum;
		}
	}
	
	//找到入度为0的点
	int PointIndegreeZero(){
		for(int i=0;i<point_num;i++){
			if(indegree[i]==0){
				return i;
			}
		}
		return -1;
	}
	
	//找到出度为0的点
	int PointOutdegreeZero(){
		for(int i=0;i<point_num;i++){
			if(outdegree[i]==0){
				return i;
			}
		}
		return -1;
	}
	//进行拓扑排序
	List<Integer> topologicalsort(){
		List<Integer> toposort = new ArrayList<Integer>();
		List<Integer> circle = new ArrayList<Integer>();
		
		//如果有点入度为0，则将该点加入拓扑集合，并使该点入度减1，出度为0；与该点有关的点矩阵为0，入度减1
		while(PointIndegreeZero()!=-1){
			toposort.add(PointIndegreeZero());
			indegree[PointIndegreeZero()]--;
			outdegree[PointIndegreeZero()] = 0;
			for(int i=0;i<point_num;i++){
				if(matrix[PointIndegreeZero()][i]==1){
					matrix[PointIndegreeZero()][i] = 0;
					indegree[i]--;
				}
			}
		}
		
		//如果拓扑集合数量小于点的数量，则有环；否则输出拓扑排序
		if(toposort.size()==point_num){
			IsToposort = "Yes";
			return toposort;
		}else{
			IsToposort = "No";
			//如果有点出度为0，则将该点出度减1；与该点有关的点矩阵为0，出度减1
			while(PointOutdegreeZero()!=-1){
				outdegree[PointOutdegreeZero()]--;
				for(int i=0;i<point_num;i++){
					if(matrix[i][PointOutdegreeZero()]==1){
						matrix[i][PointOutdegreeZero()] = 0;
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
			circle.add(circle_points.get(0));
			int temp = -1;
			for(int i=0;i<point_num;i++){
				if(matrix[circle_points.get(0)][i]==1){
					temp = i;
					break;
				}
			}
			while(temp!=circle_points.get(0)){
				for(int i=0;i<point_num;i++){
					if(matrix[temp][i]==1){
						circle.add(temp);
						temp = i;
					}
				}
			}
			circle.add(circle_points.get(0));
			return circle;
		}
	}
	
	public static void main(String[] args) {

		Scanner cin = new Scanner(System.in);
		int point_num = cin.nextInt();
		int edge_num = cin.nextInt();
		int [] edges = new int[2*edge_num];
        for(int i=0;i<2*edge_num;i++){
    		edges[i] = cin.nextInt() - 1;
        }
        
        toposort ts = new toposort(point_num, edge_num, edges);
        System.out.println(ts.IsToposort);
        System.out.println(ts.topologicalsort());
	}

}
