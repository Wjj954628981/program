package GaleShapley;

import java.util.*;

public class GS {
	
	private int n;//匹配对数
	private int[][] ManList,WomanList;//男女生心目中的排行
	private boolean IsManFree[],IsWomanFree[],IsManProposed[][];//男女生是否自由，男生是否表白
	
	//构造函数
	public GS(int n, int[][] mP, int[][] wP) {
		super();
		this.n = n;
		ManList = mP;
		WomanList = wP;
		IsManFree = new boolean[n];
		IsWomanFree = new boolean[n];
		IsManProposed = new boolean[n][n];
		init();
	}

	//初始化男女生状态 
	public void init(){
		for(int i=0;i<n;i++){
			IsManFree[i]=true;
	        IsWomanFree[i]=true;
	        for(int j=0;j<n;j++){
	        	IsManProposed[i][j]=false;
	        }
		}
	}
	
	//判断是否有男生自由 
	public boolean IsOneManFree(){
		for(int i=0;i<n;i++){
	    	if(IsManFree[i]==true)
	    	return true;
	    }
	    return false;
	}
	
	//匹配算法
	public int[] matching(){
		int[] match = new int[n];
		//如果有男生自由 
		while(IsOneManFree()){
			int ManIndex = 0;
			//找到按顺序第一个自由的男生对其进行配对 
	        for(int i=0;i<n;i++){
	        	if(IsManFree[i]==true){
	        		ManIndex=i;break; 
	        	}
	        }
	        int WomanIndex = 0;
	        //找到该男生按顺序第一个未表白的女生
	        for(int i=0;i<n;i++){
	        	int w=ManList[ManIndex][i];
	            if(IsManProposed[ManIndex][w]==false){
	            	WomanIndex=w;break;
	            }
	        }
	        //表白！ 
	        IsManProposed[ManIndex][WomanIndex]=true;
	        //如果该女生自由，则匹配成功，在一起！ 
	        if(IsWomanFree[WomanIndex]){
	        	IsManFree[ManIndex]=false;
	            IsWomanFree[WomanIndex]=false;
	            match[ManIndex]=WomanIndex;
	        }
	        //该女生已经有了匹配，进行判断 
	        else{
	        	//找到与该女生匹配的男生 
	            int indexRival = 0;
	            for(int i=0;i<n;i++){
	            	if(match[i]==WomanIndex){
	            		indexRival=i;break; 
	            	}
	            }
	            //找到该男生和原来男生的地位排名
	            int pM = 0,pRival = 0;
	            for(int i=0;i<n;i++)
	            {
	                if(WomanList[WomanIndex][i]==ManIndex)  pM=i;
	                if(WomanList[WomanIndex][i]==indexRival)  pRival=i;
	            }
	            //如果该男生排名前于原来匹配男生，则重新匹配成功！否则不作改变 
	            if(pM<pRival)
	            {
	                IsManFree[ManIndex]=false;
	                IsManFree[indexRival]=true;
	                IsWomanFree[WomanIndex]=false;
	                match[ManIndex]=WomanIndex;
	            }
	        }
	    }
		return match;
	}
	
	public static void main(String[] args) {
		//进行数据的输入
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();;
		int [][] MP = new int[n][n],WP = new int[n][n];
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		MP[i][j] = cin.nextInt();
        	}
        }
        for(int i=0;i<n;i++){
        	for(int j=0;j<n;j++){
        		WP[i][j] = cin.nextInt();
        	}
        }
		//把排序换成数组序列，需要都减一 
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				MP[i][j]--;
	            WP[i][j]--;
			}
		}
		//实例化对象并进行匹配
		GS gs = new GS(n, MP, WP);
		int[] match = gs.matching();
		for(int i=0;i<n;i++){
			match[i]++;
		}
		//输出匹配
		for(int i=0;i<n;i++){
			System.out.print(match[i]+" ");
		}
	}
}
