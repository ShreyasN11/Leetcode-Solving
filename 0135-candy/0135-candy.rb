# @param {Integer[]} ratings
# @return {Integer}
def candy(rating)
    n = rating.length
    res = Array.new(n,1)

    for i in 1...n
        if rating[i] > rating[i-1]
            res[i] = res[i-1] + 1
        end
    end

    for i in (n - 2).downto(0)
        if rating[i] > rating[i+1]
            res[i] = [res[i+1]+1, res[i]].max
        end
    end            

    return res.sum

end