package myprac;

import java.util.*;

public class hash4 {
	
	public static void main(String[] args) {
		Solution s = new Solution();
		String[] genres = {"c","p","c","c","p"};
		int[] plays = {800,600,150,800,2500};
		int[] res = s.solution(genres, plays);
		for(int r : res)
			System.out.println(r);
    }
}

class Solution {
	public int[] solution(String[] genres, int[] plays) {
        ArrayList<Integer> answer = new ArrayList<Integer>();
        ArrayList<Data> al = new ArrayList<Data>();
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        for(int i = 0; i < genres.length; i++) {
        	hm.put(genres[i], hm.getOrDefault(genres[i], 0) + plays[i]);
            al.add(new Data(i, genres[i], plays[i]));
        }
        Collections.sort(al);
        
        Iterator<String> it  = hashSort(hm).iterator();
        while(it.hasNext()) {
            String temp = (String)it.next();
            boolean trigger = false;
            for(Data d : al)
            	if(d.genre.equals(temp)) {
            		answer.add(d.index);
            		if(!trigger) 
            			trigger = true;
            		else
            			break;
            	}
        }
        
        int[] res = new int[answer.size()];
        for(int i = 0; i < res.length; i++)
        	res[i] = answer.get(i);
        return res;
    }
	
	public static ArrayList<String> hashSort(final HashMap<String, Integer> hm) {
		ArrayList<String> list = new ArrayList<String>();
		list.addAll(hm.keySet());
		
		Collections.sort(list, new Comparator<Object>() {
			public int compare(Object o1, Object o2) {
				Object v1 = hm.get(o1);
				Object v2 = hm.get(o2);
				return ((Comparable) v2).compareTo(v1);
			}
		});
		return list;
	}
}

class Data implements Comparable<Data>{
    int index;
    String genre;
    int play;
    
    Data(int index, String genre, int play){
        this.index = index;
        this.genre = genre;
        this.play = play;
    }
    public int compareTo(Data d){
        if(play < d.play)
            return 1;
        else if(play > d.play)
            return -1;
        else
            return 0;
    }
}