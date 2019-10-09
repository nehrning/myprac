package myprac;

import java.util.*;

class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        HashMap<String, Integer> hm = new HashMap<String, Integer>();
        for(String str : completion)
        	hm.put(str, hm.getOrDefault(str, 0) + 1);
        for(String str : participant){
            if(hm.get(str) == null || hm.get(str) == 0){
                answer = str;
                break;
            }
            else
                hm.put(str, hm.get(str)-1);
        }

        return answer;
    }
}											