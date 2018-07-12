#bash /bin/bash
npm run build
cp ./dist/index.html ../server/view/index_index.html
rm -r ../server/www/static
cp -r ./dist ../server/www/static
rm ../server/www/static/index.html