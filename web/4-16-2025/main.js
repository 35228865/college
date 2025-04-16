d3.csv('https://raw.githubusercontent.com/ryanchung403/dataset/refs/heads/main/harry_potter.csv').then(res =>{
    console.log(res);
    drawGraph(res);
});
//unpack the data
function unpack(rows, key)
{
    return rows.map(function (row) 
    {
        return row[key];
    });
}
function drawGraph(res) 
{
    console.log(res);
    console.log(unpack(res, "release_year"));
    console.log(unpack(res, "revenue"));
    console.log(unpack(res, "budget"));
    let trace1 = {  
        type: "scatter",
        mode: "lines+markers",
        name: "Revenue",
        x: unpack(res, "release_year"),
        y: unpack(res, "revenue")
    };
    let trace2 = {
        type: "scatter",
        mode: "lines+markers",
        name: "Budget",
        x: unpack(res, "release_year"),
        y: unpack(res, "budget")
    };
    /*for (let i = 0; i < set1.length; i++) {
        trace1.x.push(res[i][0]);
        trace1.y.push(set1[i][1]);
    }
    for (let i = 0; i < set2.length; i++) {
        trace2.x.push(set2[i][0]);
        trace2.y.push(set2[i][1]);
    }*/
    let data =[trace1,trace2];
    let layout = {
        margin:{t:50,b:30,l:30,r:20},
        title:{text:"My Graph"},
    };
    Plotly.newPlot("myGraph",data,layout);
}