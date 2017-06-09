const glob = require("glob");
const fs = require("fs");

// write Report 
const writeReport = (source,dir) => {
    const title = source.split("/").slice(-1)[0].replace(".c","");
    const code = fs.readFileSync(source, "utf-8");
    let text;
    try {
        text = fs.readFileSync(`src/${number}/${dir}/text/${title}.txt`, "utf-8");
    } catch (e) {
        text = "";
    }
    const str = `
# ${title}

## ソースコード

\`\`\`c
${code}
\`\`\`

## 出力

\`\`\`
${text}
\`\`\`

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
    kadaireport += writeReport(value,"kadai");
});

test_sources.forEach((value) => {
    testreport += writeReport(value,"test");
});

fs.writeFileSync(`src/${number}/kadai/kadai${date}-16030.txt`);
fs.writeFileSync(`src/${number}/test/test${date}-16030.txt`);