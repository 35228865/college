let trace1 = {
    type: "scatter",
    mode: "lines+markers",
    x: [1, 2, 3, 4, 5],
    y: [1, 2, 4, 8, 16]
};

for (let i = 0; i < set1.length; i++) {
    trace1.x.push(set1[i][0]);
    trace1.y.push(set1[i][1]);
}
let data =[trace1];
let layout = {
    margin:{t:50,b:30,l:30,r:20}
};
Plotly.newPlot("myGraph",data,layout);
