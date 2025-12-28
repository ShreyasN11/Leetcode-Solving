# @param {Integer[]} citations
# @return {Integer}
def h_index(citation)
    lo = 0
    hi = citation.length
    res = 0
    while lo<=hi
        mid = (lo+hi)/2
        count = 0
        n = citation.length
        for i in 0...n
            if citation[i] >= mid
                count+=1
            end
        end
        if count >= mid
            res = mid
            lo = mid+1
        else
            hi = mid-1    
        end
    end
    return res                
end