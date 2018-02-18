g_index = 0;
g_table = {
    str = "valstr",
    num = 0,
    tab = {
        str = "valstr_inside",
        num = 0
    }
}

function Sleep(n)
    os.execute("sleep " .. n)
end

function fibo(n)
    if 1 == n or 2 == n then
        return 1
    else
        return fibo(n - 1) + fibo(n - 2)
    end
end

function domain(i, j)

    --    -- call C function.
    --    local tab = gettab()
    --
    --    -- show key and value
    --    for k, v in pairs(tab) do
    --        print("key: ".. k)
    --        print("val: ".. v)
    --    print()
    --    end

    print(j)

    local l_index = 0
    g_index = 0
    while l_index < 1000 * 1000 * 1000 do
        if l_index ~= g_index then
            print("全局变量出错")
        end
        print("l_index "..l_index)
        l_index = l_index + 1
        g_index = g_index + 1
        g_table.tab.num = g_table.tab.num + 1
        if g_table.tab.num ~= l_index then
            print("全局TAB出错")
        end
        print("begin fibo")
        local n = fibo(20)
        print("fibo 20 "..n)
    end
end

function domain2(i, j)

    --    -- call C function.
    --    local tab = gettab()
    --
    --    -- show key and value
    --    for k, v in pairs(tab) do
    --        -- print("key: ".. k)
    --        -- print("val: ".. v)
    --    --print()
    --    end

    --print(j)

    local l_index = 0
    g_index = 0
    while l_index < 1000 * 1000 * 1000 do
        if l_index ~= g_index then
            print("全局变量出错")
        end
        l_index = l_index + 1
        g_index = g_index + 1
        g_table.tab.num = g_table.tab.num + 1
        if g_table.tab.num ~= l_index then
            print("全局TAB出错")
        end
    end
end

--domain2(1, 2)


