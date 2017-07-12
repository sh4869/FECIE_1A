const glob = require("glob");
const fs = require("fs");

// write Report 
const writeReport = (number,source,dir) => {
    const title = source.split("/").slice(-1)[0].replace(".c","");
    const code = fs.readFileSync(source, "utf-8");
    let text;
    try {
        text = fs.readFileSync(`src/${number}/${dir}/text/${title}.txt`, "utf-8");
    } catch (e) {
        text = "";
    }
    const str = `
# ${title}\r\n\r\n
## ソースコード\r\n\r\n
\`\`\`c\r\n
${code}
\`\`\`\r\n
## 出力\r\n\r\n
\`\`\`\r\n
${text}\r\n
\`\`\`\r\n
`;
    return str;
}


const number = Number(process.argv[2]);
const date = process.argv[3];

const kadai_sources = glob.sync(`src/${number}/kadai/*.c`);
const test_sources = glob.sync(`src/${number}/test/*.c`);

let kadaireport = "";
let testreport = "";
kadai_sources.forEach((value) => {
    kadaireport += writeReport(number,value,"kadai");
});

test_sources.forEach((value) => {
    testreport += writeReport(number,value,"test");
});

fs.writeFileSync(`src/${number}/kadai/kadai${date}-16030.txt`,kadaireport);
fs.writeFileSync(`src/${number}/test/test${date}-16030.txt`,testreport);