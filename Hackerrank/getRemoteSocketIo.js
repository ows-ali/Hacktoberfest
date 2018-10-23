module.exports = {
  getRemoteAddress(client) {
    const { address, port, family } = client.conn.request.connection._getpeername();
    // debug(`Client ${client.id} ([${family}]${address}:${port}) is connected.`);
    return {
      address,
      port,
      family,
      full: `[${family}]${address}:${port}`,
      remote: `${address}:${port}`,
    };
  },
};
