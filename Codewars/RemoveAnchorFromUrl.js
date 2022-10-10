function removeUrlAnchor(url){
  // TODO: complete

  let urlSanitized = '';

  url.includes('#') ? urlSanitized = removeAchorAndRest(url) : urlSanitized = url;

  return urlSanitized;
}

function removeAchorAndRest(url) {

  const indexAnchor = url.indexOf('#');
  return url.slice(0, indexAnchor);
}