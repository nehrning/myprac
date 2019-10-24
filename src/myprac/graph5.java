package myprac;

import java.util.*;

public class graph5 {
	public int solution(int[] arrows) {
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        int answer = 0;
        int x = 0;
        int y = 0;
        int vertex = 0;
        hm.put(String.format("%d%d", x, y), 1);
        for(int i : arrows){
            switch(i){
                case 0:
                    y += 1;
                    break;
                case 1:
                    x += 1;
                    y += 1;
                    break;
                case 2:
                    x += 1;
                    break;
                case 3:
                    x += 1;
                    y -= 1;
                    break;
                case 4:
                    y -= 1;
                    break;
                case 5:
                    x -= 1;
                    y -= 1;
                    break;
                case 6:
                    x -= 1;
                    break;
                case 7:
                    x -= 1;
                    y += 1;
                    break;
            }
            hm.put(String.format("%d%d", x, y), hm.getOrDefault(String.format("%d%d", x, y), 0) + 1);
        }
        Iterator<Integer> it = hm.values().iterator();
        while(it.hasNext()) {
            if(it.next() > 1)
                vertex ++;
        }
        System.out.println(2- vertex + arrows.length);
        answer = 2 - vertex + arrows.length;
        return answer;
    }
}
