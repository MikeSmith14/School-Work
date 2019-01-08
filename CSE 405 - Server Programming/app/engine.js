const fs   = require('fs');
const path = require('path');

const templates = [];

fs.readdir('./views', (err, filenames) => {
  filenames = filenames.filter(filename => filename.endsWith('.html'));
  filenames.forEach((filename) => {
    let pathname = path.join(process.cwd(), 'views', filename);
    templates[pathname] = fs.readFileSync(pathname, 'utf8');
  });
});

module.exports = function(pathname, options, cb) {
  let template = templates[pathname];
  if (template === undefined) cb(Error());
  const params = options.params;
  const keys   = Object.keys(params);
  keys.forEach((key) => {
    template = template.replace('#' + key + '#', params[key]);
  });
  return cb(null, template);
};
