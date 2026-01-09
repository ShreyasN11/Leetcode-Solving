# @param {String[]} strs
# @return {String}
def longest_common_prefix(strs)
    n = strs.length
    minlen = 200;
    for i in 0...n
        minlen = [minlen, strs[i].length].min
    end
    res = ""
    for i in 0...minlen
        ch = strs[0][i]
        flag = true
        for j in 1...n
            if strs[j][i] != ch
                flag = false
                break
            end
        end
        if flag
            res += ch
        else 
            break
        end    
    end                

    return res
end