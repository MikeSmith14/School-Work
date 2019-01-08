exports.filter = filter;

let sessions = {};

function filter(req, res) {
  let sessionId = extractSessionId(req);
  if (sessionId === null || !sessions[sessionId]) {
    sessionId = createSessionId();
    setSessionCookie(res, sessionId);
    sessions[sessionId] = { };
  }
    req.session = sessions[sessionId];
}

function extractSessionId(req) {
  if (!req.headers.cookie) return null;
  let i = req.headers.cookie.indexOf('sessionId=') + 'sessionId='.length;
  if (i == -1) return null;
  let c = req.headers.cookie.substr(i);
  let j = c.indexOf(';');
  if (j == -1) return c;
  return '' + c.substr(0, i);
}

function createSessionId() {
  sessionId = '' + Math.random();
  return sessionId;
}

function setSessionCookie(res, sessionId) {
  let cookie = 'sessionId=' + sessionId;
  res.setHeader('Set-Cookie', [cookie]);
}
